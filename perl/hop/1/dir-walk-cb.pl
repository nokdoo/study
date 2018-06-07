#!/usr/bin/env perl

sub dir_walk{
	my ($top, $filefunc, $dirfunc) = @_;
	my $DIR;

	if(-d $top){
		my $file;
		unless (opendir $DIR, $top){
			warn "Couldn't open directory $top: $!; skipping.\n";
			return;
		}

		my @results;
		while ($file = readdir $DIR){
			next if $file eq '.' || $file eq '..';
			push @results, dir_walk("$top/$file", $filefunc, $dirfunc);
		}
		return $dirfunc->($top, @results);
	}else{
		return $filefunc->($top);
	}
}

sub file_size{ -s $_[0] }

sub dir_size{
	my $dir = shift;
	my $total = -s $dir;
	my $n;
	for $n (@_) {$total += $n}
	printf "%6d %s\n", $total, $dir;
	return $total;
}

dir_walk('.', \&file_size, \&dir_size);
