#!/usr/bin/env perl

use strict;
use warnings;

sub memoize{
	my ($func) = @_;
	my %cache;
	my $stub = sub{
		my $key = join ',', @_;
		$cache{$key} = $func->(@_) unless exists $cache{$key};
		return $cache{$key};
	};
	return $stub;
}

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

$fastfib = memoize(\&fib);
