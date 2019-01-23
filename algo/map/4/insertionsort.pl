#!/usr/bin/env perl

use strict;
use warnings;

sub insertionsort
{
	my ($array) = @_;
	my $n = @$array;
	
	for( my $i = 0; $i < $n-1; $i++)
	{
		my $j;
		my $min = $i;
		for ($j = $i; $j < $n; $j++)
		{
			if ( $array->[$min] > $array->[$j] )
			{
				$min = $j;
			}
		}

		@$array[$min, $i] = @$array[$i, $min] if $min != $i;
	}
}

1;
