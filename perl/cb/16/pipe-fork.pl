#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dumper;
use lib './lib';
use feature qw/ say /;

use IO::Handle;

my ($reader, $writer);
pipe ( $reader, $writer );
$writer->autoflush(1);

if ( my $pid = fork ) { # write to child
    close $reader;
    say $writer "Parent pid $$ is sending this\n";
    close $writer;
    waitpid($pid, 0);
}
else { # read from parent
    die "cannot fork: $!" unless defined $pid;
    close $writer;
    chomp( my $line = <$reader>);
    say "Child pid $$ just read this: '$line'\n";
    close $reader;
    exit;
}
