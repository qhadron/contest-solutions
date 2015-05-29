#include "sudoku.h"

using namespace std;

Cell::Cell(int X, int Y, int Value) : x(X), y(Y), value(Value) {
	if (!Value) {
		memset(possibleValues, true, sizeof(possibleValues));
		count();
	}
	else {
		possibilities = 0;
		memset(possibleValues, 0, sizeof(possibleValues));
	}
};
void Cell::notify() {
	for (Test* cur : tests) {
		cur->check();
	}
}
bool Cell::operator<(const Cell& rhs) {
	return possibleValues < rhs.possibleValues;
}
void Cell::count() {
	possibilities = 0;
	int tempvalue;
	for (int i = 1; i <= 9; ++i)
		if (possibleValues[i]) {
			++possibilities;
			tempvalue = i;
		}
	if (possibilities == 1) {
		value = tempvalue;
	}
}

void cellcount(Cell*& c) {
	c->count();
}

Test::Test(string Name) : name(Name) {
	cnt = 0;
	for (int i = 0; i < TEST_SIZE; ++i)
		cells[i] = nullptr;
	memset(missing, true, sizeof(missing));
};

void SimpleTest::check() {
	for (Cell* cur : cells) {
		if (cur != nullptr) {
			cur->count();
#ifdef _DEBUG
#endif
			if (cur->value || cur->possibilities < 1) {
				missing[cur->value] = false;
				cnt++;
			}
		}
	}
	for (Cell* cur : cells) {
		if (cur != nullptr) {
			for (int i = 1; i <= 9; ++i)
				if (!missing[i]) {
					cur->possibleValues[i] = false;
				}
			cur->count();
		}
	}
}

bool Test::operator<(const Test& rhs) {
	return cnt < rhs.cnt;
}

ostream& operator<<(ostream& os, const Cell& cell) {
	os << "Cell@(" << cell.x << "," << cell.y << "):" << endl;;
	for (int i = 0; i < cell.possibilities; ++i) {
		if (cell.possibleValues[i]) {
			os << (i + 1) << " ";
		}
	}
	return os;
}

ostream& operator<<(ostream& os, const Test& test) {
	os << "Test@" << test.name << ":" << endl;
	for (int i = 0; i < TEST_SIZE; ++i) {
		if (test.cells[i] != nullptr) {
			cout << *test.cells[i] << endl;
		}
	}
	return os;
}

void print() {
	for (int y = 0; y < BOARD_Y; ++y) {
		if (y % 3 == 0) {
			for (int i = 0; i < BOARD_X; ++i)
				printf("--");
			printf("\n");
		}
		for (int x = 0; x < BOARD_X; ++x) {
			cout << ((board[x][y]->value) ? (char) (board[x][y]->value + '0') : '?')
				<< (char) (((x + 1) % 3 == 0) ? '|' : ' ');
		}
		printf("\n");
	}
	for (int i = 0; i < BOARD_X; ++i)
		printf("--");
	printf("\n");
}

void printpossible() {
	for (int y = 0; y < BOARD_Y; ++y) {
		if (y % 3 == 0) {
			for (int i = 0; i < BOARD_X; ++i)
				printf("--");
			printf("\n");
		}
		for (int x = 0; x < BOARD_X; ++x) {
			cout << (char) (board[x][y]->possibilities + '0')
				<< (char) (((x + 1) % 3 == 0) ? '|' : ' ');
		}
		printf("\n");
	}
	for (int i = 0; i < BOARD_X; ++i)
		printf("--");
	printf("\n");
}

void exit() {
	for (int y = 0; y < BOARD_Y; ++y) {
		for (int x = 0; x < BOARD_X; ++x) {
			if (board[x][y] != nullptr) {
				delete board[x][y];
				board[x][y] = nullptr;
			}
		}
	}
	tests.clear();
	while (!pqueue.empty()) {
		auto T = pqueue.top();
		pqueue.pop();
		if (T != nullptr)
			delete T;
	}
}

void checkall() {
	for (auto it = tests.begin(); it != tests.end(); ++it) {
		(*it)->check();
	}
	pqueue.update(cellcount);
}

