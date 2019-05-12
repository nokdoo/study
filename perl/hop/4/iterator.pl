#!/usr/bin/env perl
 
use strict;
use warnings;
use feature qw / say /;

sub NEXTVAL { $_[0]->() }
sub Iterator (&) { return $_[0] };

sub upto {
    my ($m, $n) = @_;
    return Iterator {
        return $m <= $n ? $m++ : undef;
   };
 }

my $it = upto(3, 6);
my $it2 = upto(3, 6);
print $it."\n";
print $it2."\n";
say NEXTVAL($it);
say NEXTVAL($it);
say NEXTVAL($it);
say NEXTVAL($it);
say NEXTVAL($it); # undef
