#pragma once
#include "MainMenu.h"

void Loginmenu()
{
	
	string user[5] = { "Labib", "Charel", "Fadel", "Alvina" };
	int pass[5] = { 6969, 1234, 12345, 123456 };
	extern string usera;
	int passa;
	int check = 0;
	int i;
login:
	color(7, 0);
	xy(57, 7); cout << "Travelnesia ver 1.0";
	xy(50, 0); cout << "=============================" << endl;
	xy(50, 5); cout << "=============================" << endl;
	xy(58, 1); cout << "<<Travelnesia>>";
	xy(58, 2); cout << "<<Login Page>>";
	xy(57, 3); cout << ">>Username : "; cin >> usera;
	
	for (i = 0; i < 5; i++)
	
	{
		if (user[i] == usera)
		{
			xy(57, 4); cout << ">>Password : "; cin >> passa;
			if (pass[i] == passa)
			{
				system("cls");
				check = 1;
				mainMenu();
				break;
			}
		}
	}
	if (check == 0)
	{
		system("cls");
		color(4, 0);
		xy(55, 10); cout << "Login Error, Try Again";
		goto login;
	}
	
}