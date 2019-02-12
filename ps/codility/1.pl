#!/usr/bin/env perl

use strict;
use warnings;

sub solution
{
	my (@A) = @_;
	my @table;
	foreach ( @A )
	{
		next if $_ < 1;
		$table[$_]++;
	}

	my $i = 1;

	my $length = @table;
	foreach ( ; $i<$length; $i++ )
	{
		return $i if !defined $table[$i];
	}
	return $i;

}
my $answer = solution( (1,3,6,4,1,2) );

print "$answer\n";
