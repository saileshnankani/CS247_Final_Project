CXX = g++-5
CXXFLAGS = -g -std=c++14 
EXEC = run
OBJECTS = game.o ./controller/controller.o ./model/model.o ./subjectObserver/subject.o ./subjectObserver/observer.o ./locations/location.o ./locations/tile.o ./characters/combatant.o ./characters/player.o ./characters/enemy.o  ./characters/levels/easyEnemy.o ./characters/levels/mediumEnemy.o ./characters/levels/hardEnemy.o ./characters/levels/easyLevel.o ./characters/levels/mediumLevel.o ./characters/levels/hardLevel.o ./characters/levels/level.o ./characters/character.o   
DEPENDS = ${OBJECTS.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -Wall -MMD

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
