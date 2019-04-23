#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;

package Graph;

sub new {
    my $class = shift;
    bless {}, $class;
}

sub add {
    my ($self, $vertex) = @_;
    push @{$self->{ $vertex->[0] }}, [ @{$vertex}[1..2] ];
}

1;

package Vertex;

sub new {
    my ($class, @self) = @_;
    bless \@self, $class;
}

1;

package main;

my $G = Graph->new;

while (<DATA>) {
    my @line = split ' ', $_;
    my $v = Vertex->new(@line);
    $G->add($v);
}

my %U;
foreach ( keys %$G ) {
    $U{$_} = 999;
}
print Dumper %U;


__DATA__
5 2 4
5 4 2
4 2 1
2 1 3
1 4 3
4 3 1
3 4 2
1 3 6
