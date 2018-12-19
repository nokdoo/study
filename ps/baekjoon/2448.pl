#!/usr/bin/env perl

use strict;
use warnings;

my $n = <STDIN>;
my $l = $n;
$n = $n/3;
my $k = 0;
while( ($n = $n >> 1) > 0) {
	$k++;
}
$k++;

my $size = 2**($k-1)*5 + 2**($k-1)-1;
$size = 5 if $k == 1;

my @line = ('-'x$size);

my @arr;
$arr[$size/2] = '*';

my @tmp;
push @tmp, $size/2;
while($l>0)
{
	for(1..3)
	{
		print @line;
		my $i = 0;
		if ($_ == 1)
		{
			while($i<$size)
			{
				if($tmp[$i] eq '*')
				{
					$tmp[$i-1] = '*';
					$tmp[$i] = '-';
					$tmp[$i+1] = '*';
					$i++;
				}
				$i++;
			}
		}
		elsif ($_ == 2)
		{
			while($i<$size)
			{
				while($tmp[$i] ne '*' and $i < $size) {$i++;}
				$tmp[$i-1] = '*';
				$tmp[$i] = '*';
				$tmp[$i+1] = '*';
				$tmp[$i+2] = '*';
				$tmp[$i+3] = '*';
				$i += 4;
			}
		}
		else
		{
			while($i<$size)
			{
				while($tmp[$i] ne '*' and $i<$size) {$i++;}
				$tmp[$i-1] = '*';
				$tmp[$i] = '-';
				$tmp[$i+1] = '-';
				$tmp[$i+2] = '-';
				$tmp[$i+3] = '-';
				$tmp[$i+4] = '-';
				$i += 5;
			}
		}
		print "\n";
		$l--;
	}
}
