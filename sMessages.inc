//------------------------------------------------------------------------------
// sMessages Include v1.5
// by sSiddhant
//
// This Include belongs to the sInclude Library by sSiddhant. This Include is
// created by sSiddhant and consists of new Type of Client, Death  and Player
// Messages. The List of the functions is given below.
//
// SendClientMessageToTeam(teamid, color, message[])
// SendPlayerMessageToTeam(senderid,teamid, message[])
// SendPlayerMessageToAllOthers(senderid, message[])
// SendPlayerMessageToAllOthers(senderid, message[])
// SendClientMessageToAdmins(color, message[])
// SendPlayerMessageToAdmins(senderid,message[])
// SendDeathMessageToTeam(teamid, killerid, killee, reason)
// SendDeathMessageToAdmins( killerid, killee, reason)
// SendDeathMessageToAllOthers(playerid,killerid,killee,reason)
// SendClientMessageToNonAdmins(color, message[])
// SendPlayerMessageToNonAdmins(senderid,message[])
// SendDeathMessageToNonAdmins( killerid, killee, reason)
// SendDeathMessageToOtherTeams(teamid, killerid, killee, reason)
// SendPlayerMessageToTeam(senderid, teamid, message[])
// SendClientMessageToOtherTeams(teamid, color, message[])
//
// (c) Copyright 2016, sSiddhant. All Rights Reserved.
//
//------------------------------------------------------------------------------

#if defined _sMessages_included
  #endinput
#endif
#define _sMessages_included

#pragma library sInclude

//------------------------------------------------------------------------------
// SendClientMessageToAllOthers(playerid, color, message[])
//
// This Function is used to send Message to everyone except the player
//
// playerid: The Id of the player who will not recieve message
// color: The Color of the Message
// message: The message which you want to send

stock SendClientMessageToAllOthers(playerid, color, message[])
{
	for( new i = 0; i <= MAX_PLAYERS; i++)
	{
	    if( i != playerid)
	    {
	        SendClientMessage(i,color,message);
	    }
	}
}

//------------------------------------------------------------------------------
// SendDeathMessageToAllOthers(playerid,killerid,killee,reason)
//
// This Function is used to send  death Message to the Admins
//
// playerid: Th Id of the player who will not recieve the message
// killerid: The Id of the player who killed the player
// killee: The Id of the player who is killed
// reason: The reason for the Death

stock SendDeathMessageToAllOthers (playerid, killerid, killee, reason)
{
	for( new i = 0; i<= MAX_PLAYERS; i++)
	{
	    if( i != playerid)
	    {
	        SendDeathMessageToPlayer(i, killerid, killee, reason);
	    }
	}
}

//------------------------------------------------------------------------------
// SendPlayerMessageToAllOthers(senderid, message[])
//
// This Function is used to force a particular player to send the message to all
// others except himself
//
// senderid: The Id of the player who will send the message
// message: The message which you want to send

stock SendPlayerMessageToAllOthers(senderid, message[])
{
	for( new i = 0; i <= MAX_PLAYERS; i++)
	{
	    if( i != senderid)
	    {
	        SendPlayerMessageToPlayer(i, senderid, message);
	    }
	}
}

//------------------------------------------------------------------------------
// SendPlayerMessageToAdmins(senderid,message[])
//
// This Function is used to force a particular id to send the message the Admins
//
// senderid: The Id of the Player who will send the Message
// message: The message which you want to send

stock SendPlayerMessageToAdmins(senderid,message[])
{
	for(new i = 0; i <= MAX_PLAYERS; i++)
	{
		if( IsPlayerAdmin(i) == true)
		{
			SendPlayerMessageToPlayer(i, senderid, message);
		}
	}
}

//------------------------------------------------------------------------------
// SendPlayerMessageToNonAdmins(senderid,message[])
//
// This Function is used to force a particular id to send the message to all
// who are not Admins
//
// senderid: The Id of the Player who will send the Message
// message: The message which you want to send

stock SendPlayerMessageToNonAdmins(senderid, message[])
{
	for(new i = 0; i <= MAX_PLAYERS; i++)
	{
		if( IsPlayerAdmin(i) == false)
		{
			SendPlayerMessageToPlayer(i, senderid, message);
		}
	}
}

//------------------------------------------------------------------------------
// SendClientMessageToAdmins(color, message[])
//
// This Function is used to send Message to all the Admins
//
// color: The Color of the Message
// message: The message which you want to send

stock SendClientMessageToAdmins(color, message[])
{
	for( new i = 0; i <= MAX_PLAYERS; i++)
	{
	    if( IsPlayerAdmin(i) == true)
	    {
	        SendClientMessage(i,color,message);
	    }
	}
}

//------------------------------------------------------------------------------
// SendClientMessageToNonAdmins(color, message[])
//
// This Function is used to send Message to all the players who are not Admins
//
// color: The Color of the Message
// message: The message which you want to send

