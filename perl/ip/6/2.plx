#!/usr/bin/perl

use strict;
-w;

use Data::Dumper;

my %total_bytes;
while(<>){
	my ($source, $destination, $bytes) = split;
	$total_bytes{$source}{$destination} += $bytes;
}

print "total_bytes : ".Dumper(\%total_bytes);
