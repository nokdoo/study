#!/usr/bin/env perl
use strict;
use warnings;

use Data::Dumper;

sub fib{
	my ($month) = @_; 
	if($month < 2){1}
	else{
		fib($month-1) + fib($month-2);
	}
} 

sub memoize{
	my ($func) = @_;
	print Dumper(@_);
	my %cache;
	my $stub = sub{
		print Dumper(@_);
		my $key = join ',', @_;
		$cache{$key} = $func->(@_) unless exists $cache{$key};
		return $cache{$key};
	};
	return $stub;
}

my $fastfib = memoize(\&fib);

#둘은 같다
print memoize(\&fib)->(10);
print $fastfib->(10);

