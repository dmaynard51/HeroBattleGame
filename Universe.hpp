#include "Creature.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

class Universe
{
private:
	Creature *player1;
	Creature *player2;

	void setPlayer1();
	void setPlayer2();

	void scoreRound();


	int getRandomNumber(int min, int max);
	int player1Wins;
	int player2Wins;
	int ties;
	int totalRound;

	int selectCreature;
	int selectRounds;
	int health;
    
    void healthCheck(Creature &player1, Creature &player2);
	int player1Score;
	int player2Score;
public:
	Universe();
	~Universe();

	void playGame();
	void showStatistics();
	void clearStatistics();
	void showHealth(Creature &player1, Creature &player2);
	void menu();
	int inputValidation (int min, int max);
	void showScore();


};

#endif
