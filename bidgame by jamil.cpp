#include <iostream>
#include<stdlib.h>
#include <iomanip>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

class Scoreboard
{
	private:
		string player_name;													// name of player
		int round;															// number of rounds
		double guess_avg;													// average of guesses
		double tot_score;													// total score

	public:
		Scoreboard()														// default constructor
		{
			player_name ="";
			round = 0;
			guess_avg = 0.00;
			tot_score = 0.00;
		}
		void input_name();													// prototype
		string get_name()	{	return player_name;		}					// get player's name
		int getRound()		{	return round;			}					// number of round played
		double	cal_avg()	{	return guess_avg;		}					// average of player
};

class Game
{
	private:
		int numb_array[100];												// array of 100 numbers (0 to 99)
		int	guess_numb;														// temp number entered
		int win_numb;														// wining number
		int elct;
		int found;															// *** BINARY SEARCH ***
		int low;															// lowest subscript to consider
		int high;															// highest subscript to consider
		int middle;

	public:
		Game()																// default constructor
		{
			for (int i = 0; i < 100; i++)
			{
				numb_array[i] = false;										// initialize flag array
			}
                                    guess_numb;														// guess number
			win_numb;														// winning number
			 int srand(time(0));												// seed random no's
                  elct = 100;
			int found = false;													// *** BINARY SEARCH ***
			int low = 0;													// lowest subscript to consider
			int high = elct -1;												// highest subscript to consider
			int middle = 0;
		}

		void input_numb();
		void pick_number();
		int search_numb(int guess_numb);
		int generate_numb()	{	return rand()% 100 + 1;		}
		int get_guess_numb(){	return guess_numb;			}
		int get_win_numb()	{	return win_numb;			}
		int display_array()
		{
			for (int i = 0; i < 100; i++)
			{
				cout << numb_array[i];
			}
			return 0;
		}
};

void Scoreboard::input_name()
{
	cout << "Enter player's name: ";
	getline(cin, player_name);
}

void Game::pick_number()
{
	win_numb = generate_numb();
	numb_array[win_numb] = win_numb;


}
int Game::search_numb(int guess_numb)
{


	while (found == false && low <= high)
	{
		middle = (low + high) / 2;				// determine midpoint

		if ( numb_array[middle] == guess_numb )
			found = true;					// found it
		else if ( guess_numb < numb_array[middle])
			high = middle - 1;					// cut search range in half
		else
			low = middle + 1;					// cut search range in half
	}
	return found;
}

void Game::input_numb()
{
	int found = -1;
	for (int i = 10; i > 0 && found == -1; i--)
	{
		int temp;

		cout << "You have " << i << " guesses" << endl;
		cout << "Guess a number: ";
		cin >>	guess_numb;
		temp = search_numb(guess_numb);
		if (temp != false)
			cout << "The number is found!";
	}

}

char display_menu()
{
	char choice;
																			// display menu
	cout << endl << endl << "   MAIN MENU" << endl << endl;
	cout << "A. Play a new game" << endl;
	cout << "X. Exit" << endl;
	cout << "Make a choice: ";
	cin >> choice;															// get & return user choice
	return choice;
}

int main()
{

	char choice;
	Scoreboard myScore;
	Game arr;
	myScore.input_name();

	do
		{
			Game myGame;
			choice = toupper(display_menu());								// call function to display menu

			switch (choice)
			{
				case 'A':													// select procedure to follow
					myGame.pick_number();									// generate a random number and place it in array
					myGame.input_numb();									// prompts for a guess number
					break;
				case 'X':													// do nothing if Exit chosen
					cout << "The winning number is " <<  myGame.get_win_numb() << endl;
					break;
				default:
					cout << endl << "Invalid choice -- try again" << endl;
			}
		} while (choice != 'X');											// continue until Exit chosen


	cout << "Hey, "<< myScore.get_name() << " it is working!!" << endl;
	arr.display_array();

	system("Pause");
	return 0;
}

