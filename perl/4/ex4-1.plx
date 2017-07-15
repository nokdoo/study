#!/usr/bin/perl -w
use strict;

my @tete = 1 .. 100000000;
sub total{
	my($num) = shift @_;
	foreach(@_){
		$num += $_;
	}
	$num;
}
my $totalt = &total(@tete);
print $totalt."\n";
