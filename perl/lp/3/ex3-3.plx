#!/usr/bin/perl -w
chomp(@words = <STDIN>);
@words = sort @words;
#foreach(@words){
#	print;
#	print "\n";
#}
print "@words\n";
