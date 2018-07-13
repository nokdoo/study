#!/usr/bin/env perl

{
	my %cache;
	sub fib{
		my ($month) = @_;
		unless(exists $cache{$month}){
			if($month == 1){
				$cache{$month} = 0;
			}elsif($month == 2){
				$cache{$month} = 1;
			}else{
				$cache{$month} = fib($month-1) + fib($month-2);
			}
		}
		return $cache{$month};
	}
}

print fib(10);
