#!/usr/bin/env perl

sub gridlandMetro {
    my ($n, $m, $k, @track) = @_;
    my $count = $n * $m;
	
	my @sorted_track = sort { (scalar @$a[0]) <=> (scalar @$b[0]) || (scalar @$a[1]) <=> (scalar @$b[1]) || (scalar @$a[2]) <=> (scalar @$b[2]) } @track;
	
	my @rails = ();
	
	my ($left, $right) = ($sorted_track[0][1], $sorted_track[0][2]);
	my $rep_row = $sorted_track[0][0];
	my $i = 1;
	
	while($i < $k){
		while($rep_row == $sorted_track[$i][0]){
			my ($cur_left, $cur_right) = ($sorted_track[$i][1], $sorted_track[$i][2]);
			if($left <= $cur_left && $cur_left <= $right){
				$right = ($cur_right > $right) ? $cur_right : $right;
				$i++;
			}else{
				last;
			}
		}
		push @rails, ($left, $right);
		$rep_row = $sorted_track[$i][0];
		($left, $right) = ($sorted_track[$i][1], $sorted_track[$i][2]); 
		$i++;
		if($i == $k){
			push @rails, ($left, $right);
		}
	}
	
	while(@rails){
		$count -= (pop @rails) - (pop @rails) + 1;
	}
	$count;
}

$n_temp = <STDIN>;
@n_arr = split / /,$n_temp;
$n = $n_arr[0];
chomp $n; 
$m = $n_arr[1];
chomp $m;
$k = $n_arr[2];
chomp $k;
$track_i = 0;
@track = ();
while($track_i < $k){
   my $track_temp = <STDIN>;
   my @track_t = split / /,$track_temp;
   chomp @track_t;
   push @track,\@track_t;
   $track_i++;
}
$result = gridlandMetro($n, $m, $k, @track);
print "$result\n";
