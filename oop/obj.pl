#!/usr/bin/env perl

use strict;
use warnings;

use lib "/home/nokdoo/study/oop/lib/";
use TEST::ArrayBase;

my $music = TEST::ArrayBase->new();
print $music->get_count(). "\n";
TEST::ArrayBase->new();
TEST::ArrayBase->new();

print $music->get_count(). "\n";
print TEST::ArrayBase::$_count;

