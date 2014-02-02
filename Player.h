//Player.h - class declaration
//Written by William Bittner

#pragma once
#define STARTING_LIFE 20
#define STARTING_INFECT 0
#define ENDING_LIFE 0
#define ENDING_INFECT 10

struct Player
{
	int Life, Infect;

	Player(int life=STARTING_LIFE, int infect=STARTING_INFECT);

	int ChangeLife(int i);

	int ChangeInfect(int i);

	virtual bool Lost() const;

	virtual void ResetValues();
};