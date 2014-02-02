//StandardGame.cpp
//Written by William Bittner

#pragma once
#include "StandardGame.h"
//#include <string>
//#include <gtk/gtk.h>
//#include "Player.h"
//using namespace std;

//----------------------------------------------
//Methods that change depending on game type
void UpdateLabels()
{
	if(EDHGame::edh == 0/*not edh*/)
	{
		int i = StandardGame::Player1.Life;
		string s = "Player1 Life: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::LifeLabelP1), s.c_str());

		i = StandardGame::Player2.Life;
		s = "Player2 Life: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::LifeLabelP2), s.c_str());

		i = StandardGame::Player1.Infect;
		s = "Player1 Infect: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::InfectLabelP1), s.c_str());

		i = StandardGame::Player2.Infect;
		s = "Player2 Infect: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::InfectLabelP2), s.c_str());
	}
	else if (EDHGame::edh == 1 /*2 player edh*/)
	{
		int i = EDHGame::EDHPlayer1.Life;
		string s = "Player1 Life: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::LifeLabelP1), s.c_str());

		i = EDHGame::EDHPlayer2.Life;
		s = "Player2 Life: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::LifeLabelP2), s.c_str());

		i = EDHGame::EDHPlayer1.Infect;
		s = "Player1 Infect: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::InfectLabelP1), s.c_str());

		i = EDHGame::EDHPlayer2.Infect;
		s = "Player2 Infect: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::InfectLabelP2), s.c_str());

		i = EDHGame::EDHPlayer1.Comm;
		s = "Player1 Comm: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(EDHGame::CommLabelP1), s.c_str());

		i = EDHGame::EDHPlayer2.Comm;
		s = "Player2 Comm: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(EDHGame::CommLabelP2), s.c_str());
	}
	else if(EDHGame::edh == 2 /*3 player edh*/)
	{
		int i = EDHGame::EDHPlayer1.Life;
		string s = "Player1 Life: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::LifeLabelP1), s.c_str());

		i = EDHGame::EDHPlayer2.Life;
		s = "Player2 Life: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::LifeLabelP2), s.c_str());

		i = EDHGame::EDHPlayer1.Infect;
		s = "Player1 Infect: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::InfectLabelP1), s.c_str());

		i = EDHGame::EDHPlayer2.Infect;
		s = "Player2 Infect: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(StandardGame::InfectLabelP2), s.c_str());

		i = EDHGame::EDHPlayer1.Comm;
		s = "Player1 Comm: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(EDHGame::CommLabelP1), s.c_str());

		i = EDHGame::EDHPlayer2.Comm;
		s = "Player2 Comm: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(EDHGame::CommLabelP2), s.c_str());

		i = MultiPlayerEDHGame::EDHPlayer3.Life;
		s = "Player3 Life: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(MultiPlayerEDHGame::LifeLabelP3), s.c_str());

		i = MultiPlayerEDHGame::EDHPlayer3.Infect;
		s = "Player3 Infect: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(MultiPlayerEDHGame::InfectLabelP3), s.c_str());

		i = MultiPlayerEDHGame::EDHPlayer3.Comm;
		s = "Player3 Comm: ";
		s.append(to_string((long double)i));
		gtk_label_set_text(GTK_LABEL(MultiPlayerEDHGame::CommLabelP3), s.c_str());
	}
}

void ResetGame(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player1.ResetValues();
		StandardGame::Player2.ResetValues();
	}
	else if(EDHGame::edh == 1 /*2player edh*/)
	{
		EDHGame::EDHPlayer1.ResetValues();
		EDHGame::EDHPlayer2.ResetValues();
	}
	else if(EDHGame::edh == 2/*3player edh*/)
	{
		EDHGame::EDHPlayer1.ResetValues();
		EDHGame::EDHPlayer2.ResetValues();
		MultiPlayerEDHGame::EDHPlayer3.ResetValues();
	}

	StandardGame::Continue = false;
	StandardGame::RecentPlays = "";
	UpdateLabels();
}


