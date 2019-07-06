CXX = g++-5
CXXFLAGS = -g -std=c++14 
EXEC = run
OBJECTS = locations/location.o game.o locations/tile.o characters/character.o /characters/player.o subjectObserver/subject.o subjectObserver/observer.o 
DEPENDS = ${OBJECTS.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -Wall -MMD

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
