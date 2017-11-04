#!perl
use strict;
my @skipper = qw(blue_shirt hat jacket preserver sunscreen);
check_required_items(\@skipper);

sub check_required_items{
	my $ref = shift;
	print "$ref[2]";
}
