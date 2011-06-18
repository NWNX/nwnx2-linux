#include "nwnx_chat"

void main()
{
    object oPC = OBJECT_SELF;
    int nType = NWNXChat_GetCCMessageType();
    int nSubtype = NWNXChat_GetCCMessagSubtype();
    /*if(GetPCPlayerName(oPC) == "virusman")
        SendMessageToPC(oPC, GetName(oPC)+": "+IntToString(nType)+", "+IntToString(nSubtype));*/
    switch(nType)
    {
        case 14:  //Initiative rolls
        case 5:   //Attack data
        case 6:   //Attack data to party
        case 9:   //Skill data
        case 7:   //Saving throws
            NWNXChat_SuppressMessage();
        break;

        case 11:  //Feedback message
            switch(nSubtype)
            {
                case 182: //XP Given
                case 183: //XP Lost
                    //NWNXChat_SuppressMessage();
                break;

                case 204: //Custom text message
                case 94:
                break;
            }
        break;

        case 3:   //Damage data
        case 4:   //?
        break;

        default:
        if(GetPCPlayerName(oPC) == "virusman")
            SendMessageToAllDMs(GetName(oPC)+": "+IntToString(nType)+", "+IntToString(nSubtype));
        break;
    }
    //NWNXChat_SuppressMessage();
}
