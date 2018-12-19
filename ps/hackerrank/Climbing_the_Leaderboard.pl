#!/usr/bin/perl

use strict;
use warnings;

# Complete the climbingLeaderboard function below.
sub climbingLeaderboard {
	my ($scores, $alice, $scores_count, $alice_count) = @_;
	@$alice = reverse @$alice;

	my $rank = 1;
	my $last_score = 0;
	my $last_alice_score = 0;
	my $alice_idx = 0;
	my @results;

	for (my $i = 0; $i<$scores_count; ){
		if($alice_idx == $alice_count){
			last;
		}
		
		my $alice_score = $$alice[$alice_idx];
		if($last_alice_score == $alice_score){
			push @results, $rank;
			$alice_idx++;
			next;
		}
		
		my $score = $$scores[$i];
		if($last_score == $score){
			$i++;
			next;
		}else{
			if($alice_score > $score){
				push @results, $rank;
				$alice_idx++;
				$last_alice_score = $alice_score;
			}elsif($alice_score == $score){
				push @results, $rank;
				$alice_idx++;
				$last_alice_score = $alice_score;
			}else{
				$i++;
				$rank++;
				$last_score = $score;
			}
		}
	}

	for($alice_idx..$alice_count-1){
		push @results, $rank;
	}
	reverse @results;
}

open(my $fptr, '>', $ENV{'OUTPUT_PATH'});

my $scores_count = <>;
$scores_count =~ s/\s+$//;

my $scores = <>;
$scores =~ s/\s+$//;
my @scores = split /\s+/, $scores;

my $alice_count = <>;
$alice_count =~ s/\s+$//;

my $alice = <>;
$alice =~ s/\s+$//;
my @alice = split /\s+/, $alice;

my @result = climbingLeaderboard \@scores, \@alice, $scores_count, $alice_count;

print $fptr join "\n", @result;
print $fptr "\n";

close $fptr;
