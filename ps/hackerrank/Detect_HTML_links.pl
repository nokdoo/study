#!/usr/bin/env perl

use strict;
use warnings;

my $input = <STDIN>;

for(1..$input)
{
    my $line = <STDIN>;
    my $str = qq/<a\\s+href=["'](.+?)['"].*?>(.*?)<\/a>/;
    while($line =~ /$str/g)
    {
        my $value = $1;
        my $content = $2;
        $value =~ s/^\s+//;
        $value =~ s/\s+$//;
        $content =~ s/<.*?[\\]*>//g;
        $content =~ s/^\s+//;
        $content =~ s/\s+$//;
        print "$value,$content\n";
    }
}

