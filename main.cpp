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
*******************************************************************************/

#include "Universe.hpp"
#include "Creature.hpp"
#include "Vampire.hpp"

int main()
{
    Universe universe;
    universe.menu();
	
    
    return 0;
}
