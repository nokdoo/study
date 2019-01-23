#!/usr/bin/env perl

use strict;
use warnings;

use constant BUCKETSIZE => 5;

sub bucketsort
{
	my ($array, $min, $max) = @_;
	my $N = @$array or return;

	my $range = $max - $min;
	my $N_BUCKET = $N / BUCKETSIZE;
	my @bucket;

	for ( my $i = 0; $i < $N_BUCKET; $i++)
	{
		$bucket[ $i ] = [ ];
	}

	for ( my $i = 0; $i < $N; $i++)
	{
		my $bucket = $N_BUCKET * (($array->[ $i ] - $min)/$range);
		push @{ $bucket[ $bucket ] }, $array->[ $i ];
	}

	for ( my $i = 0; $i < $N_BUCKET; $i++)
	{
		require './insertionsort.pl';
		insertionsort( $bucket[ $i ] );
	}

	@{ $array } = map { @{ $_ } } @bucket;
}

1;
