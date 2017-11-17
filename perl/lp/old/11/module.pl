#!/usr/bin/perl
-w;
use strict;

use File::Basename;

my $name = "/usr/local/bin/perl";
my $basename = basename $name;
print $basename."\n";

$basename = File::Basename::dirname $name;

print $basename."\n";

