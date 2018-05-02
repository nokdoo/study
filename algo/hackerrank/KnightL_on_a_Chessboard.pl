#!/usr/bin/env perl

use strict;
use warnings;
use Cwd;
use Data::Dumper;

#
# Complete the knightlOnAChessboard function below.
#
sub knightlOnAChessboard {
    #
    # Write your code here.
    #
	
	my $n = $_;
	my @arr;

	for(my $i=0; $i<$n-1; $i++){
		@arr[$i] = ${\(1 ... $n-1)};
	}

	print Dumper(@arr);

	

}

open(my $fptr, '>', getcwd()."/output.txt");

my $n = <>;
$n =~ s/\s+$//;

my @result = knightlOnAChessboard $n;

print $fptr join "\n", map{ join " ", @{$_} } @result;
print $fptr "\n";

close $fptr;
