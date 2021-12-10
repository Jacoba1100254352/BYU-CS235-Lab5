all:
	clear
	g++ -std=c++11 main.cpp QS.cpp -o Lab5
	./Lab5
	bash check.sh
