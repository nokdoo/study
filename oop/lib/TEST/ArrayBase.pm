package TEST::ArrayBase;
my $VERSION = 1.0;
#use strict;

use constant NAME=> 0;
use constant ARTIST=> 1;
use constant TRACK=> 2;

my %_index_for;
@_index_for{qw(name artist track)} = (NAME, ARTIST, TRACK);

my @_default_data;
@_default_data[NAME, ARTIST, TRACK] = ("king", "ha", 9);

my $_count = 0;

sub get_count {$_count;}

sub _incr_count {$_count++;}

sub new{
	my ($caller, %arg) = @_;
	my $caller_is_obj = ref($caller);
	my $class = $caller_is_obj || $caller;
	no strict "refs";
	my $self = bless [], $class;

	foreach my $member (keys %_index_for)
	{
		my $index = $_index_for{$member};
		if (exists $arg{$member}){
			$self->[$index] = $arg{$member}
		}elsif ($caller_is_obj){
			$self->[$index] = $caller->{$member}
		}
	}

	$self->_incr_count();
	return $self;
}

sub get_name{ return $_[0]->[NAME] }
1;
