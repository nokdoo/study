#!/usr/bin/perl -w
use strict;

my @list;

sub greet{
	if(@list == 0){
		print "hi @_ first\n";
	}else{
		print "hi @_ already @list\n";
	}
	push @list, @_;
}

greet("haha");
greet("haha2");
greet("haha3");