bool dfs(Cell* cur) {
	if (pqueue.empty())
		return true;
	if (cur == nullptr) {
		cur = pqueue.top();
		pqueue.pop();
	}
	assert(cur != nullptr);
	if (cur->value) {
		dprintf("[%d,%d] is %d\n", cur->x, cur->y, cur->value);
		//chose next best cell from priority_queue
		Cell* temp = pqueue.top();
		pqueue.pop();
		if (dfs(temp))
			return true;
		else {
			//remove side-effects
			if (temp->isGuess)
				pqueue.push(temp);
			return false;
		}
	}
	dprintf("At [%d,%d]\n", cur->x, cur->y);
	for (int i = 1, use; i <= 9; ++i) {
		if (cur->possibleValues[i]) {
			dprintf("Trying value %d at [%d,%d]\n", i, cur->x, cur->y);
			use = true;
			//row
			for (int x = 0; x < 9; ++x)
				if (board[x][cur->y]->value == i) {
					dprintf("\tFailed: Row test at [%d,%d]\n", x, cur->y);
					use = false;
					break;
				}
			if (!use)
				continue;
			//column
			for (int y = 0; y < 9; ++y)
				if (board[cur->x][y]->value == i) {
					dprintf("\tFailed: Col test at [%d,%d]\n", cur->x, y);
					use = false;
					break;
				}
			if (!use)
				continue;
			//grid
			for (int x = cur->x / 3, dx = 0; dx < 3; ++dx) {
				for (int y = cur->y / 3, dy = 0; use && dy < 3; ++dy) {
					if (board[x][y]->value == i) {
						dprintf("\tFailed: Grid test at [%d,%d]\n", x, y);
						use = false;
						break;
					}
				}
			}
			if (!use)
				continue;
			cur->possibilities = 1;
			cur->value = i;
			dprintf("\tSetting value of [%d,%d] to %d\n", cur->x, cur->y, cur->value);
			checkall();
			//chose next best cell from priority_queue
			Cell* temp = pqueue.top();
			pqueue.pop();
			if (dfs(temp)) {
				return true;
			}
			else {
				//reinsert node upon failure
				pqueue.push(temp);
			}
		}
	}
	return false;
}

Cell::~Cell() {
	this->tests.clear();
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
#if _VERBOSE
	freopen("output.txt", "w", stdout);
#endif
	while (cin) {
		puts("--------------------------------------------------------------------------------");
		for (int y = 0, temp; y < BOARD_Y; ++y) {
			for (int x = 0; x < BOARD_X; ++x) {
				if (!(cin >> temp)) {
					if (y != 0 || x != 0)
						cout << "Not enough info!" << endl;
					else
						cout << "Done reading" << endl;
					exit();
					return 0;
				}
				board[x][y] = new Cell(x + 1, y + 1, temp);
			}
		}
		print();
		//test each row
		for (int i = 0; i < BOARD_Y; ++i) {
			SimpleTest* temp = new SimpleTest((string)"Row Test " + (char) (i + 1 + '0'));
			for (int j = 0; j < BOARD_X; ++j) {
				temp->cells[j] = board[j][i];
			}
			tests.push_back(temp);
		}
		//test each column
		for (int i = 0; i < BOARD_X; ++i) {
			SimpleTest* temp = new SimpleTest((string)"Column Test " + (char) (i + 1 + '0'));
			for (int j = 0; j < BOARD_Y; ++j) {
				temp->cells[j] = board[i][j];
			}
			tests.push_back(temp);
		}
		//test each grid
		for (int y = 0, cnt = 0; y < 3; ++y)
			for (int x = 0; x < 3; ++x) {
				SimpleTest* temp = new SimpleTest((string)"Grid test " + (char) (++cnt + '0'));
				for (int dx = 0, i = 0; dx < 3; ++dx) {
					for (int dy = 0; dy < 3; ++dy) {
						temp->cells[i++] = board[x * 3 + dx][y * 3 + dy];
					}
				}
				tests.push_back(temp);
			}




#if _VERBOSE
		printf("%d tests in total:\n", tests.size());
		for (Test* cur : tests) {
			cout << (*cur) << endl;
		}
#endif
		bool succeeded = true;
		for (int i = 0; i < BOARD_X; ++i)
			for (int j = 0; j < BOARD_Y; ++j)
				if (!board[i][j]->value)
					pqueue.push(board[i][j]);
		pqueue.update(cellcount);

		succeeded = dfs(nullptr);

		if (false)
		while (!pqueue.empty()) {
			checkall();
			Cell* cur = pqueue.top();
			pqueue.pop();
			assert(cur != nullptr);
			dprintf("At (%d,%d): val:%4d pos:%4d\n", cur->x, cur->y, cur->value, cur->possibilities);
			if (cur->possibilities) {
				if (cur->value != 0) {
					dprintf("The only possible number in [%d,%d] is %d.\n", cur->x, cur->y, cur->value);
					continue;
				}
				else {
					cout << "Unexpected error" << endl;
					succeeded = false;
					break;
				}
			}
			if (cur->possibilities > 1) {
				cout << "Not enough info " << endl;
				succeeded = false;
				break;
			}
		}
		if (!succeeded) {
			cout << "Failed. Current board: " << endl;
		}


		print();
		exit();
	}
	return 0;
}