#!/usr/bin/env perl

my $tree = { 
	_tag => "p",
	_content => [
		"But I don't ",
			{
				_tag => "font",
				_content => ["want"],
				color => "red",
				size => 3,
			},
			" to go to bed now!",
			],
};

sub untag_html{
	my ($html) = @_;
	return $html unless ref $html;

	my $test = '';
	for my $item (@{$html->{_content}}){
		$text .= untag_html($item);
	}
	return $text;
}

print untag_html($tree), "\n";
