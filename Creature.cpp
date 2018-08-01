#include "Creature.hpp"
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

/********************************
Description: Virtual function for the creature, will take a player name.
********************************/
Creature::Creature(string userName)
{

    armor = 0;
    strength = 0;
	name = userName;
}


Creature::~Creature()
{
}

/********************************
Description: Virtual
********************************/
int Creature::getAttack(Creature &)
{
	return attack;
}

/********************************
Description:
********************************/
 int Creature::getDefense(Creature &, int atk)
{
	return defense;
}

 /********************************
Description:
********************************/
 void Creature::setAttack(int atk)
 {
	 attack = atk;
	 
 }

 /********************************
Description:
********************************/
void Creature::setDefense(int def)
 {
	 defense = def;
 }

/********************************
Description: I modified my group projects fight function to work in this project. It will return the damage of the creature that uses it, taking into account the opponant it is fight. It will first 
 roll attack for the creature, and defense of the opponant. The getDamage function will then be called
 with the attack and defense, and opponant as arguements. The getDamage function will take into account
 the opponant's armor to return the correct amount of damage. The 3 situations that will occur if the
 player's attack is greater than the opponant's, the players attack is lower than the oppoant's and
 the defense and attack are equal.
********************************/
 int Creature::fight (Creature &opponant) //subtract
	{
		int myAtk= 0;
		int OppDef = 0;
        int dmg;
        


		//get the attack of this creature
		myAtk = this->getAttack(opponant); //sets the attack to the current creature
		//get the defense of the opponant
		OppDef = opponant.getDefense(*this, myAtk); //sets the defense of the opponant
        //get dmg of this creature
        dmg = getDmg(myAtk, OppDef, opponant);

        //first case if attack is greater than the opponant's defense
		if (myAtk > OppDef)
		{
            
            if ((myAtk - OppDef - opponant.getArmor()) <= 0) // if opponants def+armor is > than attackers dmg
            {
                cout <<  opponant.name << " defended the attack." << endl;
                return 0;
            }
            else //if attackers atk is higher than 
            {
                return dmg;
                
            }
		}
        //2nd case, if attack is lower than the defense.
		else if (myAtk < OppDef)
		{
            cout << opponant.name <<" defended attack" << endl;
			return 0;
		}
        
       //3rd case, attack and defense are equal

		else if (myAtk == OppDef)
		{
			cout << opponant.name <<" defended attack" << endl;
			return 0;
		}
        return 0;
	}


	/********************************
Description:Virtual function, will be passed to the creature to return their strength.
********************************/

	 int Creature::getStrength()
	 {
		 return 0;
	 }

/********************************
Description: Virtual function, will be passed to the creature to return their strength.
********************************/
	 int Creature::getArmor()
	 {
		 return 0;
	 }

string Creature::getName()
{
    return 0;
}

/********************************
Description: Random integer function included to for each creature's attack/defense rolls. Also for
 some of the special abilities. Used this function in my group project, found it more useful then my
 old random integer function.
********************************/

int Creature::getRandomNumber(int min, int max)
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
Description: Virtual function, will be passed to the creature to return their strength.
********************************/
int Creature::getDmg(int atk, int def, Creature &opponant) //will take the atk roll - def roll - armor
{
    return 0;
}
