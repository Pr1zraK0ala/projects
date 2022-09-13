CC = g++
CFLAGS = -Wall -pedantic -Wsuggest-override -fsanitize=address -g
SRC = src/abstract_enemy.cpp  src/default_Game.cpp  src/map.cpp src/abstract_tower.cpp  src/hard_Game.cpp     src/medium_Game.cpp          src/inferno.cpp       src/player.cpp         src/low_Game.cpp      src/wizard.cpp         src/main.cpp
SRCS = src/abstract_enemy.h  src/crossbow.h      src/inferno.h      src/rogue.h src/abstract_tower.h  src/default_Game.h  src/low_Game.h     src/shieldman.h src/archer.h          src/giant.h         src/map.h          src/wizard.h src/barbarian.h     src/hard_Game.h     src/medium_Game.h src/cannon.h          src/hash_pair.h     src/player.h

all : clean build compile doc

build : abstract_enemy.o hard_Game.o main.o player.o abstract_tower.o inferno.o map.o wizard.o default_Game.o low_Game.o medium_Game.o 

compile : abstract_enemy.o hard_Game.o main.o player.o abstract_tower.o inferno.o map.o wizard.o default_Game.o low_Game.o medium_Game.o
	${CC} ${CFLAGS} $^ -o gubarkir

run:
		./gubarkir

%.o: src/%.cpp
	${CC} ${CFLAGS} -c $< -o $@


abstract_enemy.o: src/abstract_enemy.cpp src/abstract_enemy.h
abstract_enemy.o: src/abstract_enemy.h
abstract_tower.o: src/abstract_tower.cpp src/abstract_tower.h
abstract_tower.o: src/abstract_tower.h
archer.o: src/archer.h src/abstract_tower.h
barbarian.o: src/barbarian.h src/abstract_enemy.h
cannon.o: src/cannon.h src/abstract_tower.h
crossbow.o: src/crossbow.h src/abstract_tower.h
default_Game.o: src/default_Game.cpp src/default_Game.h src/map.h \
 src/player.h src/cannon.h src/abstract_tower.h src/archer.h \
 src/crossbow.h src/wizard.h src/inferno.h src/barbarian.h \
 src/abstract_enemy.h src/rogue.h src/shieldman.h src/giant.h \
 src/hash_pair.h
default_Game.o: src/default_Game.h src/map.h src/player.h src/cannon.h \
 src/abstract_tower.h src/archer.h src/crossbow.h src/wizard.h \
 src/inferno.h src/barbarian.h src/abstract_enemy.h src/rogue.h \
 src/shieldman.h src/giant.h src/hash_pair.h
giant.o: src/giant.h src/abstract_enemy.h
hard_Game.o: src/hard_Game.cpp src/hard_Game.h src/default_Game.h \
 src/map.h src/player.h src/cannon.h src/abstract_tower.h src/archer.h \
 src/crossbow.h src/wizard.h src/inferno.h src/barbarian.h \
 src/abstract_enemy.h src/rogue.h src/shieldman.h src/giant.h \
 src/hash_pair.h
hard_Game.o: src/hard_Game.h src/default_Game.h src/map.h src/player.h \
 src/cannon.h src/abstract_tower.h src/archer.h src/crossbow.h \
 src/wizard.h src/inferno.h src/barbarian.h src/abstract_enemy.h \
 src/rogue.h src/shieldman.h src/giant.h src/hash_pair.h
hash_pair.o: src/hash_pair.h src/abstract_enemy.h
inferno.o: src/inferno.cpp src/inferno.h src/abstract_tower.h
inferno.o: src/inferno.h src/abstract_tower.h
low_Game.o: src/low_Game.cpp src/low_Game.h src/default_Game.h src/map.h \
 src/player.h src/cannon.h src/abstract_tower.h src/archer.h \
 src/crossbow.h src/wizard.h src/inferno.h src/barbarian.h \
 src/abstract_enemy.h src/rogue.h src/shieldman.h src/giant.h \
 src/hash_pair.h
low_Game.o: src/low_Game.h src/default_Game.h src/map.h src/player.h \
 src/cannon.h src/abstract_tower.h src/archer.h src/crossbow.h \
 src/wizard.h src/inferno.h src/barbarian.h src/abstract_enemy.h \
 src/rogue.h src/shieldman.h src/giant.h src/hash_pair.h
main.o: src/main.cpp src/low_Game.h src/default_Game.h src/map.h \
 src/player.h src/cannon.h src/abstract_tower.h src/archer.h \
 src/crossbow.h src/wizard.h src/inferno.h src/barbarian.h \
 src/abstract_enemy.h src/rogue.h src/shieldman.h src/giant.h \
 src/hash_pair.h src/medium_Game.h src/hard_Game.h
map.o: src/map.cpp src/map.h src/player.h src/cannon.h \
 src/abstract_tower.h src/archer.h src/crossbow.h src/wizard.h \
 src/inferno.h src/barbarian.h src/abstract_enemy.h src/rogue.h \
 src/shieldman.h src/giant.h src/hash_pair.h
map.o: src/map.h src/player.h src/cannon.h src/abstract_tower.h \
 src/archer.h src/crossbow.h src/wizard.h src/inferno.h src/barbarian.h \
 src/abstract_enemy.h src/rogue.h src/shieldman.h src/giant.h \
 src/hash_pair.h
medium_Game.o: src/medium_Game.cpp src/medium_Game.h src/default_Game.h \
 src/map.h src/player.h src/cannon.h src/abstract_tower.h src/archer.h \
 src/crossbow.h src/wizard.h src/inferno.h src/barbarian.h \
 src/abstract_enemy.h src/rogue.h src/shieldman.h src/giant.h \
 src/hash_pair.h
medium_Game.o: src/medium_Game.h src/default_Game.h src/map.h \
 src/player.h src/cannon.h src/abstract_tower.h src/archer.h \
 src/crossbow.h src/wizard.h src/inferno.h src/barbarian.h \
 src/abstract_enemy.h src/rogue.h src/shieldman.h src/giant.h \
 src/hash_pair.h
player.o: src/player.cpp src/player.h
player.o: src/player.h
rogue.o: src/rogue.h src/abstract_enemy.h
shieldman.o: src/shieldman.h src/abstract_enemy.h
wizard.o: src/wizard.cpp src/wizard.h src/abstract_tower.h
wizard.o: src/wizard.h src/abstract_tower.h






doc/doxyfile.inc: Doxyfile
	echo INPUT         =  ./src > doc/doxyfile.inc
	echo FILE_PATTERNS =  *.h $(SRCS) >> doc/doxyfile.inc

doc: doc/doxyfile.inc $(SRC)
	doxygen Doxyfile

clean :
		rm -rf *.o gubarkir
		rm -r doc
		mkdir doc

