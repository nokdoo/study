#!/usr/bin/perl -w
use strict;

$_ = "한글이에요";

print "가\x11*16*16+\xAB";

if(/(\x11AB)/){
	print "passed\n";
}