//Method called when the IncLifeButtonP1 is pressed
void IncLifeP1(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player1.ChangeLife(1);
	}
	else if(EDHGame::edh == 1/*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer1.ChangeLife(1);
	}
	
	
	StandardGame::RecentPlays.append("Player 1 gained 1 life \n");
	UpdateLabels();
} 
//Method called when the IncLifeButtonP2 is pressed
void IncLifeP2(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player2.ChangeLife(1);
	}
	else if (EDHGame::edh == 1 /*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer2.ChangeLife(1);
	}
	StandardGame::RecentPlays.append("Player 2 gained 1 life \n");
	UpdateLabels();
} 
//Method called when the IncInfectButtonP1 is pressed
void IncInfectP1(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player1.ChangeInfect(1);
		if(StandardGame::Player1.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);	
		}
	}
	else if(EDHGame::edh == 1 /*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer1.ChangeInfect(1);
		if(EDHGame::EDHPlayer1.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);
		}
	}
	StandardGame::RecentPlays.append("Player 1 gained 1 infect \n");
	UpdateLabels();
} 
//Method called when the IncInfectButtonP2 is pressed
void IncInfectP2(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player2.ChangeInfect(1);
		if(StandardGame::Player2.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);
		}
	}
	else if(EDHGame::edh == 1 /*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer2.ChangeInfect(1);
		if(EDHGame::EDHPlayer2.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);
		}
	}
	
	StandardGame::RecentPlays.append("Player 2 gained 1 infect \n");
	UpdateLabels();
} 

//Method called when the DecLifeButtonP1 is pressed
void DecLifeP1(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player1.ChangeLife(-1);
		if(StandardGame::Player1.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);	
		}
	}
	else if(EDHGame::edh == 1 /*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer1.ChangeLife(-1);
		if(EDHGame::EDHPlayer1.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);
		}
	}
	
	StandardGame::RecentPlays.append("Player 1 lost 1 life \n");
	UpdateLabels();
} 
//Method called when the DecLifeButtonP2 is pressed
void DecLifeP2(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player2.ChangeLife(-1);
		if(StandardGame::Player2.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);	
		}
	}
	else if(EDHGame::edh == 1 /*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer2.ChangeLife(-1);
		if(EDHGame::EDHPlayer2.Lost()&&!StandardGame::Continue)
		{
			EndGame(widget, data);
		}
	}
	
	StandardGame::RecentPlays.append("Player 1 lost 1 life \n");
	UpdateLabels();
} 

//Method called when the DecInfectButtonP1 is pressed
void DecInfectP1(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player1.ChangeInfect(-1);
	}
	else if(EDHGame::edh == 1 /*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer1.ChangeInfect(-1);
	}
	StandardGame::RecentPlays.append("Player 1 lost 1 infect \n");
	UpdateLabels();
} 
//Method called when the DecInfectButtonP2 is pressed
void DecInfectP2(GtkWidget *widget, gpointer data)
{
	if(EDHGame::edh == 0 /*not edh*/)
	{
		StandardGame::Player2.ChangeInfect(-1);
	}
	else if(EDHGame::edh == 1 /*2player edh*/||EDHGame::edh == 2 /*3player edh*/)
	{
		EDHGame::EDHPlayer2.ChangeInfect(-1);
	}

	StandardGame::RecentPlays.append("Player 2 lost 1 infect \n");
	UpdateLabels();
} 

//-------------------------------------------------------------------------------------------
//Methods for buttons that don't change based on game type!
void destroy(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}

void RestartGame(GtkWidget *widget, gpointer data)
{
	ResetGame(widget, data);
	gtk_widget_destroy(widget->parent);
}

void EndGame(GtkWidget *widget, gpointer data)
{
	StandardGame::Continue = true;

	GtkWidget *window;
	GtkWidget *endGameButton;
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window), 200,100);
	gtk_window_set_title(GTK_WINDOW(window), "Restart Game?");
	endGameButton = gtk_button_new_with_label("Click this button to restart the game or close this window to continue playing");

	gtk_signal_connect(GTK_OBJECT(endGameButton), "clicked", GTK_SIGNAL_FUNC(RestartGame),NULL);
	gtk_container_add(GTK_CONTAINER(window), endGameButton);
	gtk_widget_show_all(window);
}

void RollDice(GtkWidget *widget, gpointer data)
{
	GtkWidget *window;
	GtkWidget *label;
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "Dice Roll");
	
	int i = rand()%20;
	string s = to_string((long double)i);

	label = gtk_label_new(s.c_str());

	gtk_container_add(GTK_CONTAINER(window), label);

	gtk_widget_show_all(window);
}

void ShowRecentPlays(GtkWidget *widget, gpointer data)
{
	GtkWidget *window;
	GtkWidget *label;
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	gtk_window_set_default_size(GTK_WINDOW(window),200,100);

	gtk_window_set_title(GTK_WINDOW(window), "Recent Plays");
	

	label = gtk_label_new(StandardGame::RecentPlays.c_str());

	gtk_container_add(GTK_CONTAINER(window), label);

	gtk_widget_show_all(window);
}

void CoinFlip(GtkWidget *widget, gpointer data)
{
	GtkWidget *window;
	GtkWidget *label;
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "Coin Flip");
	
	int i = rand()%2;
	string s;
	if(i == 1)
		s = "Heads";
	else
		s = "Tails";

	label = gtk_label_new(s.c_str());

	gtk_container_add(GTK_CONTAINER(window), label);

	gtk_widget_show_all(window);
}

