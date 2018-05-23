#!/usr/bin/env perl

use IO::Socket;

my $server_port = 8888;

$server = IO::Socket::INET->new(
		LocalPort => $server_port,
		Type => SOCK_STREAM,
		Reuse => 1,
		Listen => 10)
	or die "Couldn't be a tcp server on port $server_port : $@\n";

while($client = $server->accept()){
	print "test\n";
	print $client;
}

close ($server);
