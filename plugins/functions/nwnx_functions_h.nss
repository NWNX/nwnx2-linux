const int CREATURE_EVENT_HEARTBEAT      = 0;
const int CREATURE_EVENT_PERCEPTION     = 1;
const int CREATURE_EVENT_SPELLCAST      = 2;
const int CREATURE_EVENT_ATTACKED       = 3;
const int CREATURE_EVENT_DAMAGED        = 4;
const int CREATURE_EVENT_DISTURBED      = 5;
const int CREATURE_EVENT_ENDCOMBAT      = 6;
const int CREATURE_EVENT_CONVERSATION   = 7;
const int CREATURE_EVENT_SPAWN          = 8;
const int CREATURE_EVENT_RESTED         = 9;
const int CREATURE_EVENT_DEATH          = 10;
const int CREATURE_EVENT_USERDEF        = 11;
const int CREATURE_EVENT_BLOCKED        = 12;

const int MOVEMENT_RATE_PC          = 0;
const int MOVEMENT_RATE_IMMOBILE    = 1;
const int MOVEMENT_RATE_VERY_SLOW   = 2;
const int MOVEMENT_RATE_SLOW        = 3;
const int MOVEMENT_RATE_NORMAL      = 4;
const int MOVEMENT_RATE_FAST        = 5;
const int MOVEMENT_RATE_VERY_FAST   = 6;
const int MOVEMENT_RATE_DEFAULT     = 7;
const int MOVEMENT_RATE_DM_FAST     = 8;

const int VARIABLE_TYPE_INT         = 1;
const int VARIABLE_TYPE_FLOAT       = 2;
const int VARIABLE_TYPE_STRING      = 3;
const int VARIABLE_TYPE_OBJECT      = 4;
const int VARIABLE_TYPE_LOCATION    = 5;

struct scriptvar
{
    string Name;
    int    Type;
    string Value;
};