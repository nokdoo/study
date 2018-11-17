#!/usr/bin/env perl

use strict;
use warnings;

my $t = <>;

while($t>0){
	my ($n, $k) = split ' ', <>;
	my $target = <>;
	print $n." ", $k." ", $target, "\n";
}
