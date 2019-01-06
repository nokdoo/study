#!/usr/bin/env perl

use strict;
use warnings;

sub shellsort{
	my $array = shift;
	print "@$array\n";

	my $i;
	my $j;
	my $shell;

	for($shell = 1; $shell < @$array; $shell = 2 * $shell+1)
	{}

	do{
		$shell = int( ($shell - 1) /2);
		for($i = $shell; $i<@$array; $i++)
		{
			for($j = $i-$shell;
				$j>=0 && $array->[$j] gt $array->[$j + $shell];
				$j -= $shell)
			{
				@$array[$j, $j+$shell] = @$array[$j + $shell, $j];
				print "@$array\n";
			}
		}
	} while $shell > 1;
}
1;
