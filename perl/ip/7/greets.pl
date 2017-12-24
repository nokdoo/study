#!perl
-w;
use strict;

sub skipper_greets{
	my $person = shift;
	print "Skipper: Hey there, $person!\n";
}

sub gilligan_greets{
	my $person = shift;
	if($person eq 'Skipper'){
		print "Gilligan: Sir, yes, sir, $person!\n";
	}else{
		print "Gilligan: Hi, $person!\n";
	}
}

sub professor_greets{
	my $person = shift;
	print "Professor: By my calculations, you must be $person!\n";
}

my %greets = (
	Gilligan => \&gilligan_greets,
	Skipper => \&skipper_greets,
	Professor => \&professor_greets,
);

my @room;
for my $person(qw(Gilligan Skipper Professor)){
	print "\n";
	print "$person walks into the room.\n";
	for my $room_person(@room){
		$greets{$person}->($room_person);
		$greets{$room_person}->($person);
	}
	push @room, $person;
}


