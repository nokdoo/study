#!/usr/local/bin/perl
-w;
use strict;

use Module::CoreList;

my %modules = %{ $Module::CoreList::version{5.008}};

foreach (%modules){
	print $_."\n";
}

