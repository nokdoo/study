#!/usr/bin/env perl

use strict;
use warnings;

use lib "lib/";
use CD::Music;

my $music = CD::Music->new(_name=>'kiiii');
$music->inc_count();
my $music1 = CD::Music->new(_name=>'kiiii');

print $music1->count();
