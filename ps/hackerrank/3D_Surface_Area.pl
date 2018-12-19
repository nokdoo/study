#!/usr/bin/env perl

use strict;
use warnings;

use Data::Dumper;

# Complete the surfaceArea function below.
sub surfaceArea {
    
    my ($A, $H, $W) = @_;
    my $count = 0;
    for my $i (0..$H-1){
        my $row = $A->[$i];
        my $prevalue = 0;
        for my $j (0..$W-1){
            my $currentvalue = $A->[$i][$j];
            my $gap = $currentvalue - $prevalue;
            $count += ($gap > 0) ? $gap : 0;
            $count += 2 if $currentvalue != 0;
            $prevalue = $currentvalue;
        }
        $prevalue = 0;
        for my $j (reverse 0..$W-1){
            my $currentvalue = $A->[$i][$j];
            my $gap = $currentvalue - $prevalue;
            $count += ($gap > 0) ? $gap : 0;
            $prevalue = $currentvalue;
        }
    }
    
    for my $j (0..$W-1){
        my $prevalue = 0;
        for my $i (0..$H-1){
            my $currentvalue = $A->[$i][$j];
            my $gap = $currentvalue - $prevalue;
            $count += ($gap > 0) ? $gap : 0;
            $prevalue = $currentvalue;
        }
        $prevalue = 0;
        for my $i (reverse 0..$H-1){
            my $currentvalue = $A->[$i][$j];
            my $gap = $currentvalue - $prevalue;
            $count += ($gap > 0) ? $gap : 0;
            $prevalue = $currentvalue;
        }
    }
    $count;
}

open(my $fptr, '>', $ENV{'OUTPUT_PATH'});

my $HW = <>;
$HW =~ s/\s+$//;
my @HW = split /\s+/, $HW;

my $H = $HW[0];
$H =~ s/\s+$//;

my $W = $HW[1];
$W =~ s/\s+$//;

my @A = ();

for (1..$H) {
    my $A_item = <>;
    $A_item =~ s/\s+$//;
    my @A_item = split /\s+/, $A_item;

    push @A, \@A_item;
}

my $result = surfaceArea \@A, $H, $W;

print $fptr "$result\n";

close $fptr;
