#!/usr/bin/perl

use strict;
use warnings;

# Complete the minimumSwaps function below.
sub minimumSwaps {
	my ($arr) = @_;
	my $count = 0;
	my $size = scalar @$arr;

	unshift @$arr, 0;

	for (my $i = 1; $i <= $size; $i++){
		next if $$arr[$i] == $i;
		my $tmp = $$arr[$i];
		$$arr[$i] = $$arr[$tmp];
		$$arr[$tmp] = $tmp;
		$count++;
		$i--;
	}
	print $count;
}

open(my $fptr, '>', $ENV{'OUTPUT_PATH'});

my $n = <>;
$n =~ s/\s+$//;

my $arr = <>;
$arr =~ s/\s+$//;
my @arr = split /\s+/, $arr;

my $res = minimumSwaps \@arr;

print $fptr "$res\n";

close $fptr;
