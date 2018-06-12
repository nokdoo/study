#!/usr/bin/env perl

use Data::Dumper;

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

sub walk_html{
	my ($html, $textfunc, $elementfunc) = @_;
	return $textfunc->($html) unless ref $html;

	my @results;
	for my $item (@{$html->{_content}}){
		push @results, walk_html($item, $textfunc, $elementfunc);
	}
	return $elementfunc->($html, @results);
}

sub print_if_h1tag{
	my $element = shift;
	my $text = join '', @_;
	print $text if $element->{_tag} eq 'h1';
	return $text;
}

sub print_alltext{
	shift;
	join '', @_;
}

@tagged_text = walk_html($tree, sub { ['MAYBE', $_[0]] }, \&promote_if_h1tag);
print Dumper(@tagged_text);

sub promote_if_h1tag{
	my $element = shift;
	if($element->{_tag} eq 'h1'){
		return ['KEEPER', join '', map{$_->[1]} @_];
	}else{
		return @_;
	}
}
