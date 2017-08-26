#!perl -w

use strict;

$_= "I saw Barneydown Fred\nlast night.\n";

if(/Barney.*Fred/s){ #s를 빼면 \n단위로 끊김
	print "That string mentions Fred\n";
}
