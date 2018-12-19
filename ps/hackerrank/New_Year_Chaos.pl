#!/usr/bin/env perl

use strict;
use warnings;

sub swap{
	my $tmp;
	$tmp = $_[0];
	$_[0] = $_[1];
	$_[1] = $tmp;
}

# Complete the minimumBribes function below.
sub minimumBribes {
	print "start=========", "\n";
	my $linelength = @{$_[0]};
	my @currentline = (0, @{$_[0]});
	my @changecnt = (0)x($linelength+1);
	my $cnt = 0;
	
	my $start = 1;
	while($start){
		$_ = $start;
		if($start == $linelength){ last;}
		print "24: \$_ = $_", "\n";
		if($start == $currentline[$start]){
			$start++;
			next;
		}else{
			while($currentline[$_] < $currentline[$_+1]){
				print "30: $_", "\n";
				$_++;
			}
			print "33: @currentline \$_ = $_", "\n";
			while($currentline[$_] > $currentline[$_+1]){
				swap $currentline[$_], $currentline[$_+1];
				$cnt++;
				if(++$changecnt[$currentline[$_+1]] == 3){
					print "Too chaotic", "\n";
					return;
				}
				$_--;	
			}

		}
	}
	print "@currentline", "\n";
	print "end==========", "\n";
	print "@changecnt", "\n";
	print $cnt, "\n";
}

my $t = <>;
$t =~ s/\s+$//;

for (my $t_itr = 0; $t_itr < $t; $t_itr++) {
    my $n = <>;
    $n =~ s/\s+$//;

    my $q = <>;
    $q =~ s/\s+$//;
    my @q = split /\s+/, $q;

    minimumBribes \@q;
}
