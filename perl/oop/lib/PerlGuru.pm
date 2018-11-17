package PerlGuru;

sub _init{
	my ($self, %args) = @_;
	$self->PerlHacker::_init(%args);
	$self->PunMeister::_init(%args);
	$self->{_acolytes} = $args{followers};
	$self->{_philosophy} = $args{manifesto};
}
1;
