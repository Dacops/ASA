CFLAGS = -O3 -std=c++11 -Wall

proj: proj.cpp
	g++ $(CFLAGS) proj.cpp -lm -o proj
	g++ $(CFLAGS) ladrilho_valido.cpp -lm -o gerador

run: proj gerador
	./gerador args > testfile
	./proj < testfile
clear:
	rm -f proj gerador testfile


