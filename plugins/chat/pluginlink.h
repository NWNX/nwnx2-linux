#ifndef NWNX_CHAT_PLUGINLINK_H
#define NWNX_CHAT_PLUGINLINK_H

#include "core/ipc/Signal.h"

/**
 * Event: ChatMessageEvent
 * Provider: nwnx_chat
 *
 * Called whenever a qualifying chat message is sent, dependent on nwnx_chat settings.
 */
using ChatMessageEvent = Signal<
    /* Chat message being sent. */
    const char*,
    /* Object receiving the message. */
    unsigned int,
    /* Object sending the message. */
    unsigned int,
    /* Channel the message was sent on. */
    unsigned char,
    /* Set to true to suppress the chat message. */
    bool&
>;

/**
 * Event: ChatCCMessageEvent
 * Provider: nwnx_chat
 *
 * Called whenever a CNWCCMessage is sent.
 */
using ChatCCMessageEvent = Signal<
    /* CNWCCMessageData type. */
    int,
    /* CNWCCMessageData subtype. */
    int,
    /* Object being sent the message. */
    unsigned int,
    /* CNWCCMessageData instance. */
    void *,
    /* Set to true to suppress the CNWCCMessageData message. */
    bool&
>;

#endif // NWNX_CHAT_EVENTS_H
