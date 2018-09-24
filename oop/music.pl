#!/usr/bin/env perl

use strict;
use warnings;

use lib "/home/nokdoo/study/oop/lib/";
use CD::Music;

my $music = CD::Music->new(_name=>'kiiii');
print CD::Music->name();
