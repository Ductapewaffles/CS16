all: vertical palindrome selectionSort

vertical: vertical.cpp
	g++ -o vertical vertical.cpp -Wall -std=c++17

palindrome: palindrome.cpp
	g++ -o palindrome palindrome.cpp pfunctions.cpp

selectionSort: selectionSort.cpp sfunctions.cpp
	g++ -o selectionSort selectionSort.cpp sfunctions.cpp

clean: 
	rm -f vertical palindrome selectionSort
