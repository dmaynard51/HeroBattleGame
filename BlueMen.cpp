

#include "BlueMen.hpp"
#include <ctime>
#include <limits>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;



/********************************
 Description: When blue men are created passes the following stats
 ********************************/
BlueMen::BlueMen(string inputName) : Creature(inputName)
{
    name = inputName;
    armor = 3;
    strength = 12;
}


/********************************
 Description: Will return the sum of 2 die rolls from 1-10, and display the attack roll.
 ********************************/
int BlueMen::getAttack(Creature &opponant)
{
    int atk;
    int tempAtk = 0;
    
    tempAtk += getRandomNumber(1, 10);
    tempAtk += getRandomNumber(1, 10);
    
    atk = tempAtk;
    
    
    
    cout << "Attack roll for " << getName() << " " << atk << endl;
    return atk;
    
}

/********************************
 Description: Will roll 3 defense rolls, but for each decrease of 4, will lose a defense roll. 
 Will also display the defense roll to the user.
 ********************************/
int BlueMen::getDefense(Creature &opponant, int atk)
{
   
    
        int def = 0;
    int tempDef = 0;
    
    if (strength >= 9)
    {
        tempDef += getRandomNumber(1, 6);
        tempDef += getRandomNumber(1, 6);
        tempDef += getRandomNumber(1, 6);
    }

    if (strength >= 5)
    {
        tempDef += getRandomNumber(1, 6);
        tempDef += getRandomNumber(1, 6);
    }
    
    if (strength >= 1)
    {
        tempDef += getRandomNumber(1, 6);
    }
    
    def = tempDef;
    cout << "Defense roll for: "  << getName() << " " << def << endl; //for testing
    return def;
        
    
    return 0;
}

/********************************
 Description: Will return the strength of the creature.
 ********************************/
int BlueMen::getStrength()
{
    
    return strength;
}


/********************************
 Description: Return the name of the creature.
 ********************************/
string BlueMen::getName()
{
    
    return name;
}


/********************************
 Description: Returns the armor of the creature.
 ********************************/
int BlueMen::getArmor()
{
    return armor;
    
}


/********************************
 Description: Will return the damage, taking the attack and defense as arguments. Also takes the opponant
 it is fighting against to get the value of their armor.
 ********************************/
int BlueMen::getDmg(int atk, int def, Creature &opponant) //will return atk - def - armor = dmg
{
		cout << "Attack: " << atk << endl;
		cout << "Defense: " << def << endl;
		cout << opponant.getName() << " armor absorbed: " << opponant.getArmor() << " points of damage" << endl;
        cout << getName() << " does " << atk - def - opponant.getArmor() << " points of damage" << endl;
    return atk - def - opponant.getArmor();
}
