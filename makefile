final: card_demo.o player.o card.o deck.o
	g++ -otest card_demo.o player.o card.o deck.o
driver: card_demo.cpp player.h deck.h card.h
	g++ -c card_demo.cpp
player: player.cpp player.h card.h
	g++ -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -c deck.cpp
card.o: card.cpp card.h
	g++ -std=c++11 -c card.cpp