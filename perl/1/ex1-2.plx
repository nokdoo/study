#!/usr/bin/perl
@lines = `perldoc -u -f atan2`;
foreach(@lines){
	print;
}
