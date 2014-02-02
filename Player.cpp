//Player.cpp - definition for Player class
//Written by William Bittner

#include "Player.h"

Player::Player(int life/*=STARTING_LIFE*/, int infect/*=STARTING_INFECT*/)
{
	//Set Initial Parameters
	Life = life;
	Infect = infect;
}

int Player::ChangeLife(int i)
{
	Life+=i;
	return Life;
}

int Player::ChangeInfect(int i)
{
	Infect+=i;
	return Infect;
}

bool Player::Lost() const
{
	return(Infect>=ENDING_INFECT)||(Life<=ENDING_LIFE);
}

void Player::ResetValues()
{
	Life = STARTING_LIFE;
	Infect = STARTING_INFECT;
}