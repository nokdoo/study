#!perl

use strict;

my @array = qw(test1 test2);

sub test_sub{
	my $ref = shift;


	print @{$ref};
}

test_sub(\@array);
