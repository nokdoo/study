#!/usr/bin/perl -w

$maximum = &max(5,1,2,3,4,2,3);

sub max{
	my($maxnum) = shift @_;
	foreach(@_){
		if($_ > $maxnum){
			$maxnum = $_;
		}
	}
	$maxnum;
}

print $maximum."\n";
