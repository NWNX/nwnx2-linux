#!/usr/bin/perl -w
use strict;

# mnx.pl - backend for Minimal NWNX
#
# shamelessly based on Cookbook ex.17-2, udpquotd.pl
#
# listens for requests on udp 1820

use IO::Socket;
use vars  qw/$sock $inpkt $outpkt $hisaddr $hishost $PORTNO $CMDLINE/;

$PORTNO = 2182;
# $CMDLINE = '/usr/games/fortune -s';
$CMDLINE = 'date';

sub pktdump($) {
  my ($pkt) = @_;
  my ($chrout,$length, $i,$j);

  $length= length($pkt);

  for($j=0; $j<$length; ) {
	$chrout = "                ";
	for($i=0; $i<16 && $j<$length; ++$i ) {
	  my $hexval = ord(substr($pkt,$j,1));
	  my $hexstr = pack('H*',$hexval);
	  printf(" %02x",$hexval);
	  substr($chrout,$i,1) = ($hexval>31 && $hexval<128)?chr($hexval):".";
	  ++$j;
	}
	while($i<16) {
	  print "   ";
	  ++$i;
	}
	print " - $chrout\n";
  }
}

$sock = IO::Socket::INET->new(LocalPort => $PORTNO, Proto => 'udp')
 or die "socket: $@";
print "Listening to UDP$PORTNO\n";

while($sock->recv($inpkt,1024)) {
  my ($port, $ipaddr) = sockaddr_in($sock->peername);
  # my ($nwnx,$op,$arg,$value) = split(/[!]/,$inpkt,4);

  # print "Received $op $arg from " . inet_ntoa($ipaddr) . ":$port\n";
  print "Received $inpkt from " . inet_ntoa($ipaddr) . ":$port\n";

  my $output = `$CMDLINE`; # . "¬";
  print "$output\n";

  $sock->send($output);
}
die "recv: $!";