stock SendClientMessageToNonAdmins(color, message[])
{
	for( new i = 0; i <= MAX_PLAYERS; i++)
	{
	    if( IsPlayerAdmin(i) == false)
	    {
	        SendClientMessage(i,color,message);
	    }
	}
}

//------------------------------------------------------------------------------
// SendDeathMessageToAdmins(killerid,killee,reason)
//
// This Function is used to send  death Message to the Admins
//
// killerid: The Id of the player who killed the player
// killee: The Id of the player who is killed
// reason: The reason for the Death

stock SendDeathMessageToAdmins( killerid, killee, reason)
{
	for( new i = 0; i<= MAX_PLAYERS; i++)
	{
	    if( IsPlayerAdmin(i)== true)
	    {
	        SendDeathMessageToPlayer(i, killerid, killee, reason);
	    }
	}
}

//------------------------------------------------------------------------------
// SendDeathMessageToNonAdmins(killerid,killee,reason)
//
// This Function is used to send  death Message to the players who are not Admins
//
// killerid: The Id of the player who killed the player
// killee: The Id of the player who is killed
// reason: The reason for the Death

stock SendDeathMessageToNonAdmins( killerid, killee, reason)
{
	for( new i = 0; i<= MAX_PLAYERS; i++)
	{
	    if( IsPlayerAdmin(i)== false)
	    {
	        SendDeathMessageToPlayer(i, killerid, killee, reason);
	    }
	}
}

//------------------------------------------------------------------------------
// SendDeathMessageToTeam(teamid,killerid,killee,reason)
//
// This Function is used to send  death Message to the members of a particular
// team
//
// teamid: The Id of the Team to which to the death message will be send
// killerid: The Id of the player who killed the player
// killee: The Id of the player who is killed
// reason: The reason for the Death

stock SendDeathMessageToTeam(teamid, killerid, killee, reason)
{
	for( new i = 0; i<= MAX_PLAYERS; i++)
	{
	    if( GetPlayerTeam(i) == teamid)
	    {
	        SendDeathMessageToPlayer(i, killerid, killee, reason);
	    }
	}
}

//------------------------------------------------------------------------------
// SendDeathMessageToOtherTeams(teamid,killerid,killee,reason)
//
// This Function is used to send  death Message to the members of a particular
// team
//
// teamid: The Id of the Team to which to the death message will not be send
// killerid: The Id of the player who killed the player
// killee: The Id of the player who is killed
// reason: The reason for the Death

stock SendDeathMessageToOtherTeams(teamid, killerid, killee, reason)
{
	for( new i = 0; i<= MAX_PLAYERS; i++)
	{
	    if( GetPlayerTeam(i) != teamid)
	    {
	        SendDeathMessageToPlayer(i, killerid, killee, reason);
	    }
	}
}

//------------------------------------------------------------------------------
// SendClientMessageToTeam(teamid, color, message[])
//
// This Function is used to send Message to the members of a particular team
//
// teamid: The Id of the Team to which to the message will be send
// color: The Color of the Message
// message: The message which you want to send

stock SendClientMessageToTeam(teamid, color, message[])
{
	for( new i = 0; i<= MAX_PLAYERS; i++)
	{
	    if( GetPlayerTeam(i) == teamid)
	    {
	    	SendClientMessage(i,color,message);
	    }
	}
}

//------------------------------------------------------------------------------
// SendClientMessageToOtherTeams(teamid, color, message[])
//
// This Function is used to send Message to the members of a particular team
//
// teamid: The Id of the Team to which to the message will not be send
// color: The Color of the Message
// message: The message which you want to send

stock SendClientMessageToOtherTeams(teamid, color, message[])
{
	for( new i = 0; i<= MAX_PLAYERS; i++)
	{
	    if( GetPlayerTeam(i) != teamid)
	    {
	    	SendClientMessage(i,color,message);
	    }
	}
}

//------------------------------------------------------------------------------
// SendPlayerMessageToTeam(senderid,teamid, message[])
//
// This Function is used to force a particular id to send the message to a whole
// Team
//
// senderid: The Id of the Player who will send the Message
// teamid: The Id of the Team to which to the message will be send
// message: The message which you want to send

stock SendPlayerMessageToTeam(senderid, teamid, message[])
{
	for(new i = 0; i <= MAX_PLAYERS; i++)
	{
		if( GetPlayerTeam)i) == teamid)
		{
			SendPlayerMessageToPlayer(i, senderid, message);
		}
	}
}

//------------------------------------------------------------------------------
// SendPlayerMessageToOtherTeams(senderid,teamid, message[])
//
// This Function is used to force a particular id to send the message to a whole
// Team
//
// senderid: The Id of the Player who will send the Message
// teamid: The Id of the Team to which to the message will not be send
// message: The message which you want to send

stock SendPlayerMessageToOtherTeams(senderid, teamid, message[])
{
	for(new i = 0; i <= MAX_PLAYERS; i++)
	{
		if( GetPlayerTeam)i) != teamid)
		{
			SendPlayerMessageToPlayer(i, senderid, message);
		}
	}
}

//------------------------------------------------------------------------------
