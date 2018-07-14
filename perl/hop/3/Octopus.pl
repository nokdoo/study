#!/usr/bin/env perl

use strict;
use warnings;

package Octopus;
sub new{
	my ($class, %args) = @_;
	$args{tentacles} = 8;
	bless \%args, $class;
}

sub name{
	my $self = shift;
	if (@_) { $self->{name} = shift; }
	$self->{name};
}

package main;
my $junko = Octopus->new(favorite_food => "crab cakes");
$junko->name("Junko");
my $fenchurch = Octopus->new(favorite_food => "crab cakes");
$fenchurch->name("Fenchurch");

print $junko->name, "\n";
