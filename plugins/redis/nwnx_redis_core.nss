// Returns 1 if the last command produced an error.
int redisErr();

// Returns the last error message.
string redisErrStr();

// Pushes a argument to be used with redisCommand.
// We're pushing them separately because that's the only way
// to ensure binary-safe operation (since nwscript doesn't allow
// escaping special characters in strings).
void redisPushBinarySafe(string value);

// Execute a command with all arguments pushed before:
//   redisPushBinarySafe("SET");
//   redisPushBinarySafe("key");
//   redisPushBinarySafe("some value");
//   redisCommand();
// Is functionally equivalent to calling: SET key 'some value'
// Returns the value given back by redis, or '' on nil and error.
string redisCommand();

// Returns the first/next result from the last query.
// This can be used to iterate over multi-field replies like arrays and sets.
// This can also be used to retrieve the last non-array result once, so
// iterator code will work for both types of results.
// Will return "" if no more elements are available.
//
// Example code:
//    string iterator;
//    while ((iterator = redisGet()) != "")
//      WriteTimestampedLogEntry("iter: " + iterator);
string redisGet();

// Make redis subscribe to the given channel (pattern).
// Use this instead of SUBSCRIBE because SUBSCRIBE operates on
// your command context and will break things unless you know what you are doing.
void redisSubscribe(string channel, int wildcard = 0);

// Make redis unsubscribe from the given channel (pattern).
// Use this instead of UNSUBSCRIBE because UNSUBSCRIBE operates on
// your command context and will break things unless you know what you are doing.
void redisUnsubscribe(string channel, int wildcard = 0);

// Returns the channel on which a message was received.
// Only valid inside the redis pubsub event script.
string redisGetEventChannel();
// Returns the message received.
// Only valid inside the redis pubsub event script.
string redisGetEventMessage();

// Store the given object as raw gff data.
// Examples for query: "SET someCreature %b"
// You need to make sure exactly one %b appears in it.
void redisSCO(string query, object obj);

// Examples for query: "GET someCreature"
object redisRCO(string query, location loc, object owner);

// Implementation below.

const int
	REDIS_REPLY_STRING        = 1,
	REDIS_REPLY_ARRAY         = 2,
	REDIS_REPLY_INTEGER       = 3,
	REDIS_REPLY_NIL           = 4,
	REDIS_REPLY_STATUS        = 5,
	REDIS_REPLY_ERROR         = 6;

int    redisLastReplyType   = 0;
string redisLastErrorStr    = "";
string redisLastReply       = "";
int    redisGetOffset       = 0;

int redisErr() {
	return (redisLastReplyType == REDIS_REPLY_ERROR);
}
string redisErrStr() {
	return redisLastErrorStr;
}

string redisCommand() {
	string result = "";

	string redisStr = "NWNX!REDIS!CMD";
	SetLocalString(GetModule(), redisStr, "1");
	string ret = GetLocalString(GetModule(), redisStr);

	// Reply format: TYPE strlen(RESULT) result
	int pos_result_len = FindSubString(ret, " ", 0) + 1;
	int pos_result     = FindSubString(ret, " ", pos_result_len) + 1;

	int replytype  = StringToInt(GetSubString(ret, 0, pos_result_len));
	int result_len = StringToInt(GetSubString(ret, pos_result_len, pos_result));
	result = GetSubString(ret, pos_result, result_len);

	if (replytype == REDIS_REPLY_ERROR) {
		redisLastErrorStr = result;
		result            = "";
	} else {
		redisLastErrorStr = "";
	}

	redisLastReplyType = replytype;
	redisLastReply      = result;
	redisGetOffset      = 0;

	return result;
}

string redisGet() {
	switch (redisLastReplyType) {
		case REDIS_REPLY_ERROR:
			return "";

		case REDIS_REPLY_ARRAY:
			while (redisGetOffset < GetStringLength(redisLastReply)) {
				int pos_end_of_sz = FindSubString(redisLastReply, " ", redisGetOffset);
				int start_of_content = pos_end_of_sz + 1;
				string szstr = GetSubString(redisLastReply, redisGetOffset, pos_end_of_sz - redisGetOffset);
				int sz = StringToInt(szstr);
				int end_of_content = start_of_content + sz;
				string content = GetSubString(redisLastReply, start_of_content, sz);

				redisGetOffset = end_of_content + 1; // redisGetOffset + " "

				return content;
			}
			return "";

		default:
			string ret = redisGetOffset == 0 ? redisLastReply : "";
			redisGetOffset = GetStringLength(redisLastReply);
			return ret;
	}

	return "";
}

void redisSubscribe(string channel, int wildcard = 0) {
	if (wildcard)
		SetLocalString(GetModule(), "NWNX!REDIS!PSUBSCRIBE", channel);
	else
		SetLocalString(GetModule(), "NWNX!REDIS!SUBSCRIBE", channel);
}
void redisUnsubscribe(string channel, int wildcard = 0) {
	if (wildcard)
		SetLocalString(GetModule(), "NWNX!REDIS!PUNSUBSCRIBE", channel);
	else
		SetLocalString(GetModule(), "NWNX!REDIS!UNSUBSCRIBE", channel);
}

void redisPushBinarySafe(string value) {
	SetLocalString(GetModule(), "NWNX!REDIS!PUSH", value);
}

string redisGetEventChannel() {
	SetLocalString(GetModule(), "NWNX!REDIS!GETEVCHAN", "1");
	return GetLocalString(GetModule(), "NWNX!REDIS!GETEVCHAN");
}
string redisGetEventMessage() {
	SetLocalString(GetModule(), "NWNX!REDIS!GETEVMSG", "1");
	return GetLocalString(GetModule(), "NWNX!REDIS!GETEVMSG");
}

void redisSCO(string query, object obj) {
	SetLocalString(GetModule(), "NWNX!REDIS!SETSCORCOQUERY", query);
	StoreCampaignObject("NWNX", "REDIS", obj);
}

object redisRCO(string query, location loc, object owner) {
	SetLocalString(GetModule(), "NWNX!REDIS!SETSCORCOQUERY", query);
	return RetrieveCampaignObject("NWNX", "REDIS", loc, owner, OBJECT_INVALID);
}
