#!/usr/bin/env perl

use strict;
use warnings;

sub solve {
	my ($arr_ref) = @_;
	my %hash1;
	my %hash2;

	foreach my $str (@$arr_ref)
	{
		my $len = length $str;
		my $flag = 0;
		for(1..$len)
		{
			my $word = substr($str, 0, $_);
			unless (exists $hash2{$word})
			{
				$hash2{$word} = 0;
				if ($flag == 0 && !(exists $hash1{$word}))
				{
					$flag = 1;
					$hash1{$word} = 1;	
					print "$word\n";
				}
			}

			if($_ == $len)
			{
				$hash2{$str}++; 
				if ($flag == 0)
				{
					if ($hash2{$str}>1)
					{
						print "$str $hash2{$str}\n";
					}
					else
					{
						print "$str\n";
					}
				}
			}
		}
	}
}

my $n = <>;
chomp $n;
my @arr;
for (1..$n) {
	my $line = <>;
	chomp $line;
	push @arr, $line;
}

solve(\@arr);

