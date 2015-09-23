#include "ccutil.h"
#include <string.h>
#include "interfacecodes.h"
#include "api_linfunctions.h"

extern BYTE abyCommandPacket[], abyResponsePacket[];

bool initCommandTable( void )
{
	abyCommandPacket[PAL_BYTE] = DDAPI_PAL_initCommandTable;
	abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_initCommandTable;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool enableCommandHandler( void )
{
    abyCommandPacket[PAL_BYTE] = DDAPI_PAL_enableCommandHandler;
    abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_enableCommandHandler;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool disableCommandHandler( void )
{
    abyCommandPacket[PAL_BYTE] = DDAPI_PAL_disableCommandHandler;
    abyCommandPacket[OPCODE_BYTE] = DDAPI_OPCODE_disableCommandHandler;
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

bool addCommandTableEntry(struct command * commandEntry)
{
	abyCommandPacket[PAL_BYTE]=DDAPI_PAL_addCommandTableEntry;
    abyCommandPacket[OPCODE_BYTE]=DDAPI_OPCODE_addCommandTableEntry;
    memcpy ( &abyCommandPacket[2], (BYTE *)commandEntry, 11 );
    if (sendMessage(abyCommandPacket, abyResponsePacket) == true)
    {
        return isAck(abyResponsePacket);
    }
    return false;
}

