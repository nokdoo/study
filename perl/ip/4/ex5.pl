#!perl

use strict;

my @test = qw(test1 test2);
my @test_list = ('abcdd' => \@test);

print $test_list[0];

