#!/usr/bin/env perl

use strict;
use warnings;
srand(time + $$ + ($$ <<15));

use Benchmark;

my @array = reverse 'aaa'..'cac';

for (@array)
{
	if (rand() < 0.5)
	{
		$_ = ucfirst;
	}
	if (rand() < 0.25)
	{
		substr($_, rand(length), 0) = '_';
	}
	if (rand() < 0.333)
	{
		$_ .= $_;
	}
	if (rand() < 0.333)
	{
		$_ .= reverse $_;
	}
	if (rand() < 1/length)
	{
		substr($_, rand(length), rand(length)) = '';
	}
}

timethese(10, {
	'ST' =>
	'@sorted = map { $_->[0] }
				sort { $a->[1] cmp $b->[1] }
					map
					{
						my $d = lc;
						$d =~ s/[\W_]+//g;
						[ $_, $d]
					}
					@array',
	'nonST' =>
	'@sorted = sort
				{
					my ($da, $db) = ( lc($a), lc($b) );
					$da =~ s/[\W_]+//g;
					$db =~ s/[\W_]+//g;
					$da cmp $db;
				}
				@array'
});
