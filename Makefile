CFLAGS = -O3 -std=c++11 -Wall

proj: proj.cpp
	g++ $(CFLAGS) proj.cpp -lm -o proj

run: proj gerador
	./proj < p1_testeW.txt > output.txt
clear:
	rm -f proj gerador testfile


