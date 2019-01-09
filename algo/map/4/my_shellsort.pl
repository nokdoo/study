#!/usr/bin/env perl

use strict;
use warnings;

sub shellsort
{
	my $array = shift;
	my ($i, $j);
	my $gap;

	for($gap = 1; $gap<@$array; $gap = 2 * $gap + 1)
	{
	}

	while($gap)
	{
		$gap = int( ($gap - 1) / 2);
		for($i = $gap; $i<@$array; $i++)
		{
			for($j = $i-$gap; $j>=0 && $array->[$j] gt $array->[$j+$gap]; $j-= $gap)
			{
				@$array[$j, $j+$gap] = @$array[$j+$gap, $j];
			}
		}
	}

}
1;
