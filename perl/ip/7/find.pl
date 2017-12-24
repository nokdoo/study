#!perl
-w;
use strict;

use File::Find;

my $total_size = 0;
find(sub {$total_size += -s if -f}, '.');
print $total_size, "\n";
