#!/usr/bin/perl

-w;

use strict;

use Data::Dumper;

my @data1 = qw( one won );

my @data2 = qw(two too to);
push @data2, \@data1;
push @data1, \@data2;

my $string = Dumper(\@data1, \@data2);


print Data::Dumper->Dump( [\@data1, \@data2], [ qw(*data1 *data2) ] );
