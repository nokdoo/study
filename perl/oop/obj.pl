#!/usr/bin/env perl

use strict;
use warnings;

use lib "/home/nokdoo/study/perl/oop/lib/";
use TEST::ArrayBase;

print @{main::ISA};

my $music = TEST::ArrayBase->new();
print $music->get_count(). "\n";
TEST::ArrayBase->new();
TEST::ArrayBase->new();

print $music->get_count(). "\n";
print TEST::ArrayBase::$_count;

