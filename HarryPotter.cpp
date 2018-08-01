

#include "HarryPotter.hpp"
#include <ctime>
#include <limits>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;




/********************************
 Description: Constructor for Harry, with a strength of 10, armor of 0, and sets hogwart's ability to true
 (not used).
 ********************************/
HarryPotter::HarryPotter(string inputName) : Creature(inputName)
{
    name = inputName;
    armor = 0;
    strength = 10;
	hogwarts = true;
}



/********************************
 Description: Will roll 2 attack die from 1-6, and display the sum of the attack rolled.
 ********************************/
int HarryPotter::getAttack(Creature &opponant)
{
    int atk;
    int tempAtk = 0;
    
    tempAtk += getRandomNumber(1, 6);
    tempAtk += getRandomNumber(1, 6);
    
    atk = tempAtk;
    cout << "Attack roll for " << getName() << " " << atk << endl; //for testing;
    return atk;
    
}


/********************************
 Description: Will roll 2 defense die from 1-6. Also if harry's health gets below 0, then it will
 increase his health back to 20 using his hogwart's ability. It will then display if the ability is used
 and the defense die rolled.
 ********************************/
int HarryPotter::getDefense(Creature &opponant, int atk)
{

    int def = 0;
    int tempDef = 0;

    tempDef += getRandomNumber(1, 6);
    tempDef += getRandomNumber(1, 6);
    def = tempDef;

    if ((atk - def - getArmor() >= strength) && (hogwarts == true))
    {
        cout << "Harry uses hogwarts ability!" << endl;

       strength = 20 + atk - def - getArmor();
        hogwarts = false;
    }
    
    cout << "Defense roll for: "  << getName() << " " << def << endl; //for testing
    
        
    
    return def;
        
 
    return 0;
}


/********************************
 Description: Will return the strength of the creature.
 ********************************/
int HarryPotter::getStrength()
{
    return strength;
}


/********************************
 Description: Return the name of the creature.
 ********************************/
string HarryPotter::getName()
{
    
    return name;
}


/********************************
 Description: Returns the armor of the creature.
 ********************************/
int HarryPotter::getArmor()
{
    return armor;
    
}


/********************************
 Description: Will return the damage, taking the attack and defense as arguments. Also takes the opponant
 it is fighting against to get the value of their armor.
 ********************************/
int HarryPotter::getDmg(int atk, int def, Creature &opponant) //will return atk - def - armor = dmg
{
    
    
		cout << "Attack: " << atk << endl;
		cout << "Defense: " << def << endl;
        cout << opponant.getName() << " armor absorbed: " << opponant.getArmor() << " points of damage" << endl;
        cout << getName() << " does " << atk - def - opponant.getArmor() << " points of damage" << endl;
    
    return atk - def - opponant.getArmor();
}
