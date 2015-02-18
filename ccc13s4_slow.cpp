#include <iostream>
#include <vector>

#define BFS

#ifdef BFS
#include <queue>
#endif

using namespace std;

typedef unsigned int uint;

#define MAX 1000000
int n, m, x, y;


class PEOPLE
{
public:
	vector<PEOPLE*> shorter;
	PEOPLE() {
		shorter.reserve(9);
	}
#ifdef BFS
	int index;
#elif _DEBUG
	int index;
#endif // _DEBUG
};

PEOPLE* a, *b;
bool found = 0;
#ifdef DFS
void dfs(PEOPLE* p)
{
#ifdef _DEBUG
	cout << p->index << " ";
#endif // _DEBUG
	if (p == b)
	{
		found = true;
		return;
	}
	if (p->shorter.size() == 0) return;
	for (uint i = 0; i < (p->shorter.size()); i++)
		dfs((p->shorter[i]));
}

void dfs2(PEOPLE* p)
{
	if (p == a)
	{
		found = true;
		return;
	}
	if (p->shorter.size() == 0) return;
	for (uint i = 0; i < (p->shorter.size()); i++)
		dfs2((p->shorter[i]));
}
#endif

vector<bool> t;
bool bfs(PEOPLE* start,PEOPLE * target) {
	t.assign(n,0);
	queue<PEOPLE*> steps;
	PEOPLE * person=start;
	t[person->index] = 1;
	steps.push(start);
	while (!steps.empty()){
		person = steps.front(); steps.pop();
#ifdef _DEBUG
		cout << person->index << " ";
#endif
		if (person == target) return true;
		for (vector<PEOPLE*>::iterator it = (person)->shorter.begin(); it != (person)->shorter.end(); ++it) {// PEOPLE* i : (person)->shorter) {
			if (!t[(*it)->index]) {
				t[(*it)->index] = 1, steps.push((*it));
			}
		}
	}
#ifdef _DEBUG
	cout << "\n";
#endif
	return false;
}

PEOPLE p[MAX+1];

int main(void)
{
#ifdef PROFILE
	freopen("0.input.txt", "r", stdin);
#endif
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		p[x].index = x; p[y].index = y;
		p[x].shorter.push_back(&p[y]);
	}
	cin >> x >> y;
	a = &p[x];
	b = &p[y];
#ifdef BFS
	if (bfs(a, b)) cout << "yes" << endl;
	else if (bfs(b,a)) cout << "no" << endl;
	else cout << "unknown" << endl;
#endif
#ifdef DFS
	dfs(a);
#ifdef _DEBUG
	cout << endl;
#endif
	if (found) {
		cout << "yes" << endl;
		return 0;
	}
	found = false;
	dfs2(b);
	if (found) {
		cout << "no" << endl;
		return 0;
	}
	cout << "unknown" << endl;
#endif
}

