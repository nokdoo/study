#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;

sub max
{
	my ($a, $b) = @_;
	return ($a > $b) ? $a : $b;
}

sub min
{
	my ($a, $b) = @_;
	return ($a < $b) ? $a : $b;
}

sub deep
{
	my ($array, $P, $Q, $R) = @_;
	my $ret =  min ( $array->[$P] - $array->[$Q], $array->[$R] - $array->[$Q] );
	print "$P, $Q, $R ====== $ret\n";

	return $ret;
}

sub solution {
    my (@A)=@_;
    # write your code in Perl 5.18
	my $lastindex = $#A;

	my $deepest = 0;

	for my $i ( 0..$lastindex-2 )
	{
		next if $A[$i] <= $A[$i+1];
		my $P = $i;
		my $Q = $i+1;
		my $R = $Q+1;
		#while ( $R < $lastindex && $A[$R] <= $A[$R+1] )
		#{
	#		$R++;
	#	}

		$deepest = max ( $deepest, deep ( \@A, $P, $Q, $R ) );
	}
	return -1 if $deepest == 0;
	return $deepest;
}

print solution ( ( 0, 1, 3, -2, 0, 1, 0, -3, 2, 3) );
