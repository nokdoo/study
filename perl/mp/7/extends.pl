#!/usr/bin/env perl
# Q : extends 를 할 때 + 가 없다면 어떻게 되려나..?
# A : 에러 발생. 꼭 +를 붙이자.

# Q : Moose 를 사용하지 않는 메소드의 경우는?? ( accessor 가 아닌 경우 )


use strict;
use warnings;

package LightSource {
	use Moose;

	has 'power',
		is => 'ro',
		isa => 'Int',
		default => 1;

	sub method {
		print "LightSource\n";
	}
}

package SuperCandle {
	use Moose;

	extends 'LightSource';
	has '+power',
		default => 20;

	sub method {
		print "SuperCandle\n";
	}

	
}

my $candle = SuperCandle->new;
$candle->method;
