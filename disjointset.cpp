
/*
    http://en.wikipedia.org/wiki/Disjoint-set_data_structure
    Disjoint set:
        --all elements are in sets
        --if elements have same number, then they are in same set
    union(x,y)  -- joins x and y
    find(x)     --finds the set x belongs to
    make_set(x) --make an empty set x
*/

#define MAX 1000

int p[MAX],r[MAX];  //parent(representation), rank (almost depth)

void make_set(int x) {
    p[x]=x; //set parent to itself
    r[x]=0;
}

void find(int x) {
    return (x!=p[x])?p[x]=find(p[x]):p[x];
}

void union(int x, int y) {
	x = find(x);y = find(y);
	if (x == y) return;
	if (r[x] < r[y])
        p[x] = y;
    else {
        p[y] = x;
        if (r[x]==r[y])r[y]++;
    }
}

