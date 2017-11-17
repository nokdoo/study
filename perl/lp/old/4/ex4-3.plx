#!/usr/bin/perl -w
#use strict;



my @nums = 1..10;
my @result = &getlist(@nums);

sub getavg{
	my $cnt = 0;
	my $sum = 0;
	foreach(@_){
		$sum += $_;
		$cnt++;
	}
	return $sum/$cnt;
}

sub getlist{
	my $agv = &getavg(@_);
	my @list;
	
	foreach (@_){
		if($_ > $agv){
			push @list, $_;
		}
	}

	print @list;
}
