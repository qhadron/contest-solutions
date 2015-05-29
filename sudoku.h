#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stack>

#define TEST_SIZE 10

#define BOARD_X 9
#define BOARD_Y 9

#define _VERBOSE 0

#ifdef _DEBUG
#define dprintf printf
#else
#define dprintf(x) 
#endif

#ifdef _VERBOSE
#define vprintf printf
#else
#define vprintf(x) 
#endif

using namespace std;

struct Test;
struct Cell;

struct Cell {
	int x, y;
	int value;
	bool isGuess;
	list<Test*> tests;
	bool possibleValues[10];
	int possibilities;
	Cell(int X, int Y, int Value);
	void notify();
	bool operator<(const Cell& rhs);
	void count();
	~Cell();
};

struct Test {
	int cnt;
	bool missing[10];
	string name;
	Cell* cells[TEST_SIZE];
	Test(string Name);
	virtual void check(){};
	bool operator<(const Test& rhs);
};

struct SimpleTest : Test {
	SimpleTest(string Name) : Test(Name) {}
	virtual void check();
};

//test based on the idea that if N cells share the same N possibilites only, then
//if another cell also shares those possibilites, but has other options,
//then the other cell cannot be contain one of the previous conditions
struct SubsetTest : Test {
	SubsetTest(string Name) : Test(Name) {}
};

bool dfs(Cell* cur);

struct Comparator
{
	bool operator() (const Cell* a, const Cell* b) {
		return a->possibilities > b->possibilities;
	}
};

template <typename T, class Container, class Comp>
class priority_queue {
public:
	priority_queue() {
		make_heap(c.begin(), c.end(), Comp());
	}
	priority_queue(priority_queue& other) {
		c(other.c);
		make_heap(c.begin(), c.end(), Comp());
	}
	void push(T val) {
		c.push_back(val);
		std::push_heap(c.begin(), c.end(), Comp());
	}
	void pop() {
		assert(is_heap(c.begin(), c.end(), Comp()));
		pop_heap(c.begin(), c.end(), Comp());
		c.pop_back();
	}
	T top() {
		assert(!c.empty());
		return (c.front());
	}
	void update() {
		make_heap(c.begin(), c.end(), Comp());
		assert(is_heap(c.begin(), c.end(), Comp()));
#ifdef _DEBUG
		cout << "updated" << endl;
#endif
	}
	void update(void(*f)(T&)) {
		for (auto it = c.begin(); it != c.end(); ++it)
			f(*it);
		update();
	}
	bool empty() {
		return c.empty();
	}
	Container base_val(){
		return Container(c);
	}
	Container& container_base() {
		return c;
	}
	size_t size() {
		return c.size();
	}
	void sort() {
		sort_heap(c.begin(), c.end, Comp());
	}
private:
	Container c;
};

Cell* board[BOARD_X][BOARD_Y];
list<Test*> tests;

priority_queue<Cell*, vector<Cell*>, Comparator> pqueue;

