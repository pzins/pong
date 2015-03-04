sfml-app : main.o game.o player.o ball.o bonus.o speedBonus.o lengthBonus.o speedBallBonus.o
	g++ main.o game.o player.o ball.o bonus.o speedBonus.o lengthBonus.o speedBallBonus.o -o sfml-app -pthread -std=c++11 -L /home/pierre/SFML/lib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o : main.cpp game.cpp player.cpp ball.cpp bonus.cpp speedBonus.cpp speedBallBonus.cpp lengthBonus.cpp game.h player.h ball.h bonus.h speedBonus.h lengthBonus.h speedBallBonus.h
	g++ -c main.cpp game.cpp player.cpp ball.cpp bonus.cpp speedBonus.cpp lengthBonus.cpp speedBallBonus.cpp -pthread -std=c++11 -I /home/pierre/SFML/include

clean :
	rm sfml-app *.o
