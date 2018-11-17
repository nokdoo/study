#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;

package _Initializable;

use strict;

sub new{
	my ($class, %args) = @_;
	my $self = bless {}, ref $class || $class;
	$self->_init(%args);
	return $self;
}

package PerlHacker;

@PerlHacker::ISA = qw(_Initializable  );

sub _init{
	my ($self, %args) = @_;
	$self->{_name} = $args{name};
	$self->{_alias} = $args{mokiker};
	$self->{_langs} = $args{languages};
}

package PunMeister;
@PunMeister::ISA = qw(_Initializable );

sub _init{
	my ($self, %args) = @);
	$self->{_name} = $args{name};
	$self->{_pun_gent} = $args{pun};
}

package PerlGuru;

sub _init{
	my ($self, %args) = @_;
	$self->PerlHacker::_init(%args);
	$self->PunMeister::_init(%args);
	$self->{_acolytes} = $args{followers};
	$self->{_philosophy} = $args{manifesto};
}

package main;

my %args = (
	_name=>"youn",
	_alias=>"haha",
	_langs=>123
);

my $a = PerlHacker->new(%args);
print Dumper($a);
