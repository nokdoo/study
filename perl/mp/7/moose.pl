#!/usr/bin/env perl
# default 가 없다면 에러가 발생한다.

use strict;
use warnings;



package Cat {
	use Moose;

	has 'name',
		is => 'ro';
	has 'age',
		is => 'ro',
		isa => 'Int',
		default => 0;
}

my $animal = Cat->new(name=>"nya");
print $animal->age;
