#!/usr/local/bin/perl
-w;
use strict;

use Math::BigInt;

my $val = Math::BigInt->new(2);

$val->bpow(1000);

print $val->bstr;
