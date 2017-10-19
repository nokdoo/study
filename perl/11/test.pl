#!/usr/bin/perl
-w;
use strict;

my $name = "/usr/local/bin/perl/haha";

(my $basename = $name) =~ s#.*/##;

print $basename;
