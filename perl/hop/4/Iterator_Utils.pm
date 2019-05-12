package Iterator_Utils;
use strict;
use warnings;
use base 'Exporter';

our @EXPORT_OK = qw(NEXTVAL Iterator
            append imap igrep
            iterate_function filehandle_iterator list_iterator);
our %EXPORT_TAGS = ('all' => \@EXPORT_OK);
sub NEXTVAL { $_[0]->() }
sub Iterator (&) { 
    print @_;
    return $_[0] 
}
