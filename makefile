output: main.o Creature.o Vampire.o Universe.o BlueMen.o Barbarian.o Medusa.o HarryPotter.o 
	g++ main.o Creature.o Vampire.o Universe.o BlueMen.o Barbarian.o Medusa.o HarryPotter.o  -o project3 

main.o: main.cpp 
	g++ -c main.cpp

Creature.o: Creature.cpp Creature.hpp
	g++ -g -c -std=c++11 Creature.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -g -c -std=c++11 Vampire.cpp

Universe.o: Universe.cpp Universe.hpp
	g++ -g -c -std=c++11 Universe.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -g -c -std=c++11 BlueMen.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -g -c -std=c++11 Barbarian.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -g -c -std=c++11 Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -g -c -std=c++11 HarryPotter.cpp



clean:
	rm *.o project3