void CreateToken(GtkWidget *widget, gpointer data)
{
	GtkWidget *window;
	GtkWidget *nameOfToken;
	GtkWidget *numberOfTokens;
	GtkWidget *table;

	nameOfToken = gtk_entry_new_with_max_length(25);
	numberOfTokens = gtk_entry_new_with_max_length(6);

	gtk_entry_set_text(GTK_ENTRY(nameOfToken),"Name of token");
	gtk_entry_set_text(GTK_ENTRY(numberOfTokens), "Number");
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "Token");

	table =  gtk_table_new(2,2,true);

	gtk_container_add(GTK_CONTAINER(window), table);

	gtk_table_attach_defaults(GTK_TABLE(table),nameOfToken,0,2,0,1);
	gtk_table_attach_defaults(GTK_TABLE(table),numberOfTokens,0,2,1,2);

	gtk_widget_show_all(window);
}
//--------------------------------------------------------------------------------
//Methods for StandardGame
void StandardGame::CreateGameWindow()
{
	//create window
	Window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	//set title
	gtk_window_set_title(GTK_WINDOW(Window), "Standard Game");

	//when given "destroy", destroy
	gtk_signal_connect (GTK_OBJECT (Window), "destroy", GTK_SIGNAL_FUNC (destroy), NULL);

	//Sets the border width of the window. 
	gtk_container_set_border_width (GTK_CONTAINER (Window), 10);
}

void StandardGame::CreateButtons()
{
	//Increases player 1's life by 1
	IncLifeButtonP1 = gtk_button_new_with_label("Player1 +1 Life");
	//Decrease player 1's life by 1
	DecLifeButtonP1 = gtk_button_new_with_label("Player1 -1 Life");
	//Increases player 1's infect by 1
	IncInfectButtonP1 = gtk_button_new_with_label("Player1 +1 Infect");
	//Decreases player 1's infect by 1
	DecInfectButtonP1 = gtk_button_new_with_label("Player1 -1 Infect");


	//Increases player 2's life by 1
	IncLifeButtonP2 = gtk_button_new_with_label("Player2 +1 Life");
	//Decrease player 2's life by 1
	DecLifeButtonP2 = gtk_button_new_with_label("Player2 -1 Life");
	//Increases player 2's infect by 1
	IncInfectButtonP2 = gtk_button_new_with_label("Player2 +1 Infect");
	//Decrease player 2's infect by 1
	DecInfectButtonP2 = gtk_button_new_with_label("Player2 -1 Infect");

	//Resets the game to default values
	ResetGameButton = gtk_button_new_with_label("Reset!");

	//Shows a window with heads or tails
	FlipCoinButton = gtk_button_new_with_label("Flip a coin!");

	//Shows a randum number 1-20
	RollDiceButton = gtk_button_new_with_label("Roll a D20!");

	//Shows a window with 2 texts fields - name of token and how many
	CreateTokenButton = gtk_button_new_with_label("Create a token!!");

	//Brings up a label containing all the of changes in stats since game started
	RecentPlaysButton = gtk_button_new_with_label("Show Recent Plays!");
}

