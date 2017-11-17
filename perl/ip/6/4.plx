#!/usr/bin/perl

-w;

use strict;

use Data::Dumper;

my @data1;
my @data2;

my $str;

while(<>){
	$str = $str.$_;
}

my $data_structure = eval $str;

print ;
