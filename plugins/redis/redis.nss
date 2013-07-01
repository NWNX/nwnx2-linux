#include "nwnx_redis"

// Example event script. Should be self-explainatory.

void main() {
	string channel = redisGetEventChannel();
	string message = redisGetEventMessage();
	WriteTimestampedLogEntry("Got message on channel '" + channel + "': " + message);
}
