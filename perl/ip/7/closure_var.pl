#!perl
-w;
use strict;

use File::Find;
use File::Find::Closures;
use File::Spec::Functions qw(canonpath no_upwards);

sub find_by_min_size{
	my $min = shift;
	my @files = ();
	sub{ push @files, canonpath($File::Find::name)
		if -s $_ >= $min},
	sub { @files = no_upwards(@files);
	wantarray ? @ files : [ @files ]}
}	

my ($wanted, $list_reporter) = find_by_name( qw(README) );

my @directories;
find ($wanted, @directories);

my @readmes = $list_reporter->();


