#!perl
-w;
use strict;

eval{ 10/0};

print $@;
