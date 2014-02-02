//EDHGame.h
//Written by William Bittner

#pragma once
#include "StandardGame.h"
//#include <gtk/gtk.h>
//#include <string>
#include "EDHPlayer.h"
//using namespace std;

//Method called when the IncInfectButtonP1 is pressed
void IncCommP1(GtkWidget *widget, gpointer data);

//Method called when the IncInfectButtonP2 is pressed
void IncCommP2(GtkWidget *widget, gpointer data);

//Method called when the DecLifeButtonP1 is pressed
void DecCommP1(GtkWidget *widget, gpointer data);

//Method called when the DecLifeButtonP2 is pressed
void DecCommP2(GtkWidget *widget, gpointer data);

struct EDHGame : StandardGame
{
	static EDHPlayer EDHPlayer1, EDHPlayer2;
	static int edh;
	static GtkWidget *CommLabelP1, *CommLabelP2;
	
	GtkWidget *IncCommButtonP1;
	GtkWidget *IncCommButtonP2;
	GtkWidget *DecCommButtonP1;
	GtkWidget *DecCommButtonP2;

	EDHGame(int argc, char *argv[], EDHPlayer p1, EDHPlayer p2);

	virtual void CreateGameWindow();
	virtual void CreateButtons();
	virtual void ConnectSignalsToButtons();
	virtual void CreateTableAndAddEverythingToIt(int y, int x);
};
#include "MultiPlayerEDHGame.h"