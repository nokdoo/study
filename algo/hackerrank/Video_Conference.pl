#!/usr/bin/env perl

use strict;
use warnings;

sub diff_index {
	my ($str1, $str2, $len) = @_;

	$len = 1 unless defined $len;

	my $len1 = length $str1;
	my $len2 = length $str2;
	my $min_len = ($len1 < $len2) ? $len1 : $len2;

	while ($len <= $min_len){
		return $len-1 unless (substr($str1, 0, $len) eq substr($str2, 0, $len));
		$len++;
	}

	return $len-1;
}

sub shortest_prefix {
	my ($str, $hash) = @_;
	my $len_str = length $$str;
	my $len_prefix = 1;

	while ($len_prefix <= $len_str){
		my $substr = substr $$str, 0, $len_prefix;
		unless ( exists $$hash{$substr} ) {
			print "\t\t$$str $substr\n";
			return $substr;
		}
		$len_prefix = diff_index($$hash{$substr}, $$str, $len_prefix)+1;
	}
	print "\t\t$$str $$str\n";
	return $$str;
}

sub solve {
	my ($arr) = @_;
	my %hash;
	my %hash2;
	$hash{_same}=\%hash2;

	foreach my $str (@$arr){
		my $prefix = shortest_prefix(\$str, \%hash);
		if( exists $hash{$prefix} ) {
			$hash2{$prefix}++;
			print "$prefix $hash2{$prefix}\n";
		}else{
			$hash2{$prefix} = 1;
			print "$prefix\n";
			$hash{$prefix} = $str;
		}
	}

	delete $hash{_same};

	return \%hash;
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

