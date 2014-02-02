//EDHGame.cpp EDHGame definition
//Written by William Bittner

#pragma once
#include "MultiPlayerEDHGame.h"
//#include "StandardGame.h"
//#include <iostream>
//#include <string>
//#include <gtk/gtk.h>
//#include "Player.h"
//using namespace std;


//Method called when the IncInfectButtonP1 is pressed
void IncCommP3(GtkWidget *widget, gpointer data)
{
	MultiPlayerEDHGame::EDHPlayer3.ChangeComm(1);
	StandardGame::RecentPlays.append("Player 3 gained 1 comm \n");
	UpdateLabels();
	if(MultiPlayerEDHGame::EDHPlayer3.Lost()&&!StandardGame::Continue)
	{
		EndGame(widget, data);
	}
}

//Method called when the DecLifeButtonP1 is pressed
void DecCommP3(GtkWidget *widget, gpointer data)
{
	MultiPlayerEDHGame::EDHPlayer3.ChangeComm(-1);
	StandardGame::RecentPlays.append("Player 3 lost 1 comm \n");
	UpdateLabels();
}

//Method called when the DecLifeButtonP2 is pressed
void IncLifeP3(GtkWidget *widget, gpointer data)
{
	MultiPlayerEDHGame::EDHPlayer3.ChangeLife(1);
	StandardGame::RecentPlays.append("Player 3 gained 1 life \n");
	UpdateLabels();
}

//Method called when the DecLifeButtonP2 is pressed
void DecLifeP3(GtkWidget *widget, gpointer data)
{
	MultiPlayerEDHGame::EDHPlayer3.ChangeLife(-1);
	StandardGame::RecentPlays.append("Player 3 lost 1 life \n");
	UpdateLabels();
	if(MultiPlayerEDHGame::EDHPlayer3.Lost()&&!StandardGame::Continue)
	{
		EndGame(widget, data);
	}
}

//Method called when the DecLifeButtonP2 is pressed
void DecInfectP3(GtkWidget *widget, gpointer data)
{
	MultiPlayerEDHGame::EDHPlayer3.ChangeInfect(-1);
	StandardGame::RecentPlays.append("Player 3 lost 1 infect \n");
	UpdateLabels();
}

//Method called when the DecLifeButtonP2 is pressed
void IncInfectP3(GtkWidget *widget, gpointer data)
{
	MultiPlayerEDHGame::EDHPlayer3.ChangeInfect(1);
	StandardGame::RecentPlays.append("Player 3 gained 1 infect \n");
	UpdateLabels();
	if(MultiPlayerEDHGame::EDHPlayer3.Lost()&&!StandardGame::Continue)
	{
		EndGame(widget, data);
	}
}

//--------------------------------------------------------------
//MultiPlayerEDHGame methods
void MultiPlayerEDHGame::CreateGameWindow()
{
	__super::CreateGameWindow();

	//set title
	gtk_window_set_title(GTK_WINDOW(Window), "3 Player EDH Game");
}

void MultiPlayerEDHGame::CreateButtons()
{
	__super::CreateButtons();

	//add new buttons 
	//Increases player 1's comm by 1
	IncCommButtonP3 = gtk_button_new_with_label("Player3 +1 Comm");
	//Decreases player 1's comm by 1
	DecCommButtonP3 = gtk_button_new_with_label("Player3 -1 Comm");

	//Increases player 2's comm by 1
	IncLifeButtonP3 = gtk_button_new_with_label("Player3 +1 Life");
	//Decrease player 2's comm by 1
	DecLifeButtonP3 = gtk_button_new_with_label("Player3 -1 Life");

	//Increases player 2's comm by 1
	IncInfectButtonP3 = gtk_button_new_with_label("Player3 +1 Infect");
	//Decrease player 2's comm by 1
	DecInfectButtonP3 = gtk_button_new_with_label("Player3 -1 Infect");
}
	
void MultiPlayerEDHGame::ConnectSignalsToButtons()
{
	__super::ConnectSignalsToButtons();

	//Connect new buttons their functions
	gtk_signal_connect(GTK_OBJECT(IncCommButtonP3), "clicked", GTK_SIGNAL_FUNC(IncCommP3), NULL);
	gtk_signal_connect(GTK_OBJECT(DecCommButtonP3), "clicked", GTK_SIGNAL_FUNC(DecCommP3), NULL);
	gtk_signal_connect(GTK_OBJECT(IncLifeButtonP3), "clicked", GTK_SIGNAL_FUNC(IncLifeP3), NULL);
	gtk_signal_connect(GTK_OBJECT(DecLifeButtonP3), "clicked", GTK_SIGNAL_FUNC(DecLifeP3), NULL);
	gtk_signal_connect(GTK_OBJECT(IncInfectButtonP3), "clicked", GTK_SIGNAL_FUNC(IncInfectP3), NULL);
	gtk_signal_connect(GTK_OBJECT(DecInfectButtonP3), "clicked", GTK_SIGNAL_FUNC(DecInfectP3), NULL);
}

void MultiPlayerEDHGame::CreateTableAndAddEverythingToIt(int y, int x)
{
	__super::CreateTableAndAddEverythingToIt(y,x);

	//Attach new buttons to table
	gtk_table_attach_defaults (GTK_TABLE (Table), IncLifeButtonP3, 6, 7, 0, 1);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecLifeButtonP3, 6, 7, 1, 2);
	gtk_table_attach_defaults (GTK_TABLE (Table), IncInfectButtonP3, 6, 7, 2, 3);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecInfectButtonP3, 6, 7, 3, 4);
	gtk_table_attach_defaults (GTK_TABLE (Table), IncCommButtonP3, 6, 7, 7, 8);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecCommButtonP3, 6, 7, 8, 9);

	//Attach new labels to table
	gtk_table_attach_defaults (GTK_TABLE (Table), LifeLabelP3, 6, 7, 4, 5);
	gtk_table_attach_defaults (GTK_TABLE (Table), InfectLabelP3, 6, 7, 5, 6);
	gtk_table_attach_defaults (GTK_TABLE (Table), CommLabelP3, 6, 7, 9, 10);
}

//EDHGame statics
EDHPlayer MultiPlayerEDHGame::EDHPlayer3;
GtkWidget* MultiPlayerEDHGame::CommLabelP3;
GtkWidget* MultiPlayerEDHGame::LifeLabelP3;
GtkWidget* MultiPlayerEDHGame::InfectLabelP3;

//MultiPlayerEDHGame Constuctor
MultiPlayerEDHGame::MultiPlayerEDHGame(int argc, char *argv[], EDHPlayer p1, EDHPlayer p2, EDHPlayer p3):EDHGame(argc,argv,p1,p2)
{
	EDHPlayer3 = p3;
	edh = 2;

	
	//initialize labels
	string s = "Player3 Comm: ";
	CommLabelP3 = gtk_label_new(s.append(to_string((long double)(EDHPlayer3.Comm))).c_str());
	s = "Player3 Life: ";
	LifeLabelP3 = gtk_label_new(s.append(to_string((long double)(EDHPlayer3.Life))).c_str());
	s = "Player3 Infect: ";
	InfectLabelP3 = gtk_label_new(s.append(to_string((long double)(EDHPlayer3.Infect))).c_str());
}
