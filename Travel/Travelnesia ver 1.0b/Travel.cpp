//core
#include "CursorController.h"
#include "SoundController.h"
#include "xcurse.h"
#include "LoginMenu.h"
#include "OrderMenu.h"
#include "MainMenu.h"
#include "Destination.h"
#include "Agen.h"
#include "Finalization.h"

using namespace std;

int main()
{
		hidecursor();
		Loginmenu();
		orderMenu();
	return 0;
}
void Total()
{
	system("start /min notepad /p Bill.txt");
	int counter = 5;
	color(2, 0);
	xy(57, 7); cout << "ORDER COMPLETED" << endl;
	color(4, 0);
	while(counter >= 1)
	{
		xy(50, 8); cout << "you will return to Main Menu in " << counter;
		Sleep(1000);
		counter--;
	}
	
	mainMenu();
}