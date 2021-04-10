#pragma once
#include "OrderMenu.h"
#include "Finalization.h"
#include <fstream>
#include <chrono>
void Destination();
string usera;
string alamat;
class TravelAgent
{
public:

	void setData(string cname, int p, string dtime)
	{
		company_name = cname;
		price = p;
		departTime = dtime;
	}


	void displayData()
	{
		xy(55, 0); cout << "CONFIRMATION ORDER" << endl;
		xy(55, 1); cout << "Agent Name : " << company_name << endl;
		xy(55, 2); cout << "Price : "<< "Rp" << price << endl;
		xy(55, 3); cout << "Time of Departure : " << departTime << endl;
		
	}

public:
	string company_name;
	string departTime;
	int price;
	
	
	//use for serialization and deserialization
	//use to read and write object
	bool operator == (const TravelAgent & obj)
	{
		return (company_name == obj.company_name) && (departTime == obj.departTime) && (price == obj.price);
	}

	friend ostream & operator << (ostream &out, const TravelAgent & obj)
	{
		out << "<<               Travelnesia                  >>" << "\n";
		out << "<<------------------------------------->>" << "\n";
		out <<"Travel Agent : " << obj.company_name << "\n" << "Time of Departure : " << obj.departTime << "\n"<< "Price : "<< "Rp"<< obj.price << endl;
		out << "on the Name of : " << usera << "\n";
		out << "Valid for Tomorrow" << "\n";
		out << "<<------------------------------------->>" <<"\n";
		out << "Thank you for using our Service" << endl;
		return out;
	}

	friend istream & operator >> (istream &in, TravelAgent & obj)
	{
		in >> obj.company_name;
		in >> obj.departTime;
		in >> obj.price;
		return in;
	}
};


