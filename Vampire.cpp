//
//  Vampire.cpp
//  project3
//
//  Created by Daniel Maynard on 7/27/17.
//  Copyright © 2017 Daniel Maynard. All rights reserved.
//

#include "Vampire.hpp"
#include <ctime>
#include <limits>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;



/********************************
 Description: Takes a name arguement in the vampire constructor, and armor of 1 and strenght of 18.
 Inheriting from its base class of creature.
 ********************************/
Vampire::Vampire(string inputName) : Creature(inputName)
{
	name = inputName;
    armor = 1;
    strength = 18;
}



/********************************
 Description: Will return Vampire's attack roll from 1-12, and will display the attack roll.
 ********************************/
int Vampire::getAttack(Creature &opponant)
{
    int atk;

    atk = getRandomNumber(1, 12);
	cout << "Attack roll for " << getName() << " " << atk << endl; //for testing;
    return atk;
    
}


/********************************
 Description: Will first do a randomized roll from 1-2 to see if the vampire charms its opponant -
 if it does then increases defense to 1000 - which should be more than medusa's gaze. If it doesn't
 charm, then a roll of 1-6 is rolled to return the vampire's defense.
 ********************************/
int Vampire::getDefense(Creature &opponant, int atk)
{
    int charm = 0;

    charm = getRandomNumber(1, 2);
    
    
    if (charm == 2) //50% chance vampire can't be hit.
    {
        cout << opponant.getName() << " was charmed" << endl;
        return 1000;
        
    }
    
    if (charm == 1) //if vampire can be hit 1-6 is rolled
    {
        int def = 0;
        def = getRandomNumber(1, 6);
        cout << "Defense roll for: "  << getName() << " " << def << endl; //for testing
        return def;
        
    }
    return 0;
}


/********************************
 Description: Will return the strength of the creature.
 ********************************/
int Vampire::getStrength()
{

	return strength;
}


/********************************
 Description: Return the name of the creature.
 ********************************/
string Vampire::getName()
{
    
    return name;
}


/********************************
 Description: Returns the armor of the creature.
 ********************************/
int Vampire::getArmor()
{
    return armor;
    
}


/********************************
 Description: Will return the damage, taking the attack and defense as arguments. Also takes the opponant
 it is fighting against to get the value of their armor.
 ********************************/
int Vampire::getDmg(int atk, int def, Creature &opponant) //will return atk - def - armor = dmg
{
    
		cout << "Attack: " << atk << endl;
		cout << "Defense: " << def << endl;
        cout << opponant.getName() << " armor absorbed: " << opponant.getArmor() << " points of damage" << endl;
        cout << getName() << " does " << atk - def - opponant.getArmor() << " points of damage" << endl;
    return atk - def - opponant.getArmor();
}
