

#include "Medusa.hpp"
#include <ctime>
#include <limits>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;



/********************************
 Description: Constructor will take a name as an argument. Will start the medusa with armor of 3 and 
 strength of 8.
 ********************************/
Medusa::Medusa(string inputName) : Creature(inputName)
{
    name = inputName;
    armor = 3;
    strength = 8;
}



/********************************
 Description: Will roll 2 attack die rolls of 1-6 and display the sum to the user. If an attack die of 12 
 is rolled, will increase medusa's attack to 500. Vampire's blind will be more powerful than her gaze.
 ********************************/
int Medusa::getAttack(Creature &opponant)
{
    int atk = 0;
    int tempAtk = 0;
    tempAtk += getRandomNumber(1, 6); //first dice roll
    tempAtk += getRandomNumber(1, 6); //second dice roll
    atk = tempAtk;

	if (atk == 12)
	{
		cout << getName() << " turns " << opponant.getName() << " to stone" << endl;
		atk = atk +500;
	}


    cout << "Attack roll for " << getName() << " " << atk << endl;

    return atk;
    
}


/********************************
 Description: Will return a defense die roll between 1-6, and display the roll to the user.
 ********************************/
int Medusa::getDefense(Creature &opponant, int atk)
{

        int def = 0;
        def = getRandomNumber(1, 6);
        cout << "Defense roll for: "  << getName() << " " << def << endl; 
        return def;
    
}


/********************************
 Description: Will return the strength of the creature.
 ********************************/
int Medusa::getStrength()
{
    
    return strength;
}


/********************************
 Description: Return the name of the creature.
 ********************************/
string Medusa::getName()
{
    
    return name;
}


/********************************
 Description: Returns the armor of the creature.
 ********************************/
int Medusa::getArmor()
{
    return armor;
    
}

/********************************
 Description: Will return the damage, taking the attack and defense as arguments. Also takes the opponant
 it is fighting against to get the value of their armor.
 ********************************/
int Medusa::getDmg(int atk, int def, Creature &opponant) //will return atk - def - armor = dmg
{


		cout << "Attack: " << atk << endl;
		cout << "Defense: " << def << endl;
        cout << opponant.getName() << " armor absorbed: " << opponant.getArmor() << " much damage" << endl;
        cout << getName() << " does " << atk - def - opponant.getArmor() << " points of damage" << endl;

    return atk - def - opponant.getArmor();
}


/********************************
 Description: Will return the damage, taking the attack and defense as arguments. Also takes the opponant
 it is fighting against to get the value of their armor.
 ********************************/
