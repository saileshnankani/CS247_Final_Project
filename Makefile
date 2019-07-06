CXX = g++-5
CXXFLAGS = -g -std=c++14 
EXEC = run
OBJECTS = location.o game.o tile.o character.o
DEPENDS = ${OBJECTS.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -Wall -MMD

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
