#!/usr/local/bin/perl
-w;
use strict;

my %name = qw{ 
		fred flintstone Wilma Flintstone Barney Rubble
			betty rubble Bamm-Bamm Rubble PEBBLES FLINTSTONE
};

foreach(sort {$name{$a} cmp $name{$b} or $a cmp $b} %name){
	print $_."\n";
}

