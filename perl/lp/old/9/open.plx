#!/usr/bin/perl
-w;
use strict;

open TMP, 'file';
open MK, '>replaced';
$^I = '.bak';
while(<TMP>){
	s/file\\n/replaced/;
	print MK ;
}
close TMP;
close FILE;
