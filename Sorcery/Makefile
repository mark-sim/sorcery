CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD 
EXEC = sorcery
OBJECTS = disenchant.o triggerminion.o bonegolem.o fireelemental.o potionseller.o subject.o abstractritual.o darkritual.o auraofpower.o standstill.o recharge.o activationminion.o apprenticesummoner.o mastersummoner.o novicepyromancer.o ascii_graphics.o silence.o magicfatigue.o haste.o enrage.o giantstrength.o enchantmentdecorator.o unsummon.o blizzard.o raisedead.o banish.o abstractspell.o board.o graveyard.o abstractminion.o airelemental.o earthelemental.o nonabilityminion.o main.o player.o game.o card.o deck.o hand.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}


