#!/usr/bin/env perl

use strict;
use warnings;

use Data::Dumper;

sub min{
    my $arr_ref = shift;
    my $min;
    for(@$arr_ref){
        $min = $_ if !$min || $_ < $min;
    }
    $min;
}

sub rotateSquare{
    my $from_square = shift;
    my @des_square = ();
    for my $i (0..2){
        my @tmp_square = ();
        for my $j (reverse 0..2){
            push @tmp_square, $from_square->[$j][$i];
        }
        push @des_square, \@tmp_square;
    }
    \@des_square;
}

sub symmetrization{
    my $from_square = shift;
    my @des_square = reverse @$from_square;
    \@des_square;
}

sub calculateSum{
    my ($magicsquare, $square) = @_;
    my $sum = 0;
    for my $i (0..2){
        for my $j (0..2){
            $sum += abs($magicsquare->[$i][$j] - $square->[$i][$j]);
        }
    }
    $sum;
}

sub formingMagicSquare{
    my @magicsquare = ([4,9,2], [3,5,7], [8,1,6]);
    my $square = $_[0];
    my $sum;
    my @results = ();
    for(1..4){
        $square = symmetrization $square;
        $sum = calculateSum \@magicsquare, $square;
        push @results, $sum;
        $square = symmetrization $square;
        $square = rotateSquare $square;
        $sum = calculateSum \@magicsquare, $square;
        push @results, $sum;
    }
    min \@results;
}

open(my $fptr, '>', $ENV{'OUTPUT_PATH'});

my @s = ();

for (1..3) {
    my $s_item = <>;
	$s_item =~ s/\s+$//;
    my @s_item = split /\s+/, $s_item;

    push @s, \@s_item;
}

my $result = formingMagicSquare \@s;
print $result;
print $fptr "$result\n";

close $fptr;
