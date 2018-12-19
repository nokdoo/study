#!/usr/bin/env perl

use strict;
use warnings;

sub max{
	my ($a, $b) = @_;
	return ($a gt $b) ? $a : $b;
}

# Complete the maxXor function below.
sub maxXor {
    # solve here
	my ($arr_ref, $queries_ref) = @_;
	#my $arr_len = @$arr_ref;
	#my $queries_len = @$queries_ref;
	
	my @result;
	
	for my $i (@$queries_ref)
	{
		my $max = 0;
		for my $j (@$arr_ref)
		{
			my $result = ($i+0) ^ ($j+0);
			$max = max($max, $result);
		}
		push @result, $max;
	}
	return @result;
}

open(my $fptr, '>', $ENV{'OUTPUT_PATH'});

my $n = <>;
$n =~ s/\s+$//;

my $arr = <>;
$arr =~ s/\s+$//;
my @arr = split /\s+/, $arr;

my $m = <>;
$m =~ s/\s+$//;

my @queries = ();

for (1..$m) {
    my $queries_item = <>;
    $queries_item =~ s/\s+$//;
    push @queries, $queries_item;
}

my @result = maxXor \@arr, \@queries;

print "@result";
print $fptr join "\n", @result;
print $fptr "\n";

close $fptr;

