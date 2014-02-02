//MainMenu.cpp - MainMenu definition
//Written by William Bittner

#include "MainMenu.h"

void NewStandardGame(GtkWidget *widget, gpointer data)
{
	Player Player1, Player2;
	StandardGame(MainMenu::Argc, NULL, Player1, Player2).MakeGUIAndDisplay(9,5);
}

void NewEDHGame(GtkWidget *widget, gpointer data)
{
	EDHPlayer Player1, Player2;
	EDHGame(MainMenu::Argc, NULL, Player1, Player2).MakeGUIAndDisplay(11,5);
}

void NewMultiEDHGame(GtkWidget *widget, gpointer data)
{
	EDHPlayer Player1, Player2, Player3;
	MultiPlayerEDHGame(MainMenu::Argc, NULL, Player1, Player2, Player3).MakeGUIAndDisplay(11,7);
}

void MainMenu::CreateAndDisplayMainMenuGui()
{
	//create window
	Window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(Window), "William Bittner's Magic: The Gathering Life Tracker!");
	gtk_window_set_default_size(GTK_WINDOW(Window),400,200);

	//when given "destroy", destroy
	gtk_signal_connect (GTK_OBJECT (Window), "destroy", GTK_SIGNAL_FUNC (destroy), NULL);

	//Sets the border width of the window. 
	gtk_container_set_border_width (GTK_CONTAINER (Window), 10);

	//Create new button!
	Standard = gtk_button_new_with_label("New Standard Game!");

	//called function hello when clicked
	gtk_signal_connect(GTK_OBJECT(Standard), "clicked", GTK_SIGNAL_FUNC(NewStandardGame), NULL);

	//Create new button!
	Edh = gtk_button_new_with_label("New EDH Game!");

	//called function hello when clicked
	gtk_signal_connect(GTK_OBJECT(Edh), "clicked", GTK_SIGNAL_FUNC(NewEDHGame), NULL);

	//Create new button!
	MultiEdh = gtk_button_new_with_label("New 3 Player EDH Game!");

	//called function hello when clicked
	gtk_signal_connect(GTK_OBJECT(MultiEdh), "clicked", GTK_SIGNAL_FUNC(NewMultiEDHGame), NULL);

	Table = gtk_table_new(3,2,true);

	//add table to window
	gtk_container_add(GTK_CONTAINER(Window), Table);

	//add buttons to table
	gtk_table_attach_defaults (GTK_TABLE(Table), Standard, 0,2,0,1);
	gtk_table_attach_defaults (GTK_TABLE(Table), Edh, 0,2,1,2);
	gtk_table_attach_defaults (GTK_TABLE(Table), MultiEdh, 0,2,2,3);

	//display window
	gtk_widget_show_all  (Window);

	//sleeps, waiting for events 
	gtk_main ();
}

int MainMenu::Argc;
//char MainMenu::Argv;

MainMenu::MainMenu(int argc, char *argv[])
{
	Argc = argc;
	//sets up all defaults
	gtk_init (&argc, &argv);
    
}