CXX = g++-5 
CXXFLAGS =  -g -std=c++14 
EXEC = UWgame
OBJECTS = game.o ./controller/action.h ./controller/controller.o ./controller/keyboard.o ./controller/curseControl.o ./view/view.o ./view/standard.o ./view/curseView.o ./view/graphic.o ./view/window.o ./model/model.o ./subjectObserver/subject.o ./subjectObserver/observer.o ./locations/location.o ./locations/tile.o ./characters/combatant.o ./characters/player_impl.o ./characters/player.o ./characters/npc.o ./characters/interviewer.o ./characters/enemy.o  ./characters/levels/easyEnemy.o ./characters/levels/mediumEnemy.o ./characters/levels/hardEnemy.o ./characters/levels/easyLevel.o ./characters/levels/mediumLevel.o ./characters/levels/hardLevel.o ./characters/levels/level.o ./characters/character.o   
DEPENDS = ${OBJECTS.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -L/usr/X11R6/lib -lX11 -o ${EXEC} -Wall -MMD -lncurses 

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
