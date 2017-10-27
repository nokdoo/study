#!/usr/bin/perl -w
use strict;

$_ = "A한글이에요";

print \0xec;

if(/\0x88/){
	print "passed\n";
}
