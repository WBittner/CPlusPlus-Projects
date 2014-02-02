//EDHPlayer.cpp - definition for Player class
//Written by William Bittner

#include "EDHPlayer.h"

EDHPlayer::EDHPlayer(int life/*=EDH_STARTING_LIFE*/, int infect/*=STARTING_INFECT*/, int commanderDamage/* = STARTING_COMMANDER*/) : Player(life,infect)
{
	Comm = commanderDamage;
}
int EDHPlayer::ChangeComm(int i)
{
	Comm+=i;
	return Comm;
}

bool EDHPlayer::Lost() const
{
	return (Comm>=ENDING_COMMANDER)||(__super::Lost())/*(Infect>=ENDING_INFECT)||(Life<=ENDING_LIFE)*/;
}

void EDHPlayer::ResetValues()
{
	Infect = STARTING_INFECT;
	Comm = STARTING_COMMANDER;
	Life = EDH_STARTING_LIFE;
}