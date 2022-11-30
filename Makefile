CFLAGS = -O3 -std=c++11 -Wall proj.cpp -lm -o proj

proj: proj.cpp
	g++ $(CFLAGS)

run:
	./proj < input.txt


