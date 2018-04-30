#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main (void)
{

	using namespace std;

	srand((unsigned int)time(0));
	string name;
	bool end = false;
	bool lost;
	int menu_choice;

	int archers = 75;
	int catapults = 35;
	int swordsmen = 150;

	int g_archers = rand() % (51) + 20;
	int g_catapults = rand() % (41)+10;
	int g_swordsmen = rand() % (101) + 50;

	int archers_menu, catapults_menu, swordsmen_menu;
	int fight_menu;

	cout << "Welcome Commander, what is your name?\n";
	cin >> name;
	cout << "Well, " << name
		<<" welcome to the Battle Commander Game.\n"
		<<"\nYou are the commander of the English Army"
		<<" attacking Scotland.";
	while (!end)
	{
		int archers_sent = 0, catapults_sent = 0;
		int swordsmen_sent = 0;
		cout << "\nYou have " << archers << " archers, " << catapults << " catapults, and " << swordsmen << " swordsmen.\n"
			<<"\nScotland has " << g_archers << " archers, " << g_catapults << " catapults, and " << g_swordsmen << " swordsmen.\n\n";

		do
		{
			int i = 1;
			if (archers > 0 && ((archers - archers_sent) != 0))
			{
				archers_menu = i;
				cout << "[" << i << "] Send Archers\n";
				i++;
			}
			else archers_menu = 0;

			if (catapults > 0 && ((catapults - catapults_sent) != 0))
			{
				catapults_menu = i;
				cout << "[" << i << "] Send Catapults\n";
				i++;
			}
			else catapults_menu = 0;

			if (swordsmen > 0 && ((swordsmen-swordsmen_sent) != 0))
			{
				swordsmen_menu = i;
				cout << "[" << i << "] Send Swordsmen\n";
				i++;
			}
			else swordsmen_menu = 0;

			fight_menu = i;
			cout << "[" << i << "] Go Fight\n";
			cin >> menu_choice;

			if (menu_choice == archers_menu)
			{
				do {
					cout << "\nHow many archers would you like to send?\n";
					cin >> archers_sent;
				}
				while (!(archers_sent > -1 && archers_sent <= archers));
			} else if (menu_choice == catapults_menu)
			{
				do {
					cout << "\nHow many catapults would you like to send?\n";
					cin >> catapults_sent;
				}while (!(catapults_sent > -1 && catapults_sent <= catapults));
			} else if (menu_choice == swordsmen_menu)
			{
				do {
					cout << "\nHow many swordsmen would you like to send?\n";
					cin >> swordsmen_sent;
				} while (!(swordsmen_sent > -1 && swordsmen_sent <= swordsmen));

			}
		}
		while (menu_choice != fight_menu);
		cout << "\nEntering Battle...\n";
		int archers_dead, catapults_dead, swordsmen_dead;
		int g_archers_dead, g_catapults_dead, g_swordsmen_dead;

		archers_dead = 2 * g_catapults;
		catapults_dead = g_swordsmen;
		swordsmen_dead = 3 * g_archers;

		g_archers_dead = 2 * catapults_sent;
		g_catapults_dead = swordsmen_sent;
		g_swordsmen_dead = 3 * archers_sent;

		archers = (archers_dead<archers) ? archers - archers_dead : 0;
		catapults = (catapults_dead < catapults) ? catapults - catapults_dead : 0;
		swordsmen = (swordsmen_dead < swordsmen) ? swordsmen - swordsmen_dead : 0;

		g_archers = (g_archers_dead < g_archers) ? g_archers - g_archers_dead : 0;
		g_catapults = (g_catapults_dead < g_catapults) ? g_catapults - g_catapults_dead : 0;
		g_swordsmen = (g_swordsmen_dead < g_swordsmen) ? g_swordsmen - g_swordsmen_dead : 0;

		cout << "It was a long battle.\n"
			<< archers_dead << " archers died.\n"
			<< catapults_dead << " catapults were taken out.\n"
			<< swordsmen_dead << " swordsmen died.\n";

		if ((archers+catapults+swordsmen) == 0)
			end = lost = true;

		else if((g_archers + g_catapults+g_swordsmen) == 0)
		{
			end = true;
			lost = false;
		}
	}
	if (lost)
	{
		cout << "\nYou lost. Try again next time.\n";
		return 0;
	}
	cout << "\nCongratulations, you won!\n";
	return 0;

}
