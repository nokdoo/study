#!/usr/bin/perl

use strict;

use HTTP::SimpleLinkChecker qw(check_link);

my @links = qw( www.naver.com www.opxp.org );

my @good_links = grep{
	check_link( $_ );
	! $HTTP::SimpleLinkChecker::ERROR;
} @links;

print @good_links;
