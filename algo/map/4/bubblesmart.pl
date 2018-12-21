sub bubblesmart
{
	my $arr = shift;
	# my $to = scalar @$arr;
	my $to = $#$arr;
	my $start = 0;
	
	while (1)
	{
		my $new_start;
		my $new_end = 0;

		for ( my $i = $start || 1; $i <= $to; $i++ )
		{
			if ( @$arr[$i-1] gt @$arr[$i] )
			{
				@$arr[$i-1, $i] = @$arr[$i, $i-1];
				$new_end = $i-1;
				$new_start = $i-1 unless defined $new_start;
			}
		}
		last unless defined $new_start;
		$to = $new_end;
		$start = $new_start;
	}
}
1;
