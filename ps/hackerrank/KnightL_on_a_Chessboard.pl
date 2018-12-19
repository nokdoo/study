#!/usr/bin/perl

use strict;
use warnings;

#
# Complete the knightlOnAChessboard function below.
#
sub knightlOnAChessboard {
    #
    # Write your code here.
    #
	#
	
}    

my $n = <>;
$n =~ s/\s+$//;

my @result = knightlOnAChessboard $n;

print join "\n", map{ join " ", @{$_} } @result;
print "\n";

