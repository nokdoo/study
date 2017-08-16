#!/usr/bin/perl -w
use strict;

$_ = "yabba dabba doo";
if(/y(....) d\1/){
	print "passed\n";
}
