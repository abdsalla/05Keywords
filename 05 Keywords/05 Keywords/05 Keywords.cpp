// 05 Keywords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


int main()
{
	string guess;
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	int winCount = 0;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{

		{ "goldfish", " The snack that smiles back " },
		{ "jiffy", " I'll be back in a " },
		{ "ears", " Music to my " },
		{ "orange", " Red and yellow make " },
		{ "eat", " It's a dog ___ dog world " },
		{ "bud", " Nip it in the " },
		{ "hand", " Sleight of " },
		{ "water", " Blood is thicker than " },
		{ "jiffy", " Barking up the wrong " },
		{ "cat", "Curiosity killed the " }

	};


		srand(static_cast<unsigned int> (time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];

		string jumble = theWord;
		int length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}


		cout << "Welcome to Jumble! The scramble word guessing game!" << endl;
		cout << " You win once you successfully guess a word 3 times " << endl;
		cout << "Guess the word the jumbled version" << endl;


	for (int i = 0; i < 3; ++i)
	{

		srand(static_cast<unsigned int> (time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];
		string theHint = WORDS[choice][HINT];

		string jumble = theWord;
		int length = jumble.size();
		for (int i = 0; i < length; ++i)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		while ((guess != theWord) && (guess != "q"))
		{	
			cout << "The jumbled word is: " << jumble << endl;
			cout << "Enter the answer or, 'h' for hint and q for 'quit'" << endl;
			cin >> guess;

			if (guess == "h")
			{
				cout << theHint << endl;
			}
			if (guess == "q")
			{
				return 0;
			}
			if (guess != theWord && guess != "q" & guess != "h")
			{
				cout << " Nope, Try again " << endl;
			}
			if (guess == theWord)
			{
				winCount = winCount + 1;
				cout << "Good job!" << endl;
				time(NULL);
				srand((unsigned)time(NULL));
				string jumble = theWord;
				int length = jumble.size();
				for (int i = 0; i < length; ++i)
				{
					int index1 = (rand() % length);
					int index2 = (rand() % length);
					char temp = jumble[index1];
					jumble[index1] = jumble[index2];
					jumble[index2] = temp;
				}
				
			}

		}
		
		system("pause");

	}
	cout << "Congratulations User!  You Win!" << endl;
	cout << "Closing out..." << endl;
	system("pause");

	return 0;
}