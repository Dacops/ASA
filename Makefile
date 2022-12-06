CFLAGS = -O3 -std=c++11 -Wall

proj: proj.cpp test.cpp
	g++ $(CFLAGS) proj.cpp -lm -o proj
	g++ $(CFLAGS) test.cpp -lm -o test

run: proj
	./proj < input.txt
runt: test
	./test < input.txt
clean:
	rm -f proj test


