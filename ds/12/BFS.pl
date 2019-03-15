#!/usr/bin/env perl

use strict;
use warnings;

sub BreadthFirstSearch {
	my ($G, $v) = @_;
	my @Q;
	
	push @Q, $v;
	$G->{$v}->[$#{ $G->{$v} } ] = 1;

	while ( @Q ) {
		my $w = shift @Q;
		print "$w ";
		my $arr = $G->{$w};
		my $lastidx_of_w = $#$arr;

		for ( 0..$lastidx_of_w-1 ) {
			my $next_w = $arr->[$_];
			my $next_arr = $G->{$next_w};
			my $lastidx_of_next_w = $#$next_arr;
			if ( $next_arr->[$lastidx_of_next_w] == 0 ) {
				push @Q, $next_w;
				$next_arr->[$lastidx_of_next_w] = 1;
			}
		}
	}
	
	print "\n";
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

BreadthFirstSearch( $G, 'A');



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
