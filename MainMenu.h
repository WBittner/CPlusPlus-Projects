//MainMenu.h - header file for main menu GUI
//Written by William Bittner

#pragma once
#include "StandardGame.h"
#include "MultiPlayerEDHGame.h"

void NewStandardGame(GtkWidget *widget, gpointer data);

void NewEDHGame(GtkWidget *widget, gpointer data);

struct MainMenu
{
	//GTK Widet is the storage type for widgetse
	GtkWidget *Window;
	GtkWidget *Standard;
	GtkWidget *Edh;
	GtkWidget *MultiEdh;
	GtkWidget *Table;
	static int Argc;
	static char *Argv[];
	

	MainMenu(int Argc, char *Argv[]);
	
	void CreateAndDisplayMainMenuGui();
};