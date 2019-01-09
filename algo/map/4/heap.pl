#!/usr/bin/env perl

use strict;
use warnings;

sub heapup
{
	my ($array, $index) = @_;
	my $value = $array->[$index];

	while ($index)
	{
		my $parent = int( ($index-1)/2 );
		my $pv = $array->[$parent];
		last if $pv lt $value;
		$array->[$index] = $pv;
		$index = $parent;
	}
	$array->[$index] = $value;
}

sub heapdown
{
	my ($array, $index, $last) = @_;

	return if $last <= 0;

	my $iv = $array->[$index];

	while($index < $last)
	{
		my $child = 2 * $index + 1;
		last if $child > $last;
		my $cv = $array->[$child];
		if($child < $last)
		{
			my $cv2 = $array->[$child+1];
			if($cv2 lt $cv)
			{
				$cv = $cv2;
				++$child;
			}
		}
		last if $iv le $cv;
		$array->[$index] = $cv;
		$index = $child;
	}
	$array->[$index] = $iv;	
}

sub heapify_array_up
{
	my $array = shift;
	my $i;

	for ( $i = 1; $i <$#$array; ++$i)
	{
		heapup( $array, $i );
	}
}

sub heapify_array_down
{
	my $array = shift;
	my $last = $#$array;
	my $i;

	for ( $i = int( ($last-1)/2); $i >= 0; --$i)
	{
		heapdown($array, $i, $last);
	}
}

1;
