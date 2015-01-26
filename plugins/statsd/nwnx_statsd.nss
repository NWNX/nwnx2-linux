/**
 * Increment a key.
 */
void statsd_inc(string key);

/**
 * Decrement a key.
 */
void statsd_dec(string key);

/**
 * Send a GAUGE value.
 */
void statsd_gauge(string key, int size);

/**
 * Send a COUNT value.
 */
void statsd_count(string key, int size);

/**
 * Send a TIMING value (in ms).
 */
void statsd_timing(string key, int ms);

/**
 * This is a helper to make timings easier. Simply call:
 *   statsd_timing_start("some.key");
 *   expensive_code_to_track();
 *   statsd_timing_stop("some.key");
 *  .. and the plugin will do the rest.
 *
 * This uses clock_gettime() in the background, and the plugin
 * tracks used keys - so be aware that start("samekey") without a stop("samekey")
 * to follow will leak (a tiny amount of) memory.
 */
void statsd_timing_start(string key);

void statsd_timing_stop(string key);


void statsd_inc(string key)
{
	SetLocalString(GetModule(), "NWNX!STATSD!INC", key);
}

void statsd_dec(string key)
{
	SetLocalString(GetModule(), "NWNX!STATSD!DEC", key);
}

void statsd_gauge(string key, int size)
{
	SetLocalString(GetModule(), "NWNX!STATSD!GAUGE", key + " " + IntToString(size));
}

void statsd_count(string key, int size)
{
	SetLocalString(GetModule(), "NWNX!STATSD!COUNT", key + " " + IntToString(size));
}

void statsd_timing(string key, int ms)
{
	SetLocalString(GetModule(), "NWNX!STATSD!TIMING", key + " " + IntToString(ms));
}

void statsd_timing_start(string key)
{
	SetLocalString(GetModule(), "NWNX!STATSD!START", key);
}

void statsd_timing_stop(string key)
{
	SetLocalString(GetModule(), "NWNX!STATSD!STOP", key);
}
