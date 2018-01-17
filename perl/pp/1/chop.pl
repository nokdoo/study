#!perl

-w;

use strict;

my $str = "te\nst\n\n";

printf chomp $str;

print $str;
