#!perl

use strict;

foreach my $operator( qw( + - * / )){
	my $result = eval "2 $operator 2";	
	print "2 $operator 2 is $result\n";

}

print ' tt ' , eval '5 /', "\n";
warn $@ if $@;

print "\n";

my $filename = "../ex6.pl";
my $test = do $filename;
