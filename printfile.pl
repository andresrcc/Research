#!/usr/bin/perl -w

#Basic file reading using perl

my $file = $ARGV[0];
my $opened = open(my $file_handler, "<", $file);

if(!$opened){
    die "Could not open file";
}

while(!eof($file_handler)){
    my $line = readline($file_handler);
    print $line;
}
