#pragma once

/**
 * Event: EVENT_CONNECT_PLAYER_CONNECT
 * Param: ConnectPlayerConnectEvent
 * Abortable: No
 *
 * Called when a player connects. This is AFTER non-window messages and
 * authentication, just before the haks are sent to the client.
 * You can disconnect them here by aborting the callchain, optionally
 * giving a strref reason.
 */
#define EVENT_CONNECT_PLAYER_CONNECT "Connect/PlayerConnect"

struct ConnectPlayerConnectEvent {
    const uint32_t playerId;
    uint32_t disconnect_strref;
};

/**
 * Event: EVENT_CONNECT_PLAYER_DISCONNECT
 * Param: ConnectPlayerDisconnectEvent
 * Abortable: No
 *
 * Called when a player disconnects from the server.
 * The player need not neccessarily be in game; this could happen
 * during connection setup or in the character list as well.
 *
 * strref is the tlk entry with which the player was booted, if the
 * disconnect originated serverside.
 *
 * _BEFORE is called before actually cleaning up the player, so a CNWSPlayer*
 * object is still available.
 *
 * _AFTER only sees the playerId, all related data has already been freed.
 */
#define EVENT_CONNECT_PLAYER_DISCONNECT_BEFORE "Connect/PlayerDisconnectBefore"
#define EVENT_CONNECT_PLAYER_DISCONNECT_AFTER "Connect/PlayerDisconnectAfter"

struct ConnectPlayerDisconnectEvent {
    const uint32_t playerId;
    const uint32_t strref;
};

