/********************************************************
 Name: Daniel Maynard
 Assignment: Project 3
 Date: 8/4/17
 Description: At the start of this game, the menu function will be called, which will 
 gives options to play. show score, clear score and quit. The game will take two creatures 
 chosen by the user/s and will have them fight against each other. When either of the
 creature's strength gets to 0 or below the other player will win, and the player's score will go up by
 one.
 
 The creatures in this game are a vampire - which can charm the opponant, a barbarian, a medusa - which
 when it rolls a 12 will turn the opponant to stone, blue men - and when it loses 4 health it loses an 
 defense die and Harry Potter - when his strength get to 0 or below, will regenerate to 20 strength one 
 time.
 
 This game also contains a check score function and clear score function, which allow the user to see
 how many time each player has won and reset it.
 ********************************************************/

#include "Universe.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;


Universe::Universe()
{
	player1 = NULL;
	player2 = NULL;
	totalRound = 0;
	player1Score = 0;
	player2Score = 0;
	health = 0;
}


/********************************
 Description: Clears the memory of the creatures that were created.
 ********************************/

Universe::~Universe()
{
	delete player1;
	delete player2;
}

/********************************
Description: Asks the player what creature player 1 will be. Used a similar function in my group project. 
 to choose between rock paper scissor.
********************************/

void Universe::setPlayer1()
{
    int userChoice = 0;
    string msg = "Which creature would you like use?\n"
    "    1. Vampire\n"
    "    2. Barbarian\n"
    "    3. Blue Men\n"
    "    4. Medusa\n"
    "    5. Harry Potter\n"
    "Please enter your selection: ";
    cout << msg << endl;
//input validation to make sure a number 1-5 is entered    
    userChoice = inputValidation(1, 5);
    cout << endl;
    
// frees up memory for the new creature
    delete player1;
    
    if (userChoice == 1)
    {
        player1 = new Vampire("Player 1 - Vampire");
        cout << "You chose Vampire." << endl;
    }
    
    if (userChoice == 2)
    {
        player1 = new Barbarian("Player 1 - Barbarian");
        cout << "You chose Barbarian" << endl;
    }

    if (userChoice == 3)
    {
        player1 = new BlueMen("Player 1 - Blue Men");
        cout << "You chose BlueMen" << endl;
    }
    
    if (userChoice == 4)
    {
        player1 = new Medusa("Player 1 - Medusa");
        cout << "You chose Medusa" << endl;
    }
    
    if (userChoice == 5)
    {
        player1 = new HarryPotter("Player 1 - Harry Potter");
        cout << "You chose Harry Potter" << endl;
    }
}


/********************************
 Description: Asks the player what creature player 1 will be. Used a similar function in my group project.
 to choose between rock paper scissor.
********************************/
void Universe::setPlayer2()
{
    int userChoice = 0;
    string msg = "Which creature would you like use?\n"
    "    1. Vampire\n"
    "    2. Barbarian\n"
    "    3. Blue Men\n"
    "    4. Medusa\n"
    "    5. Harry Potter\n"
    "Please enter your selection: ";
    cout << msg << endl;
//input validation used to
    userChoice = inputValidation(1, 5);
    cout << endl;
    
//frees up memory for a new creature
    delete player2;
    
    if (userChoice == 1)
    {
        player2 = new Vampire("Player 2 - Vampire");
        cout << "You chose Vampire." << endl;
    }
    
    if (userChoice == 2)
    {
        player2 = new Barbarian("Player 2 - Barbarian");
        cout << "You chose Barbarian" << endl;
    }
    
    if (userChoice == 3)
    {
        player2 = new BlueMen("Player 2 - Blue Men");
        cout << "You chose BlueMen" << endl;
    }

    if (userChoice == 4)
    {
        player2 = new Medusa("Player 2 - Medusa");
        cout << "You chose Medusa" << endl;
    }
    
    if (userChoice == 5)
    {
        player2 = new HarryPotter("Player 2 - Harry Potter");
        cout << "You chose Harry Potter" << endl;
    }
    
}


