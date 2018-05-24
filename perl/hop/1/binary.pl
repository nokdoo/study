#!/usr/bin/env perl

my $n = <>;
$n =~ s/\s+$//;

my $result = binary($n);

print $result;

sub binary{
	my ($n) = @_;
	return $n if $n == 0 || $n == 1;

	my $k = int($n/2);
	my $b = $n % 2;

	my $t = binary($k);

	return $t.$b;
}
