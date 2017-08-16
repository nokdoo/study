#!/usr/bin/perl -w
use strict;

$_ = "한글이에요";

if(/[ㄷ]/){
	print "passed\n";
}
