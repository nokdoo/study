#!perl

print <<EOF;    # same as earlier example
The price is $Price.
EOF
print <<"EOF";  # same as above, with explicit quotes
The price is $Price.
EOF
print <<'EOF';    # single–quoted quote
All things (e.g. a camel's journey through
		A needle's eye) are possible, it's true.
But picture how the camel feels, squeezed out
In one long bloody thread, from tail to snout.
–– C.S. Lewis
EOF
print <<\EOF;     # another single–quoted quote
I could really use $100 about now.
EOF
print << x 10;    # print next line 10 times
The camels are coming!  Hurrah!  Hurrah!
print <<"" x 10;  # the preferred way to write that
The camels are coming!  Hurrah!  Hurrah!
print <<`EOC`;    # execute commands
echo hi there
echo lo there
EOC
print <<"dromedary", <<"camelid";   # you can stack them
I said bactrian.dromedary
She said llama.
camelid
funkshun(<<"THIS", 23, <<'THAT');   # doesn't matter if they're in parens
Here's a line
or two.
THIS
And here's another.
THAT
