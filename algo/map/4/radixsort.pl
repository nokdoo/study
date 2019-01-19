#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;

sub radixsort
{
	my $array = shift;
	my $from = $array;
	my $to;

	for (my $i = (length $array->[0])-1; $i>=0; $i--)
	{
		$to = [];
		foreach my $card (@$from)
		{
			push @{ $to->[ ord( substr $card, $i ) ] }, $card;
		}

		print Dumper($to);

		$from = [ map { @{ $_ || [] } } @$to ];
		print Dumper($from);
	}

	@$array = @$from;
}
1;
