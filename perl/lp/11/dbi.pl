#!/usr/bin/perl

use utf8;

use DBI;
use strict;

my $dbh = DBI->connect("DBI:mysql:database=eng;host=192.168.35.155;port=3306", "english", "1234") or die $DBI::errstr;

my $sth = $dbh->prepare("select * from words where word = 'by which'");
$sth->execute();
my @arr = $sth->fetchrow_array;
$sth->finish;

foreach(@arr){
	print $_."\n";
}
