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

print "@d\n";

# require './bubblesmart.pl'; bubblesmart (\@d);
# require './shellsort.pl'; shellsort (\@d);
# require './my_shellsort.pl'; shellsort (\@d);
# require './heap.pl'; heapify_array_up (\@d);

# @d = (9,2,8,4,5,3,6,7,1);
# print "@d\n";
# require './bucketsort.pl'; bucketsort (\@d, 1, 9);

# my @array = qw/wolf boar hawk bear pike lion lynx puma/;
# print "@array\n";
# require './radixsort.pl'; radixsort(\@array);
# print "@array\n";


print "@d\n";
