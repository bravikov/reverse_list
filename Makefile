reverse_list: reverse_list.cpp
	g++ -Wall -std=c++14 -o reverse_list reverse_list.cpp

clean:
	rm -f reverse_list
