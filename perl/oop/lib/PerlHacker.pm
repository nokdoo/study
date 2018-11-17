package PerlHacker;

my @ISA = qw(_Initializable Programmer Obfuscator);

sub _init{
	my ($self, %args) = @_;
	$self->{_name} = $args{name};
	$self->{_alias} = $args{mokiker};
	$self->{_langs} = $args{languages};
}
1;
