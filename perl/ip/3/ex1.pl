#!/usr/local/bin/perl
use strict;

my @castaways = qw(Gilligan Skipper Ginker Professor Mary Ann);

print "$_\n" for @castaways;
print "\n";


my @lunch_choices = grep /s/, @castaways;


