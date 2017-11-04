#!perl

use strict;

sub check_required_items{
	my $who = shift;
	my $items = shift;

	my %whose_items = map { $_, 1 } @$items;

	my @required = qw(preserver sunscreen water_bottle jacket);
	my @missing = ();

	for my $item(@required){
		unless ($whose_items{$item}){
			print "$who is missing $item.\n";
			push @missing, $item;
		}
	}

	if(@missing){
		print "Adding @missing to @$items for $who.\n";
		push @$items, @missing;
	}
		
}

my @n1 = qw( sunscreen test test1 test2 jacket );
my @n2 = qw( sunscreen test1 test2 jacket );
my @n3 = qw( sunscreen jacket );

my @test = ("nokdoo" => \@n1);
print @test;
#print ${$test[1]}[0];
print $test[1] -> [0];
