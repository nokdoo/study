#!/usr/bin/env perl

sub hanoi{
	my($n, $start, $end, $extra) = @_;
	if($n == 1){
		print "Move disk #1 from $start to $end.\n";
	}else{
		hanoi($n-1, $start, $extra, $end);
		print "Move disk #$n from $start to $end.\n";
		hanoi($n-1, $extra, $end, $start);
	}
}

hanoi(10, 'A', 'C', 'B');
