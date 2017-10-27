#!/usr/local/bin/perl
-w;
use strict;

use Module::CoreList;

print $Module::CoreList::version{5.01400}{CPAN};
