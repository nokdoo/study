#!perl -w
use strict;

print "Would you like to play a game? ";

chomp($_ = <>);

if(/yes/i){#yes 또는 YES 
	print "In that case, I recommend that you go bowling.\n";
}
