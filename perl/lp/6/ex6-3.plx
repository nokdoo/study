#!/usr/bin/perl -w
use strict;

=pod
while(my ($key, $val) = each %ENV){
	print "$key, $val\n";
}
=cut

my $long = 0;
foreach my $key(keys %ENV){
	my $len = length $key;
	$long = $len if $len > $long;
}

foreach my $key(sort keys %ENV){
	printf "%-${long}s %s\n", $key, $ENV{$key};
}
