#!/usr/bin/env perl

use IO::Socket;

my ($addr, $port) = ("localhost", "8888");


$socket = IO::Socket::INET->new(
								PeerAddr => $addr,
								PeerPort => $port, 
								Proto => "tcp",
								Type => SOCK_STREAM 
							)
	or die "Couldn.t connect to $remote_host:$remost_port :$@\n";

print $socket "Why don't you call me anymore?\n";

$answer = <$socket>;

print $answer;

close($socket);

