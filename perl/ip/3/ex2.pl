#!/usr/local/bin/perl

use strict;

my @input_numbers = (1,2,4,8,16,32,64);
my @bigger_than_10 = grep $_ > 10, @input_numbers;

print @bigger_than_10;
