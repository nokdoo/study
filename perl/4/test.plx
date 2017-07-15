#!/usr/bin/perl -w
sub list_from{
	if($a < $b){
		$a .. $b;
	}else{
		reverse $a..$b;
	}
}
$a = 11;
$b = 6;

@c = &list_from;

print @c."\n";

