#!/usr/bin/env perl

sub write_value
{
	my ($x, $y) = @_;
	return 1 if ($x == $y or $y == 1 or $x == 1);
	return write_value($x-1, $y-1)+write_value($x, $y-1);
}

sub write_line
{
	my ($c, $n) = @_;
	for (1..$c)
	{
		print write_value($_, $c);
		print " ";
	}
	print "\n";
}

sub pascal_triangle
{
	my ($n) = @_;
	for (1..$n)
	{
		write_line($_, n);
	}
}

pascal_triangle 10;