void StandardGame::ConnectSignalsToButtons()
{
	//Connect misc. buttons
	gtk_signal_connect(GTK_OBJECT(FlipCoinButton), "clicked", GTK_SIGNAL_FUNC(CoinFlip), NULL);
	gtk_signal_connect(GTK_OBJECT(RollDiceButton), "clicked", GTK_SIGNAL_FUNC(RollDice), NULL);
	gtk_signal_connect(GTK_OBJECT(CreateTokenButton), "clicked", GTK_SIGNAL_FUNC(CreateToken), NULL);
	gtk_signal_connect(GTK_OBJECT(RecentPlaysButton), "clicked", GTK_SIGNAL_FUNC(ShowRecentPlays), NULL);

	//Connect stat buttons
	gtk_signal_connect(GTK_OBJECT(IncLifeButtonP1), "clicked", GTK_SIGNAL_FUNC(IncLifeP1), NULL);
	gtk_signal_connect(GTK_OBJECT(DecLifeButtonP1), "clicked", GTK_SIGNAL_FUNC(DecLifeP1), NULL);
	gtk_signal_connect(GTK_OBJECT(IncInfectButtonP1), "clicked", GTK_SIGNAL_FUNC(IncInfectP1), NULL);
	gtk_signal_connect(GTK_OBJECT(DecInfectButtonP1), "clicked", GTK_SIGNAL_FUNC(DecInfectP1), NULL);
	gtk_signal_connect(GTK_OBJECT(IncLifeButtonP2), "clicked", GTK_SIGNAL_FUNC(IncLifeP2), NULL);
	gtk_signal_connect(GTK_OBJECT(DecLifeButtonP2), "clicked", GTK_SIGNAL_FUNC(DecLifeP2), NULL);
	gtk_signal_connect(GTK_OBJECT(IncInfectButtonP2), "clicked", GTK_SIGNAL_FUNC(IncInfectP2), NULL);
	gtk_signal_connect(GTK_OBJECT(DecInfectButtonP2), "clicked", GTK_SIGNAL_FUNC(DecInfectP2), NULL);

	//Connect Misc buttons
	gtk_signal_connect(GTK_OBJECT(ResetGameButton), "clicked", GTK_SIGNAL_FUNC(ResetGame), NULL);
}

 void StandardGame::CreateTableAndAddEverythingToIt(int y, int x)
 {
	 //Create table!
	Table = gtk_table_new(y,x,true);

	//Add Table to window!
	gtk_container_add(GTK_CONTAINER(Window), Table);

	//Attach Stat Buttons to Table
	gtk_table_attach_defaults (GTK_TABLE (Table), IncLifeButtonP1, 0, 1, 0, 1);
	gtk_table_attach_defaults (GTK_TABLE (Table), IncLifeButtonP2, 2, 3, 0, 1);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecLifeButtonP1, 0, 1, 1, 2);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecLifeButtonP2, 2, 3, 1, 2);
	gtk_table_attach_defaults (GTK_TABLE (Table), IncInfectButtonP1, 0, 1, 2, 3);
	gtk_table_attach_defaults (GTK_TABLE (Table), IncInfectButtonP2, 2, 3, 2, 3);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecInfectButtonP1, 0, 1, 3, 4);
	gtk_table_attach_defaults (GTK_TABLE (Table), DecInfectButtonP2, 2, 3, 3, 4);

	//Attach Labels to Table
	gtk_table_attach_defaults (GTK_TABLE (Table), LifeLabelP1, 0, 1, 4, 5);
	gtk_table_attach_defaults (GTK_TABLE (Table), LifeLabelP2, 2, 3, 4, 5);
	gtk_table_attach_defaults (GTK_TABLE (Table), InfectLabelP1, 0, 1, 5, 6);
	gtk_table_attach_defaults (GTK_TABLE (Table), InfectLabelP2, 2, 3, 5, 6);

	//Attach Misc. Buttons to Table
	gtk_table_attach_defaults(GTK_TABLE (Table), ResetGameButton, 4, 5, 0, 1);
	gtk_table_attach_defaults(GTK_TABLE (Table), RollDiceButton, 4, 5, 2, 3);
	gtk_table_attach_defaults(GTK_TABLE (Table), FlipCoinButton, 4, 5, 4, 5);
	gtk_table_attach_defaults(GTK_TABLE (Table), CreateTokenButton, 4, 5, 6, 7);
	gtk_table_attach_defaults(GTK_TABLE (Table), RecentPlaysButton, 4, 5, 8, 9);
 }

 //Calls the 4 methods to make the GUI
 void StandardGame::MakeGUIAndDisplay(int y, int x)
 {
	CreateGameWindow();
	CreateButtons();
	ConnectSignalsToButtons();
	CreateTableAndAddEverythingToIt(y,x);

	//Show window and everything in it
	gtk_widget_show_all(Window);
		
	//sleeps, waiting for events 
	gtk_main ();
 }

//StandardGame statics
Player StandardGame::Player1;
Player StandardGame::Player2;
string StandardGame::RecentPlays;
bool StandardGame::Continue;
GtkWidget* StandardGame::LifeLabelP1;
GtkWidget* StandardGame::LifeLabelP2;
GtkWidget* StandardGame::InfectLabelP1;
GtkWidget* StandardGame::InfectLabelP2;

//StandardGame Constructor
StandardGame::StandardGame(int argc, char *argv[], Player p1, Player p2)
{
	//Assign players
	Player1 = p1;
	Player2 = p2;

	//Set continue so that the game can end(unless they choose not to, then it will no longer ask to end until they manually start a new game
	Continue = 0;

	//So that if an EDH game is played before this one, it wont think you are playing EDH in the methods
	EDHGame::edh = false;

	//Set recent plays to we can append the changes 
	RecentPlays = "";

	//initialize labels
	string s = "Player1 Life: ";
	LifeLabelP1 = gtk_label_new(s.append(to_string((long double)(Player1.Life))).c_str());
	s = "Player2 Life: ";
	LifeLabelP2 = gtk_label_new(s.append(to_string((long double)(Player2.Life))).c_str());
	s = "Player1 Infect: ";
	InfectLabelP1 = gtk_label_new(s.append(to_string((long double)(Player1.Infect))).c_str());
	s = "Player2 Infect: ";
	InfectLabelP2 = gtk_label_new(s.append(to_string((long double)(Player2.Infect))).c_str());

	//sets up all defaults for GTK
	gtk_init (&argc, &argv);
}