#!/usr/bin/env perl

require "./walk-html.pl";

my $tree = { 
	_tag => "p",
	_content => [
		"But I don't ",
			{
				_tag => "font",
				_content => ["want"],
				color => "red",
				size => 3,
			},
			" to go to bed now!",
			],
};

print walk_html($tree, sub { $_[0] }, \&print_if_h1tag);

