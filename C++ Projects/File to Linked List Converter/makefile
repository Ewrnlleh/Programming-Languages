all:derle calistir

derle:

	g++ -I ./include -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include -o ./lib/Bagilliste.o -c ./src/Bagilliste.cpp
	g++ -I ./include -o ./lib/Test.o -c ./src/main.cpp
	g++ -I ./include ./src/Dugum.cpp ./src/Bagilliste.cpp ./src/main.cpp -o ./bin/Test
calistir:
	./bin/Test 