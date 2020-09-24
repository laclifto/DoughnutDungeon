
all:
	g++ -g main.cpp items.cpp minotaur.cpp dragon.cpp npc.cpp dragonRoom.cpp waterfallRoom.cpp dropRoom.cpp musicalMinotaur.cpp secretGarden.cpp ironMaiden.cpp treasureRoom.cpp player.cpp space.cpp spaceList.cpp startRoom.cpp ratRoom.cpp utils.cpp -o prog

clean:
	rm -f *.o prog

debug:
	valgrind -v --leak-check=full --track-origins=yes prog  
