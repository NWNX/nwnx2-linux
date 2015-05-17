#ifndef NWNX_CHAT_PLUGINLINK_H
#define NWNX_CHAT_PLUGINLINK_H

static const char* EVENT_CHAT_MESSAGE = "Chat/Message";
static const char* EVENT_CHAT_CCMESSAGE = "Chat/CCMessage";

/**
 * Event: Chat/Message
 * Provider: nwnx_chat
 *
 * Called whenever a qualifying chat message is sent, dependent on nwnx_chat settings.
 */
typedef struct {
    /* Chat message being sent. */
    const char* msg;
    /* Object receiving the message. */
    unsigned int to;
    /* Object sending the message. */
    unsigned int from;
    /* Channel the message was sent on. */
    unsigned char channel;
    /* Set to true to suppress the chat message. */
    bool suppress;
}
ChatMessageEvent;

/**
 * Event: Chat/CCMessage
 * Provider: nwnx_chat
 *
 * Called whenever a CNWCCMessage is sent.
 */
typedef struct {
    /* CNWCCMessageData type. */
    int type;
    /* CNWCCMessageData subtype. */
    int subtype;
    /* Object being sent the message. */
    unsigned int to;
    /* CNWCCMessageData instance. */
    void *msg_data;
    /* Set to true to suppress the CNWCCMessageData message. */
    bool suppress;
}
ChatCCMessageEvent;

#endif // NWNX_CHAT_EVENTS_H