void Bandung()
{
	
	//agent Data
	TravelAgent Pagent1,Pagent2,Pagent3,Pagent4,Fagent1,Fagent2,Fagent3,Fagent4;
	Pagent1.setData("Pembawa Malam", jmlPenumpang * 185000, "05:00 WIB");
	Pagent2.setData("Pembawa Malam", jmlPenumpang *185000, "10:00 WIB");
	Pagent3.setData("Pembawa Malam", jmlPenumpang * 185000, "14:00 WIB");
	Pagent4.setData("Pembawa Malam", jmlPenumpang * 185000, "21:00 WIB");
	Fagent1.setData("First Travel", jmlPenumpang * 190000, "05:00 WIB");
	Fagent2.setData("First Travel", jmlPenumpang * 190000, "10:00 WIB");
	Fagent3.setData("First Travel", jmlPenumpang * 190000, "14:00 WIB");
	Fagent4.setData("First Travel", jmlPenumpang * 190000, "21:00 WIB");
	int agmenu = 0, m = 2, n = 3,o = 6, agcmenu = 0, conmenu = 0;
	bool agt = true;
	bool con = true;
	string AgentData;
	
menuagen:
	xy(53, m); cout << "->";
	while (agt)
	{
		xy(50, 0); cout << "=============================" << endl;
		xy(60, 1); cout << "Bandung\n";
		xy(55, 2); cout << "1.Pembawa Malam\n";
		xy(55, 3); cout << "2.First Travel\n";
		xy(55, 4); cout << "3.Back";
		xy(50, 5); cout << "=============================" << endl;
		system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && m != 4)
		{
			xy(53, m); cout << "  ";
			m++;
			xy(53, m); cout << "->";
			agmenu++;
			continue;
		}
		if(GetAsyncKeyState(VK_UP) && m != 2)
		{
			xy(53, m); cout << "  ";
			m--;
			xy(53, m); cout << "->";
			agmenu--;
			continue;
		}
		if(GetAsyncKeyState(VK_RETURN))
		{
			switch(agmenu)
			{
			case 0:
				{
				system("cls");
			menujam:
				color(7, 0);
				xy(53, n); cout << "->";
				while(agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "Pembawa Malam\n";
					xy(55, 2); cout << "Rp 185.000\n";
					xy(55, 3); cout << "1. 05.00 WIB\n";
					xy(55, 4); cout << "2. 10.00 WIB\n";
					xy(55, 5); cout << "3. 14.00 WIB\n";
					xy(55, 6); cout << "4. 21.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");
					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if(GetAsyncKeyState(VK_RETURN))
					{
						switch(agcmenu)
						{
						case 0 :
							{
							system("cls");
							Pagent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
										{
										ofstream out("Bill.txt");
										out << Pagent1;
										out.close();
										system("cls");
										Final();
										break;
										}
									case 1:
										{
										system("cls");
										goto menujam;
										}
									}
								}
							}
							}
						case 1:
							{
							system("cls");
							Pagent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pagent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
							}
						case 2:
							{
							system("cls");
							Pagent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53,o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pagent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
							}
						case 3:
							{
							system("cls");
							Pagent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pagent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
							}
						case 4:
							{
							system("cls");
							goto menuagen;
							break;
							}
						}
					}
					
					
				}
				
				}
			case 1:
				{
			menujam2:
				system("cls");
				xy(53, n); cout << "->";
				while (agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "First Travel\n";
					xy(55, 2); cout << "Rp 190.000\n";
					xy(55, 3); cout << "1. 05.00 WIB\n";
					xy(55, 4); cout << "2. 10.00 WIB\n";
					xy(55, 5); cout << "3. 14.00 WIB\n";
					xy(55, 6); cout << "4. 21.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");
					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						switch (agcmenu)
						{
						case 0:
						{
							system("cls");
							Fagent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent1;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 1:
						{
							system("cls");
							Fagent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 2:
						{
							system("cls");
							Fagent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 3:
						{
							system("cls");
							Fagent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 4:
						{
							system("cls");
							goto menuagen;
							break;
						}
						}
					}
					
				}
				}
			case 2:
				{
				system("cls");
				Destination();
				
				}
			}
		}
	}
	
}
void Jakarta()
{

	TravelAgent Jagent1, Jagent2, Jagent3, Jagent4, Pjagent1, Pjagent2, Pjagent3, Pjagent4;
	Jagent1.setData("Puspa Jaya", jmlPenumpang * 200000, "08:00 WIB");
	Jagent2.setData("Puspa Jaya", jmlPenumpang * 200000, "11:00 WIB");
	Jagent3.setData("Puspa Jaya", jmlPenumpang * 200000, "14:00 WIB");
	Jagent4.setData("Puspa Jaya", jmlPenumpang * 200000, "20:00 WIB");
	Pjagent1.setData("First Travel", jmlPenumpang * 195000, "04:00 WIB");
	Pjagent2.setData("First Travel", jmlPenumpang * 195000, "10:00 WIB");
	Pjagent3.setData("First Travel", jmlPenumpang * 195000, "12:00 WIB");
	Pjagent4.setData("First Travel", jmlPenumpang * 195000, "14:00 WIB");
	int agmenu = 0, m = 2, n = 3,o = 6, agcmenu = 0, conmenu = 0;
	bool agt = true;
	bool con = true;
menuagen:
	xy(53, m); cout << "->";
	while (agt)
	{
		xy(50, 0); cout << "=============================" << endl;
		xy(60, 1); cout << "Jakarta\n";
		xy(55, 2); cout << "1.Puspa Jaya\n";
		xy(55, 3); cout << "2.First Travel\n";
		xy(55, 4); cout << "3.Back";
		xy(50, 5); cout << "=============================" << endl;

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && m != 4)
		{
			xy(53, m); cout << "  ";
			m++;
			xy(53, m); cout << "->";
			agmenu++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && m != 2)
		{
			xy(53, m); cout << "  ";
			m--;
			xy(53, m); cout << "->";
			agmenu--;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (agmenu)
			{
			case 0:
			{
				system("cls");
			menujam:
				xy(53, n); cout << "->";
				while (agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "Puspa Jaya\n";
					xy(55, 2); cout << "Rp 200.000\n";
					xy(55, 3); cout << "1. 08.00 WIB\n";
					xy(55, 4); cout << "2. 11.00 WIB\n";
					xy(55, 5); cout << "3. 14.00 WIB\n";
					xy(55, 6); cout << "4. 20.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");

					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						switch (agcmenu)
						{
						case 0:
						{
							system("cls");
							Jagent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Jagent1;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 1:
						{
							system("cls");
							Jagent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Jagent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 2:
						{
							system("cls");
							Jagent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Jagent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 3:
						{
							system("cls");
							Jagent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Jagent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 4:
						{
							system("cls");
							goto menuagen;
							break;
						}
						}
					}
							
				}
			}

			case 1:
			{
				menujam2:
				system("cls");
				xy(53, n); cout << "->";
				while (agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "First Travel\n";
					xy(55, 2); cout << "Rp 195.000\n";
					xy(55, 3); cout << "1. 04.00 WIB\n";
					xy(55, 4); cout << "2. 10.00 WIB\n";
					xy(55, 5); cout << "3. 12.00 WIB\n";
					xy(55, 6); cout << "4. 14.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");

					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						switch (agcmenu)
						{
						case 0:
						{
							system("cls");
							Pjagent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pjagent1;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 1:
						{
							system("cls");
							Pjagent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pjagent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 2:
						{
							system("cls");
							Pjagent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pjagent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 3:
						{
							system("cls");
							Pjagent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pjagent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 4:
						{
							system("cls");
							goto menuagen;
							break;
						}
						}
					}
				}
			}
			case 2:
				{
				system("cls");
				Destination();
				break;
				}
			}
		}
	}
}
void Surabaya()
{
	//agent Data
	TravelAgent Magent1, Magent2, Magent3, Magent4, Fagent1, Fagent2, Fagent3, Fagent4;
	Magent1.setData("First Travel", jmlPenumpang * 150000, "07:00 WIB");
	Magent2.setData("First Travel", jmlPenumpang * 150000, "10:00 WIB");
	Magent3.setData("First Travel", jmlPenumpang * 150000, "12:00 WIB");
	Magent4.setData("First travel", jmlPenumpang * 150000, "20:00 WIB");
	Fagent1.setData("Merpati Travel", jmlPenumpang * 190000, "07:00 WIB");
	Fagent2.setData("Merpati Travel", jmlPenumpang * 190000, "10:00 WIB");
	Fagent3.setData("Merpati Travel", jmlPenumpang * 190000, "12:00 WIB");
	Fagent4.setData("Merpati Travel", jmlPenumpang * 190000, "15:00 WIB");
	int agmenu = 0, m = 2, n = 3,o = 6, agcmenu = 0, conmenu = 0;
	bool agt = true;
	bool con = true;

menuagen:
	xy(53, m); cout << "->";
	while (agt)
	{
		xy(50, 0); cout << "=============================" << endl;
		xy(60, 1); cout << "Surabaya";
		xy(55, 2); cout << "1.First Travel";
		xy(55, 3); cout << "2.Merpati Travel";
		xy(55, 4); cout << "3.Back";
		xy(50, 5); cout << "=============================" << endl;

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && m != 4)
		{
			xy(53, m); cout << "  ";
			m++;
			xy(53, m); cout << "->";
			agmenu++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && m != 2)
		{
			xy(53, m); cout << "  ";
			m--;
			xy(53, m); cout << "->";
			agmenu--;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (agmenu)
			{
			case 0:
			{
				system("cls");
			menujam:
				xy(53, n); cout << "->";
				while (agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "First Travel";
					xy(55, 2); cout << "Rp 150.000\n";
					xy(55, 3); cout << "1. 07.00 WIB\n";
					xy(55, 4); cout << "2. 10.00 WIB\n";
					xy(55, 5); cout << "3. 12.00 WIB\n";
					xy(55, 6); cout << "4. 20.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");
					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						switch (agcmenu)
						{
						case 0:
						{
							system("cls");
							Magent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Magent1;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 1:
						{
							system("cls");
							Magent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Magent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 2:
						{
							system("cls");
							Magent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Magent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 3:
						{
							system("cls");
							Magent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Magent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 4:
						{
							system("cls");
							goto menuagen;
							break;
						}
						}
					}


				}

			}
			case 1:
			{
			menujam2:
				system("cls");
				xy(53, n); cout << "->";
				while (agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "Merpati Travel";
					xy(55, 2); cout << "Rp 190.000\n";
					xy(55, 3); cout << "1. 07.00 WIB\n";
					xy(55, 4); cout << "2. 10.00 WIB\n";
					xy(55, 5); cout << "3. 12.00 WIB\n";
					xy(55, 6); cout << "4. 15.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");
					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						switch (agcmenu)
						{
						case 0:
						{
							system("cls");
							Fagent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent1;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 1:
						{
							system("cls");
							Fagent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 2:
						{
							system("cls");
							Fagent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 3:
						{
							system("cls");
							Fagent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Fagent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 4:
						{
							system("cls");
							goto menuagen;
							break;
						}
						}
					}
				}
			}
			case 2:
			{
				system("cls");
				Destination();

			}
			}
		}
	}
}
void Semarang()
{
	//agent Data
	TravelAgent Gagent1, Gagent2, Gagent3, Gagent4, Pagent1, Pagent2, Pagent3, Pagent4;
	Gagent1.setData("Gateway Travel", jmlPenumpang * 110000, "05:00 WIB");
	Gagent2.setData("Gateway Travel", jmlPenumpang * 110000, "10:00 WIB");
	Gagent3.setData("Gateway Travel", jmlPenumpang * 110000, "14:00 WIB");
	Gagent4.setData("Gateway Travel", jmlPenumpang * 110000, "21:00 WIB");
	Pagent1.setData("Portal Travel", jmlPenumpang *  130000, "05:00 WIB");
	Pagent2.setData("Portal Travel", jmlPenumpang *  130000, "10:00 WIB");
	Pagent3.setData("Portal Travel", jmlPenumpang *  130000, "14:00 WIB");
	Pagent4.setData("Portal Travel", jmlPenumpang *  130000, "21:00 WIB");
	int agmenu = 0, m = 2, n = 3,o = 6, agcmenu = 0, conmenu = 0;
	bool agt = true;
	bool con = true;

menuagen:
	xy(53, m); cout << "->";
	while (agt)
	{
		xy(50, 0); cout << "=============================" << endl;
		xy(60, 1); cout << "Semarang";
		xy(55, 2); cout << "1.Gateway Travel";
		xy(55, 3); cout << "2.Portal Travel";
		xy(55, 4); cout << "3.Back";
		xy(50, 5); cout << "=============================" << endl;

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && m != 4)
		{
			xy(53, m); cout << "  ";
			m++;
			xy(53, m); cout << "->";
			agmenu++;
			continue;
		}
		if (GetAsyncKeyState(VK_UP) && m != 2)
		{
			xy(53, m); cout << "  ";
			m--;
			xy(53, m); cout << "->";
			agmenu--;
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			switch (agmenu)
			{
			case 0:
			{
				system("cls");
			menujam:
				xy(53, n); cout << "->";
				while (agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "Gateway Travel\n";
					xy(55, 2); cout << "Rp 110.000\n";
					xy(55, 3); cout << "1. 05.00 WIB\n";
					xy(55, 4); cout << "2. 10.00 WIB\n";
					xy(55, 5); cout << "3. 14.00 WIB\n";
					xy(55, 6); cout << "4. 21.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");
					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if (GetAsyncKeyState(VK_RETURN))	
					{
						switch (agcmenu)
						{
						case 0:
						{
							system("cls");
							Gagent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Gagent1;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 1:
						{
							system("cls");
							Gagent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Gagent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 2:
						{
							system("cls");
							Gagent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Gagent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 3:
						{
							system("cls");
							Gagent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Gagent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam;
									}
									}
								}
							}
						}
						case 4:
						{
							system("cls");
							goto menuagen;
							break;
						}
						}
					}

				}

			}
			case 1:
			{
			menujam2:
				system("cls");
				xy(53, n); cout << "->";
				while (agt)
				{
					xy(50, 0); cout << "=============================" << endl;
					xy(60, 1); cout << "Portal Travel\n";
					xy(55, 2); cout << "Rp 130.000\n";
					xy(55, 3); cout << "1. 05.00 WIB\n";
					xy(55, 4); cout << "2. 10.00 WIB\n";
					xy(55, 5); cout << "3. 14.00 WIB\n";
					xy(55, 6); cout << "4. 21.00 WIB\n";
					xy(55, 7); cout << "5. Back\n";
					xy(50, 8); cout << "=============================" << endl;
					system("pause>nul");
					if (GetAsyncKeyState(VK_DOWN) && n != 7)
					{
						xy(53, n); cout << "  ";
						n++;
						xy(53, n); cout << "->";
						agcmenu++;
						continue;
					}
					if (GetAsyncKeyState(VK_UP) && n != 3)
					{
						xy(53, n); cout << "  ";
						n--;
						xy(53, n); cout << "->";
						agcmenu--;
						continue;
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						switch (agcmenu)
						{
						case 0:
						{
							system("cls");
							Pagent1.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pagent1;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 1:
						{
							system("cls");
							Pagent2.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pagent2;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 2:
						{
							system("cls");
							Pagent3.displayData();
							xy(55, 5); cout << "Confirm Order? [y/n]: ";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pagent3;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 3:
						{
							system("cls");
							Pagent4.displayData();
							xy(55, 5); cout << "Confirm Order?";
							xy(53, o); cout << "->";
							while (con)
							{
								color(2, 0);
								xy(55, 6); cout << "yes";
								color(4, 0);
								xy(55, 7); cout << "No";
								color(7, 0);
								system("pause>nul");
								if (GetAsyncKeyState(VK_DOWN) && o != 7)
								{
									xy(53, o); cout << "  ";
									o++;
									xy(53, o); cout << "->";
									conmenu++;
									continue;
								}
								if (GetAsyncKeyState(VK_UP) && o != 6)
								{
									xy(53, o); cout << "  ";
									o--;
									xy(53, o); cout << "->";
									conmenu--;
									continue;
								}
								if (GetAsyncKeyState(VK_RETURN))
								{
									switch (conmenu)
									{
									case 0:
									{
										ofstream out("Bill.txt");
										out << Pagent4;
										out.close();
										system("cls");
										Final();
										break;
									}
									case 1:
									{
										system("cls");
										goto menujam2;
									}
									}
								}
							}
						}
						case 4:
						{
							system("cls");
							goto menuagen;
							break;
						}
						}
					}
				}
						
			}
			case 2:
			{
				system("cls");
				Destination();
				
			}
			}
		}
	}
}
//it ain't much, but it's honest work
