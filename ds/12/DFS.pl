#!/usr/bin/env perl

use strict;
use warnings;

sub DepthFirstSearch {
	my ( $G, $v ) = @_;
	my $w = $G->{$v};
	
	if ( $w->[$#$w] == 1 ) { return; }
	
	print "$v ";
	$w->[$#$w] = 1;
	for ( 0.. $#$w-1 ) {
		DepthFirstSearch( $G, $w->[$_] );
	}
}

my $G;

while ( <DATA> ) {
	my @line = split ' ', $_;
	my $vertex = $line[0];
	$G->{$vertex} = [];
	for ( my $i=1; $i<= $#line; $i++ ) {
		push @{ $G->{$vertex} }, $line[$i];
	}
	push @{ $G->{$vertex} }, 0;
}

DepthFirstSearch( $G, 'A' );



__DATA__
A B S
B A
C D E F S
D C
E C H
F C G
G S H
H E G
S A C G
