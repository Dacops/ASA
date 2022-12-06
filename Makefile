CFLAGS = -O3 -std=c++11 -Wall

proj: proj.cpp
	g++ $(CFLAGS) proj.cpp -lm -o proj

run: proj
	./proj < input.txt
clean:
	rm -f proj


