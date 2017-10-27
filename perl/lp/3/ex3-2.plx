#!/usr/bin/perl -w
@words = qw( fred betty barney dino wilma pebbles bamm-bamm );
chomp(@nums = <STDIN>);
foreach $num (@nums){
	print $words[$num]."\n";
}
