#!/usr/bin/perl -w
use strict;

my (@words, %hash, $word);

chomp(@words = <STDIN>);

foreach $word(@words){
	$hash{$word} += 1;
}

foreach $word(keys %hash){
	printf "$word, $hash{$word}\n";
}
