compiler = g++
flags = -std=c++17 -lstdc++fs

compile: LinearRegression.o vectors.o main.o
	$(compiler) LinearRegression.o vectors.o main.o $(flags) -o main

vectors.o: library/vectors.cpp
	$(compiler) -c library/vectors.cpp

main.o: src/main.cpp
	$(compiler) -c src/main.cpp

LinearRegression.o: library/LinearRegression.cpp
	$(compiler) -c library/LinearRegression.cpp 

clean:
	rm *.o main

run: main
	./main
