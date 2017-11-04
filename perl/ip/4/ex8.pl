#!perl

use strict;

use Carp qw(croak);

use constant HASH => ref {};

my @array = qw(test1 test2 test3);
my %hash = (name => 'test1');

my $ref = \%hash;

print eval {keys %$ref; 1};
