#!/usr/bin/env perl

use strict;
use warnings;

my @arr;

my $n = <STDIN>;

while(<STDIN>){
	my ($start, $height, $end) = split;
					
	push @arr, {
					start => $start,
					height => $height,
					end => $end
			   };
}

my @arr1 = sort { $a->{start} <=> $b->{start} } @arr;
my @arr2 = sort { $a->{end} <=> $b->{end} } @arr;
my @answer;
my %heap;


my $i = 0;
my $j = 0;
my $max_height = 0;

sub maxofHeap{
	my @arr = @_;
	my $max = 0;
	foreach (@arr){
		$max = ($max >= $_) ? $max : $_;
	}
	$max;
}

while($i < $n || $j < $n){
	my ($start, $end) = ($arr1[$i], $arr2[$j]);
	if($i < $n && $start->{start} <= $end->{end}){
		$heap{$start->{end}} = $start->{height}+0;
		$max_height = maxofHeap (values %heap);
		if((scalar @answer) == 0 || $answer[-1] != $max_height){
			push @answer, ($start->{start}, $max_height);
		}
		$i++;
	}else{
		delete $heap{$end->{end}};
		$max_height = maxofHeap (values %heap);
		if($answer[-1] != $max_height){
		push @answer, ($end->{end}, $max_height);
		}
		$j++;
	}
}

print "@answer";

