#pragma once
#include <fstream>
#include "MainMenu.h"
#include "OrderMenu.h"
void Total();
void orderMenu();
void EE_ONE_D();
int jmlPenumpang;
void Final() {
	
	char alamat[90];
	bool final = true;
	int m = 2, fmenu = 0;
	xy(58, 2); cout << "->";

	while(final)
	{
		xy(50, 0); cout << "=============================" << endl;
		xy(52, 1); cout << "Choose Methode" << endl;
		xy(60, 2); cout << "1. Pick Up" << endl;
		xy(60, 3); cout << "2. Go to Agent" << endl;
		xy(50, 4); cout << "=============================" << endl;

		system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) &&  m != 3)
		{
		xy(58, m); cout << "  ";
		m++;
		xy(58, m); cout << "->";
		fmenu++;
		continue;
		}
		if(GetAsyncKeyState(VK_UP) && m != 2)
			{
			xy(58, m); cout << "  ";
			m--;
			xy(58, m); cout << "->";
			fmenu--;
			continue;
			}
		if(GetAsyncKeyState(VK_RETURN))
			{
			switch(fmenu)
			{
			case 0:
				{
				cin.clear();
				cin.ignore();
				xy(50, 5); cout << "Input Pick Up Address : ";
				cin.getline(alamat, 90);
				ofstream address("Address.txt");
				address << alamat;
				address.close();
				kaching();
				Total();
				break;
				}
			case 1:
				{
				kaching();
				Total();
				break;
				}
			}
		}
	}

}
