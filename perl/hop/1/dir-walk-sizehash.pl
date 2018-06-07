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

sub file{
	my $file = shift;
	[short($file), -s $file];
}

sub short{
	my $path = shift;
	$path =~ s{.*/}{};
	$path;
}

sub dir{
	my ($dir, @subdirs) = @_;
	my %new_hash;
	for(@subdirs){
		my ($subdir_name, $subdir_structure) = $@_;
		$new_hash{$subdir_name} = $subdir_structure;
	}
	return [short($dir), \%new_hash];
}

sub dir_size{
	my $dir = shift;
	my $total = -s $dir;
	my $n;
	for $n (@_) {$total += $n}
	printf "%6d %s\n", $total, $dir;
	return $total;
}

dir_walk('.', \&file_size, \&dir_size);
