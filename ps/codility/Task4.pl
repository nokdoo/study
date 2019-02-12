#!/usr/bin/env perl

use strict;
use warnings;

sub solution {
    my ($A, $B)=@_; my @A=@$A; my @B=@$B;
    # write your code in Perl 5.18
	my @C;

	for my $i (0..$#A)
	{
		$C[$i] = $A[$i] + $B[$i]/1000000;
	}

	my $count = 0;

	for my $i ( 0..$#C-1 )
	{
		for my $j ( $i+1..$#C )
		{
			$count++ if $C[$i] * $C[$j] >= $C[$i] + $C[$j];
		}
	}
	$count;
}

print solution( [0,1,2,2,3,5], [500000, 500000, 0, 0, 0, 20000] );
