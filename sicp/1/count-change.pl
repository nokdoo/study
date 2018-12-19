#!/usr/bin/env perl

use warnings;
use strict;
no warnings 'recursion';

sub first_denomination
{
	my ($kinds_of_coins) = @_;
	return 1 if $kinds_of_coins == 1;
	return 5 if $kinds_of_coins == 2;
	return 10 if $kinds_of_coins == 3;
	return 25 if $kinds_of_coins == 4;
	return 50 if $kinds_of_coins == 5;
}

sub cc
{
	my ($amount, $kinds_of_coins) = @_;

	if ( $amount == 0 )
	{
		return 1;
	}

	if ( ($amount < 0) || ($kinds_of_coins == 0) )
	{
		return 0;
	}

	&cc($amount, $kinds_of_coins-1) + &cc($amount-first_denomination($kinds_of_coins), $kinds_of_coins);

}

sub countchange
{
	my ($amount) = @_;
	&cc($amount, 5);
}

print countchange 100;

