//EDHPlayer.h - EDHPlayer declaration
//Written by William Bittner

#pragma once
#include "Player.h"
#define EDH_STARTING_LIFE 40
#define STARTING_COMMANDER 0
#define ENDING_COMMANDER 21


struct EDHPlayer : public Player
{
	int Comm;

	EDHPlayer(int life=EDH_STARTING_LIFE, int infect=STARTING_INFECT, int commanderDamage = STARTING_COMMANDER);

	int ChangeComm(int i);

	bool Lost() const;

	void ResetValues();
};