This is a very simple plugin to send tracking data to [statsd](https://github.com/etsy/statsd/).

statsd is a very simple send-and-forget udp daemon that can will track your metrics (any metric really),
identified by a unique name. There is no individual setup neccessary.
You can count things, track timing information, track changes-over-time, and so on.

statsd output is usually sent into [graphite](http://graphite.wikidot.com/), which provides an actual
database to query and basic graphing functionality. Nicer frontends to graphite exist, and are easily
found on [google](http://dashboarddude.com/blog/2013/01/23/dashboards-for-graphite/).

Please see the included nwnx_statsd.nss for a list of available function calls.
