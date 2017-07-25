#!/usr/bin/perl -w
use strict;

while(defined(my $line = <STDIN>)){
	print "I saw $line";
}
while(<STDIN>){
	print "I saw $_";
}
foreach(<STDIN>){
	print "I saw $_";
}
