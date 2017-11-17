#!/usr/bin/perl -w
use strict;

my %people = ("fred", "flintstone", "barney", "rubble", "wilma", "flintstone");

print "insert name\n";

chomp(my $name = <STDIN>);

if($people{$name}){
	print $name." is existing : ".$people{$name}."\n";	
}
