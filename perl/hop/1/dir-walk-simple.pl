#!/usr/bin/env perl

sub dir_walk{
	my ($top, $code) = @_;
	my $DIR;

	$code->($top);

	if(-d $top){
		my $file;
		unless (opendir $DIR, $top){
			warn "Couldn't open directory $top: $!; skipping.\n";
			return;
		}
		while ($file = readdir $DIR){
			next if $file eq '.' || $file eq '..';
			dir_walk("$top/$file", $code);
		}
	}
}

sub print_dir{
	print $_[0], "\n";
}

dir_walk('.', \&print_dir);
