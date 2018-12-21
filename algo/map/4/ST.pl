#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;

my @input = ( "z.txt", "a.txt" , "b.txt" , "c.txt" ) ;
my @output = 
	map { print "$_\n"; /^\w* (.*)/	}
		sort
			map	
			{ 
				my $d = lc;
				$d =~ s/\.txt//g;
				"$d $_"
			}
		@input;

print "@output";
