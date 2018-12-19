#!/usr/bin/perl

use strict;
use warnings;

# Complete the organizingContainers function below.
sub organizingContainers {
	my ($container, $n) = @_;
	my (@cont, @type);
	my $result = "Possible";

	for my $i (0..$n-1){
		for my $j (0..$n-1){
			$type[$i] += $$container[$i][$j];
			$cont[$j] += $$container[$i][$j];
		}
	}
	
	for my $i (0..$n-1){
		my $j;
		for ($j=0; $j<$n; $j++){
			if($type[$i] == $cont[$j]){
				my $tmp = $cont[$j];
				$cont[$j] = $cont[$i];
				$cont[$i] = $tmp;
				last;
			}
		}

		if($j == $n){
			$result = "Impossible";
			last;
		}
	}
	print $result, "\n";
	
	return $result;

}

open(my $fptr, '>', $ENV{'OUTPUT_PATH'});

my $q = <>;
$q =~ s/\s+$//;

for (my $q_itr = 0; $q_itr < $q; $q_itr++) {
    my $n = <>;
    $n =~ s/\s+$//;

    my @container = ();

    for (1..$n) {
        my $container_item = <>;
        $container_item =~ s/\s+$//;
        my @container_item = split /\s+/, $container_item;

        push @container, \@container_item;
    }

    my $result = organizingContainers \@container, $n;

    print $fptr "$result\n";
}

close $fptr;
