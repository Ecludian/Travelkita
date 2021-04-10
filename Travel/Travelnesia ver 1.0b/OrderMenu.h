#pragma once
#include "LoginMenu.h"
#include "Agen.h"
#include <limits>
#include "Destination.h"
#include "Finalization.h"
void Final();
void orderMenu()
{
	bool EEONEDSCAN = true;
	bool running = true;
	int m = 4;
	int om = 0;
	system("cls");
	color(7, 0);
	extern int jmlPenumpang;//GLobal Value
	int x = 30, n = 3, crmenu = 0;
	xy(50, 1); cout << "=============================" << endl;
	xy(50, 9); cout << "=============================" << endl;
	xy(58, m); cout << "->";
	while (running)
	{
		xy(57, 2); cout << "<<Person>>";
		xy(57, 3); cout << "How Many?";
		xy(60, 4); cout << "1";
		xy(60, 5); cout << "2";
		xy(60, 6); cout << "3";
		xy(60, 7); cout << "4";
		xy(60, 8); cout << "5";
		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && m != 8)
		{
			xy(58, m); cout << "  ";
			m++;
			xy(58, m); cout << "->";
			om++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && m != 4)
		{
			xy(58, m); cout << "  ";
			m--;
			xy(58, m); cout << "->";
			om--;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (om)
			{
			case 0:
			{
				jmlPenumpang = 1;
				goto emitter;
			}
			case 1:
			{
				jmlPenumpang = 2;
				goto emitter;
			}
			case 2:
			{
				jmlPenumpang = 3;
				goto emitter;
			}
			case 3:
			{
				jmlPenumpang = 4;
				goto emitter;
			}
			case 4:
			{
				jmlPenumpang = 5;
				goto emitter;
			}
			}

		}

	}

emitter:
	system("cls");
	xy(50, 1); cout << "=============================" << endl;
	xy(50, 11); cout << "=============================" << endl;
	xy(55, 10); cout << "Fake GPS ver 0.5 beta";
	xy(55, 2); cout << "Getting Your Location";
	xy(48, 3); cout << "<>";
	xy(80, 3); cout << "<>";
	xy(50, 3);

	for (int i = 0; i < x; i++)
	{
		Sleep(250);
		color(2, 0);
		cout << char(219);
		if (i == 0)
		{
			EEONED();
		}
	}
	vector <string> Loc{ "Sleman", "Wonosari", "Bantul" };
	//string Loc[3] = { "Sleman", "Wonosari", "Bantul" };
	system("cls");
	srand(time(NULL));
	string crLoc = Loc[rand() % 3];
	color(7, 0);
	xy(58, n); cout << "->";
	while (EEONEDSCAN)
	{
		xy(50, 1); cout << "=============================" << endl; xy(50, 5); cout << "=============================" << endl;
		xy(50, 0); cout << "Your Current Location is: " << crLoc << endl;

		xy(60, 2); cout << "is it correct?";
		xy(60, 3); cout << "1.yes";
		xy(60, 4); cout << "2.no";
		system("pause>nul");


		if (GetAsyncKeyState(VK_DOWN) && n != 4)
		{
			xy(58, n); cout << "  ";
			n++;
			xy(58, n); cout << "->";
			crmenu++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && n != 3)
		{
			xy(58, n); cout << "  ";
			n--;
			xy(58, n); cout << "->";
			crmenu--;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (crmenu)
			{
			case 0:
			{
				system("cls");
				Destination();
				break;
			}
			case 1:

			{
				system("cls");
				goto emitter;
				break;
			}
			}
		}
	}
}

	

