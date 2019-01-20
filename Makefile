CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror=vla -MMD -g
OBJECTS=main.o map.o cell.o unit.o doorway.o nothing.o passway.o stair.o tile.o wall.o BA.o BD.o gold_n.o gold_s.o hoard_m.o PH.o potion.o RH.o treasure.o WA.o WD.o enemy.o hero.o human.o dwarf.o elf.o orcs.o merchant.o dragon.o halfling.o hoard_d.o shade.o drow.o vampire.o troll.o goblin.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}


-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
