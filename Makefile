CXX = g++
CXXFLAGS = -Wall -MMD -lncurses
EXEC = cc3k
OBJECTS = main.o player.o race.o object.o treasure.o potion.o enemy.o cell.o floor.o print.o random.o drawmap.o ba.o bd.o wa.o wd.o rh.o ph.o dragon.o merchant.o human.o dwarf.o elf.o halfing.o orcs.o drow.o shade.o goblin.o troll.o vampire.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
