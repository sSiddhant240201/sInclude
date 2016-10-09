//------------------------------------------------------------------------------
// sUser Include v0.7
// by sSiddhant
//
// This Include belongs to the sInclude Library by sSiddhant. This Include is
// created by sSiddhant and consists of new Type of Functions and Callbacks
// related to User and its data. The List of Functions and Callbacks is given
// below
//
// Functions:
// GetUserName(playerid)
// GivePlayerReward(playerid,money,score,health,armour,weapon,wamount)
// TakePlayerMoney(playerid, money)
// GetPlayerSpeed(playerid)
// SetPlayerSpawnProtection(playerid, time, health)
// SetPlayerRealWorld(playerid)
//
// Callbacks
// OnSpawnProtectionEnd(playerid)
//
// (c) Copyright 2016, sSiddhant. All Rights Reserved.
//
//------------------------------------------------------------------------------

#if defined _sUser_included
  #endinput
#endif
#define _sUser_included
#tryinclude "a_samp"

#pragma library sInclude

#define MAX_INTERIORS 20

static
	shealth;

//------------------------------------------------------------------------------
// GetUserName(playerid)
//
// This Function is used to Get the Name of the Player
//
// playerid: The Id of the player whose name will be returned

stock GetUserName(playerid)
{
    new sname[MAX_PLAYER_NAME], string[24+MAX_PLAYER_NAME];
    GetPlayerName(playerid, sname, sizeof(sname));
    return sname;
}

//------------------------------------------------------------------------------
// SetPlayerSpawnProtection(playerid,time, health)
//
// This Function is used to Give Anti Spawn-Kill Protection to player.
// OnSpawnProtectionEnd(playerid) callback will be called after end of protection
// period
//
// playerid: The Id of the player who will recieve protection
// time: The time for which protection will be given in seconds
// health: Health of the player after expiry of Protection period, 0 if you want

stock SetPlayerSpawnProtection(playerid, time, health)
{
    SetPlayerHealth(playerid,99999);
    SetTimerEx("sKill", time, false, "i", playerid);
    shealth = health;
}

forward sKill(playerid);
public sKill(playerid)
{
	SetPlayerHealth(playerid,shealth);
	OnSpawnProtectionEnd(playerid);
}

//------------------------------------------------------------------------------
// OnSpawnProtectionEnd(playerid)
//
// This Callback is called when Spawn Protection period expires, which is given
// using SetPlayerSpawnProtection(playerid,time,health)
//
// playerid: The Id of the player who will recieve protection
// time: The time for which protection will be given in seconds
// health: Health of the player after expiry of Protection period

forward OnSpawnProtectionEnd(playerid);
public OnSpawnProtectionEnd(playerid)
{
	return 1;
}

//------------------------------------------------------------------------------
// SetPlayerVirtualWorld(playerid)
//
// This Function is used to make the player spawn in Real World
//
// playerid: The Id of the player who will spawn in real world

stock SetPlayerRealWorld(playerid)
{
	SetPlayerVirtualWorld(0);
}

//------------------------------------------------------------------------------
// TakePlayerMoney(playerid, money)
//
// This Function is used to take money from player
//
// playerid: The Id of the player whose name will be returned
// money: The amount of money to be taken away

stock TakePlayerMoney(playerid, money)
{
    GivePlayerMoney(playerid, -money);
}

//------------------------------------------------------------------------------
// GivePlayerReward(playerid,money,score,health,armour,weapon,wamount)
//
// This Function is used to Give Player various type of rewards
//
// playerid: The Id of the player who will recieve rewards
// money: The Money player will recieve, 0 for no money bonus
// score: Score the player will recieve, 0 for no score bonus
// health: Health the player will recieve, 0 for no health bonus
// armour: Armour the player will recieve, 0 for no armour bonus
// weapon: the id of the weapon which player will recieve, -1 for now weapon
// wamounr: the amount of the ammor recieve for the weapon, 0 if no weapon provided

stock GivePlayerReward(playerid,money,score,health,armour,weapon, wamount)
{
	GivePlayerMoney(playerid, money);
	SetPlayerScore(playerid, GetPlayerScore(playerid) + score);
	SetPlayerHealth(playerid, GetPlayerHealth(playerid)+ health);
	SetPlayerArmour(playerid, GetPlayerArmour(playerid) + armour);
	if( weapon1 != -1) GivePlayerWeapon(playerid, weapon, wamount);
}

//------------------------------------------------------------------------------
// GetPlayerSpeed(playerid)
//
// This Function is used to Get the Speed of the Player
//

stock GetPlayerSpeed(playerid)
{
    new Float:ST[4];
    if(IsPlayerInAnyVehicle(playerid))
    GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
    else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
    ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 179.28625;
    return floatround(ST[3]);
}

//------------------------------------------------------------------------------
