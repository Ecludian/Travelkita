#pragma once
#include "Agen.h"
void mainMenu();

void Destination()
{
	int dstmenu = 0, m  = 2;
	bool dst = true;
	xy(58, 2); cout << "->";
	while(dst)
	{
		xy(50, 0); cout << "=============================" << endl;
		xy(50, 7); cout << "=============================" << endl;
		xy(55, 1); cout << "Choose Destination: " << endl;
		xy(60, 2); cout << "1. Bandung " << endl;
		xy(60, 3); cout << "2. Jakarta " << endl;
		xy(60, 4); cout << "3. Surabaya " << endl;
		xy(60, 5); cout << "4. Semarang " << endl;
		xy(60, 6); cout << "5. Cancel" << endl;
		
		system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && m != 6)
		{
			xy(58, m); cout << "  ";
			m++;
			xy(58, m); cout << "->";
			dstmenu++;
			continue;
		}
		if(GetAsyncKeyState(VK_UP)&& m != 1)
		{
			xy(58, m); cout << "  ";
			m--;
			xy(58, m); cout << "->";
			dstmenu--;
			continue;
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch(dstmenu)
			{
			case 0:
				{
				system("cls");
				Bandung();
				break;
				}
			case 1:
				{
				system("cls");
				Jakarta();
				break;
				}
			case 2:
				{
				system("cls");
				Surabaya();
				break;
				}
			case 3:
				{
				system("cls");
				Semarang();
				break;
				}
			case 4:
				{
				system("cls");
				mainMenu();
				break;
				}
			}
		}
	}
}