/********************************
Description: This function will play 1 round, will first ask the players which creatures they would
 like to play, it will then randomize which player goes first. The function will then display the strength
 of each creature, and by hitting enter the fight will start and display each players attack, defense,
 armor and damage. It will then display the strength of each player. This loop will continue until one of 
 the player's strength get to 0 or below.
********************************/
void Universe::playGame()
{
	cout << "Round #" << (totalRound = totalRound + 1) << ":" << endl;

	//sets players 1-2
	setPlayer1();
	setPlayer2();
	health = 0;
	int firstPlayer = getRandomNumber(1, 2);

	if (firstPlayer == 1) //if player1 gets to go first
	{
		showHealth(*player1, *player2); //displays health
		cout << endl;
        cout << player1->getName() << " goes first!" << endl;
		cin.get();


		while (health == 0)
		{
			showHealth(*player1, *player2);
			cout << endl;
            player2->strength -= player1->fight(*player2);// reduces strength of player 2
			if (player2->getStrength() <= 0) //if player 1's health 0 or below, break the loop.
			{
				showHealth(*player1, *player2);
                healthCheck(*player1, *player2);
				break;
			}
			healthCheck(*player1, *player2);
			showHealth(*player1, *player2);
			cin.get();
            player1->strength -= player2->fight(*player1); //reduces strength of player 1
			healthCheck(*player1, *player2);
			showHealth(*player1, *player2);
            cin.get();
		}
		cout << "End of round" << endl;
	}


	if (firstPlayer == 2) //if player2 gets to go first
	{
		showHealth(*player1, *player2); //displays health
		cout << endl;
        cout << player2->getName() << " goes first!" << endl;
		cin.get();


		while (health == 0)
		{
			cout << endl;
            showHealth(*player1, *player2);
			player1->strength -= player2->fight(*player1); //reduces strength of player 1
			if (player1->getStrength() <= 0) //if players 2's health gets to 0 or below, break the loop
			{
				showHealth(*player1, *player2);
                healthCheck(*player1, *player2);
				break;
			}
			healthCheck(*player1, *player2) ;
			showHealth(*player1, *player2);
			cin.get();
			player2->strength -= player1->fight(*player2);// reduces strength of player 2
			healthCheck(*player1, *player2);
			showHealth(*player1, *player2);
            cin.get();
		}
		cout << "End of round" << endl;
	}
	 
}


/********************************
Description: This is the random function used, it allows an arguement to be entered with min and max.
 Our group project used this function, so I found it more useful to use then my older random function.
********************************/
int Universe::getRandomNumber(int min, int max)
{
    int result;
    static bool setSeed = false;
    
    if (setSeed == false)
    {
        srand(static_cast<int>(time(0)));
        setSeed = true;
    }
    
    result = (rand() % (max - min + 1)) + min;
    return result;
}

/********************************
Description: This will change the health to 1 if one of the players dies and increases the score of the 
 opposing player.
********************************/

void Universe::healthCheck(Creature &player1, Creature &player2)
{
    
    
    if (player1.getStrength() <= 0)
    {
        cout << player1.getName() << " has died!" << endl;
        health = 1;
		player2Score = player2Score + 1;

    }
    
    if (player2.getStrength() <= 0)
    {
        cout << player2.getName() << " has died!" << endl;
        health = 1;
		player1Score = player1Score + 1;
    }

    
}

/********************************
Description: This function will return the health of each player
********************************/

void Universe::showHealth(Creature &player1, Creature &player2)
{
	cout << endl;
	cout << "Current Round Strength Stat:" << endl;
	cout << "****************************" << endl;
	cout << player1.getName() << " Strength: " << player1.getStrength() << endl;
	cout << player2.getName() << " Strength: " << player2.getStrength() << endl;
	cout << "****************************" << endl;
}

/********************************
Description: This function will holds the menu function, allows the user to initiate to play the game,
 check the score, clear the score and quit.
********************************/
void Universe::menu()
{
	cout << "1. Play" << endl;
	cout << "2. Check Score" << endl;
	cout << "3. Clear Score" << endl;
	cout << "4. Quit" << endl;

	int choice = 0;

	choice = inputValidation(1, 4);

	if (choice == 1)
	{
		playGame();
		return menu();
	}

	if (choice == 2)
	{
		cout << "Player 1 score is: " << player1Score << endl;
		cout << "Player 2 score is: " << player2Score << endl;
		return menu();
	}


	if (choice == 3)
	{
		player1Score = 0;
		player2Score = 0;
		cout << "Player 1 score is: " << player1Score << endl;
		cout << "Player 2 score is: " << player2Score << endl;
		return menu();
	}


	if (choice == 4)
	{
		cout << "Quitting game." << endl;
	}


}

/********************************
Description: This holds the input validation for the game. Making sure numbers are chosen with min and
 max as arguments. In my group project we used this function, and found it more useful then the older
 one I was using since it detects strings.
********************************/
int Universe::inputValidation(int min, int max)
{
	bool inputFail = true;
	int input = 0;


	while (inputFail) //will loop as long as the boolean inputFail is true.
	{
		cin >> input;
		inputFail = cin.fail(); //checks to make sure the right type of value is inputted

		//clears the input stream
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//Lets the user know invalid input.
		if ((inputFail) || (input < min) || (input > max))
		{
			cout << "\nYour input is invalid.\n";
			cout << "Please enter an integer from ";
            cout << min << " to " << max << endl;

			inputFail = true;
		}
	}
	return input;
}

