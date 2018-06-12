#!/usr/bin/env perl

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
