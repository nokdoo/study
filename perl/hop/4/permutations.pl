#!/usr/bin/env perl

use strict;
use warnings;

sub permute {
	my @items = @{ $_[0] };
	my @perms = @{ $_[1] };
	unless (@items) {
		print "@perms\n";
	} else {
		my ( @newitems, @newperms, $i );
		foreach $i ( 0 .. $#items ){
			@newitems = @items;
			@newperms = @perms;
			unshift( @newperms, splice( @newitems, $i, 1 ) );
			permute( [@newitems], [@newperms] );
		}
	}
}

permute( [qw/1 2 3 4 /], [] );
