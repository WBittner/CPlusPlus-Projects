//StandardGame.h 
//Written by William Bittner

#pragma once
#include <gtk/gtk.h>
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;



//-------------------------------------------------------
//METHODS TO SET TO BUTTONS
void destroy(GtkWidget *widget, gpointer data);

//Called after every change in score - updates the labels to their correct text.
void UpdateLabels();

void RestartGame(GtkWidget *widget, gpointer data);

void CoinFlip(GtkWidget *widget, gpointer data);

void EndGame(GtkWidget *widget, gpointer data);

void CreateToken(GtkWidget *widget, gpointer data);

void ResetGame(GtkWidget *widget, gpointer data);

void RollDice(GtkWidget *widget, gpointer data);

void ShowRecentPlays(GtkWidget *widget, gpointer data);

//Method called when the IncLifeButtonP1 is pressed
void IncLifeP1(GtkWidget *widget, gpointer data);

//Method called when the IncLifeButtonP2 is pressed
void IncLifeP2(GtkWidget *widget, gpointer data);

//Method called when the IncInfectButtonP1 is pressed
void IncInfectP1(GtkWidget *widget, gpointer data);

//Method called when the IncInfectButtonP2 is pressed
void IncInfectP2(GtkWidget *widget, gpointer data);

//Method called when the DecLifeButtonP1 is pressed
void DecLifeP1(GtkWidget *widget, gpointer data);

//Method called when the DecLifeButtonP2 is pressed
void DecLifeP2(GtkWidget *widget, gpointer data);

//Method called when the DecInfectButtonP1 is pressed
void DecInfectP1(GtkWidget *widget, gpointer data);

//Method called when the DecInfectButtonP2 is pressed
void DecInfectP2(GtkWidget *widget, gpointer data);

//-----------------------
//StandardGame Class
struct StandardGame
{
	
	static Player Player1, Player2;
	static string RecentPlays;
	static bool Continue;
	static GtkWidget *LifeLabelP1, *LifeLabelP2, *InfectLabelP1, *InfectLabelP2;
	

	GtkWidget *Window;
	GtkWidget *Table;

	GtkWidget *IncLifeButtonP1;
	GtkWidget *IncLifeButtonP2;

	GtkWidget *DecLifeButtonP1;
	GtkWidget *DecLifeButtonP2;

	GtkWidget *IncInfectButtonP1;
	GtkWidget *IncInfectButtonP2;

	GtkWidget *DecInfectButtonP1;
	GtkWidget *DecInfectButtonP2;

	GtkWidget *ResetGameButton;
	GtkWidget *FlipCoinButton;
	GtkWidget *RollDiceButton;
	GtkWidget *CreateTokenButton;
	GtkWidget *RecentPlaysButton;

	StandardGame(int argc, char *argv[], Player p1, Player p2);

	virtual void CreateGameWindow();

	virtual void CreateButtons();
	
	virtual void ConnectSignalsToButtons();

	virtual void CreateTableAndAddEverythingToIt(int x, int y);

	void MakeGUIAndDisplay(int y, int x);
};

//If move to top, errors(cant find StandardGame, in EDHGame, because defined at the top
#include "EDHGame.h"