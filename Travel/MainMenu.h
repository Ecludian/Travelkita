#pragma once
#include "LoginMenu.h"
#include "OrderMenu.h"
#include "Finalization.h"
#include <stdlib.h>
void Loginmenu();

void mainMenu()
{
	system("cls");
	color(7, 0);
	int m = 2, ordermenu = 0;
	bool running = true;
	xy(58, 2); cout << "->";

	while(running)
	{
		xy(50, 0); cout << "=============================" << endl;
		xy(60, 1); cout << ">>MAIN MENU<<";
		xy(60, 2); cout << "1.Order";
		xy(60, 3); cout << "2.Log Out";
		xy(60, 4); cout << "3.Exit";
		xy(50, 5); cout << "=============================" << endl;
		system("pause>nul");


		if(GetAsyncKeyState(VK_DOWN) && m != 4)
		{
			xy(58, m); cout << "  ";
			m++;
			xy(58, m); cout << "->";
			ordermenu++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && m != 2)
		{
			xy(58, m); cout << "  ";
			m--;
			xy(58, m); cout << "->";
			ordermenu--;
			continue;
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch (ordermenu)
			{
			case 0:
				{
				orderMenu();
				break;
				}
			case 1:
				{
				system("cls");
				Loginmenu();
				break;
				}
			case 2:
				{
				xy(55, 10); cout << "Are you Sure Want to Exit?";
				exit(0);
				continue;
				}
			}
		}
	}
}