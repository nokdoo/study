#!/usr/bin/env perl

use strict;
use warnings;

my @a = "a".."z";
my @d;

srand();
foreach ( @d = @a )
{
	my $i = rand @a;
	($_, $d[$i]) = ( $d[$i], $_ );
}


require './bubblesmart.pl'; bubblesmart (\@d);





print @d;
