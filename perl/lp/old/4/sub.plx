#!/usr/bin/perl

$fred = 3;
$barney = 4;
$will = &subtest;
print $will;

sub subtest{
	printf "hey\n";
	$fred + $barney;
}
