//MultiPlayerEDHGame.h
//Written by William Bittner

#pragma once
#include "EDHGame.h"

//Method called when the IncCommButtonP3 is pressed
void IncCommP3(GtkWidget *widget, gpointer data);

//Method called when the DecCommButtonP3 is pressed
void DecCommP3(GtkWidget *widget, gpointer data);

//Method called when the IncLifeButtonP3 is pressed
void IncLifeP3(GtkWidget *widget, gpointer data);

//Method called when the DecLifeButtonP3 is pressed
void DecLife3(GtkWidget *widget, gpointer data);

//Method called when the IncInfectButtonP3 is pressed
void IncInfectP3(GtkWidget *widget, gpointer data);

//Method called when the DecInfectButtonP3 is pressed
void DecInfectP3(GtkWidget *widget, gpointer data);

struct MultiPlayerEDHGame : EDHGame
{
	static EDHPlayer EDHPlayer3;
	static GtkWidget *CommLabelP3, *InfectLabelP3, *LifeLabelP3;
	
	GtkWidget *IncCommButtonP3;
	GtkWidget *DecCommButtonP3;
	GtkWidget *IncLifeButtonP3;
	GtkWidget *DecLifeButtonP3;
	GtkWidget *IncInfectButtonP3;
	GtkWidget *DecInfectButtonP3;

	MultiPlayerEDHGame(int argc, char *argv[], EDHPlayer p1, EDHPlayer p2, EDHPlayer p3);

	virtual void CreateGameWindow();
	virtual void CreateButtons();
	virtual void ConnectSignalsToButtons();
	virtual void CreateTableAndAddEverythingToIt(int y, int x);
};