#!perl
-w;
use strict;

use File::List;

my $search = new File::List("~/study");
$search->show_empty_dirs();
