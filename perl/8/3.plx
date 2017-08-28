#!perl -w
use strict;

my $some_other = "I dream of betty rubble.";

if($some_other =~ /\brub\b|rub/){
	print "Aye\n";
}
