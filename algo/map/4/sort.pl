#!/usr/bin/env perl

use strict;
use warnings;

my @a = "a".."l";
my @d;

srand();
foreach ( @d = @a )
{
	my $i = rand @a;
	($_, $d[$i]) = ( $d[$i], $_ );
}

print "@d\n";

# require './bubblesmart.pl'; bubblesmart (\@d);
# require './shellsort.pl'; shellsort (\@d);
 require './my_shellsort.pl'; shellsort (\@d);
# require './heap.pl'; heapify_array_up (\@d);


print "@d\n";
