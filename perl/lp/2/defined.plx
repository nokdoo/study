#!/usr/bin/perl -w
$string = <STDIN>;
if(defined($string)){
	print "The input was $string";
}else{
	print "No input available!\n";
}
