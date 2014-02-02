//EDHGame.cpp EDHGame definition
//Written by William Bittner

#pragma once
#include "EDHGame.h"
//#include "StandardGame.h"
//#include <iostream>
//#include <string>
//#include <gtk/gtk.h>
//#include "Player.h"
//using namespace std;


//Method called when the IncInfectButtonP1 is pressed
void IncCommP1(GtkWidget *widget, gpointer data)
{
	EDHGame::EDHPlayer1.ChangeComm(1);
	StandardGame::RecentPlays.append("Player 1 gained 1 comm \n");
	UpdateLabels();
	if(EDHGame::EDHPlayer1.Lost()&&!StandardGame::Continue)
	{
		EndGame(widget, data);
	}
}

//Method called when the IncInfectButtonP2 is pressed
void IncCommP2(GtkWidget *widget, gpointer data)
{
	EDHGame::EDHPlayer2.ChangeComm(1);
	StandardGame::RecentPlays.append("Player 2 gained 1 comm \n");
	UpdateLabels();
	if(EDHGame::EDHPlayer2.Lost()&&!StandardGame::Continue)
	{
		EndGame(widget, data);
	}
}
//Method called when the DecLifeButtonP1 is pressed
void DecCommP1(GtkWidget *widget, gpointer data)
{
	EDHGame::EDHPlayer1.ChangeComm(-1);
	StandardGame::RecentPlays.append("Player 1 lost 1 comm \n");
	UpdateLabels();
}

//Method called when the DecLifeButtonP2 is pressed
void DecCommP2(GtkWidget *widget, gpointer data)
{
	EDHGame::EDHPlayer2.ChangeComm(-1);
	StandardGame::RecentPlays.append("Player 2 lost 1 comm \n");
	UpdateLabels();
}

//--------------------------------------------------------------
//EDHGame methods
void EDHGame::CreateGameWindow()
{
	__super::CreateGameWindow();

	//set title
	gtk_window_set_title(GTK_WINDOW(Window), "EDH Game");
}

void EDHGame::CreateButtons()
{
	__super::CreateButtons();

	//add new buttons 
	//Increases player 1's comm by 1
	IncCommButtonP1 = gtk_button_new_with_label("Player1 +1 Comm");
	//Decreases player 1's comm by 1
	DecCommButtonP1 = gtk_button_new_with_label("Player1 -1 Comm");

	//Increases player 2's comm by 1
	IncCommButtonP2 = gtk_button_new_with_label("Player2 +1 Comm");
	//Decrease player 2's comm by 1
	DecCommButtonP2 = gtk_button_new_with_label("Player2 -1 Comm");
}
	
void EDHGame::ConnectSignalsToButtons()
{
	__super::ConnectSignalsToButtons();

	//Connect new buttons their functions
	gtk_signal_connect(GTK_OBJECT(IncCommButtonP1), "clicked", GTK_SIGNAL_FUNC(IncCommP1), NULL);
	gtk_signal_connect(GTK_OBJECT(DecCommButtonP1), "clicked", GTK_SIGNAL_FUNC(DecCommP1), NULL);
	gtk_signal_connect(GTK_OBJECT(IncCommButtonP2), "clicked", GTK_SIGNAL_FUNC(IncCommP2), NULL);
	gtk_signal_connect(GTK_OBJECT(DecCommButtonP2), "clicked", GTK_SIGNAL_FUNC(DecCommP2), NULL);
}

void EDHGame::CreateTableAndAddEverythingToIt(int y, int x)
{
	__super::CreateTableAndAddEverythingToIt(y,x);

	//Attach new buttons to table
	gtk_table_attach_defaults (GTK_TABLE (Table), IncCommButtonP1, 0, 1, 7, 8);
	gtk_table_attach_defaults (GTK_TABLE (Table), IncCommButtonP2, 2, 3, 7, 8);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecCommButtonP1, 0, 1, 8, 9);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecCommButtonP2, 2, 3, 8, 9);

	//Attach new labels to table
	gtk_table_attach_defaults (GTK_TABLE (Table), CommLabelP1, 0, 1, 9, 10);
	gtk_table_attach_defaults (GTK_TABLE (Table), CommLabelP2, 2, 3, 9, 10);
}

//EDHGame statics
EDHPlayer EDHGame::EDHPlayer1; 
EDHPlayer EDHGame::EDHPlayer2;
int EDHGame::edh;
GtkWidget* EDHGame::CommLabelP1;
GtkWidget* EDHGame::CommLabelP2;

//EDHGame Constuctor
EDHGame::EDHGame(int argc, char *argv[], EDHPlayer p1, EDHPlayer p2):StandardGame(argc,argv,p1,p2)
{
	EDHPlayer1 = p1;
	EDHPlayer2 = p2;
	edh = 1;

	
	//initialize labels
	string s = "Player1 Comm: ";
	CommLabelP1 = gtk_label_new(s.append(to_string((long double)(EDHPlayer1.Comm))).c_str());
	s = "Player2 Comm: ";
	CommLabelP2 = gtk_label_new(s.append(to_string((long double)(EDHPlayer2.Comm))).c_str());
	
}
