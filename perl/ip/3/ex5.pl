#!perl
use strict;

my @input_numbers = (1,2,4,8,16,32,64);
my @result = map $_ + 100, @input_numbers;

my @result2 = map { $_, $_ } @input_numbers;

my %hash = map { $_, 3 * $_ } @input_numbers;

print $_."\n" for @result2;

