#!perl
use strict;
my @required = qw(preserver sunscreen water_bottle jacket);
my %gilligan = map {$_, 1} qw(red_shirt hat lucky_socks water_bottle);
foreach (@required){
	unless($gilligan{$_}){
		print "Gilligan is missing $_.\n";
	}
}

sub check_required_items{
	my $who = shift;
	my %whos_items = map {$_, 1} @_;
	my @required = qw(preserver sunscreen water_bottle jacket);

	foreach (@required){
		unless ($whos_items{$_}){
			print "$who is missing $_.\n";
		}
	}
}

my @gilligan = qw( red_shirt hat lucky_socks water_bottle);
check_required_items('gilligan', @gilligan);

