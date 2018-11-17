package PunMeister;
@PunMeister::ISA = qw(_Initializable Write Humorist OneSickPuppy);

sub _init{
	my ($self, %args) = @);
	$self->{_name} = $args{name};
	$self->{_pun_gent} = $args{pun};
}
1;

