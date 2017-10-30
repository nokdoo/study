#!/usr/local/bin/perl

use strict;

my @input_numbers = (1,2,4,8,16,32,64);

my @odd_digit_sum = grep digit_sum_is_odd($_), @input_numbers;

print $_."\n", for @odd_digit_sum;

sub digit_sum_is_odd{
	my $input = shift;
	print $input."\n";
	my @digits = split //, $input;
	my $sum;
	$sum += $_ for @digits;
	return 1;
}

sub digit_sum_is_odd2{
	1;
}
