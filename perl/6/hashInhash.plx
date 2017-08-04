#!/usr/bin/perl -w
use strict;

my %foo = ("key" => "val");
my %in = ("kk" => "vv");
print $foo{"key"}."\n";
$foo{"in"} .= $in;
print $foo{"in"}."\n";
