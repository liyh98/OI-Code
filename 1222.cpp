#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#include <climits>
#include <queue>
#include <functional>
#include <iostream>
#include <fstream>
using namespace std;
#pragma warning (disable : 4996)

ifstream in;
ofstream out;
struct node
{
	int x1, y1, x2, y2;
	inline int area() const
	{
		return x2 > x1&&y2 > y1 ? (x2 - x1)*(y2 - y1) : 0;
	}
};

node overlap(node a, node b)
{
	int x1 = max(a.x1, min(a.x2, b.x1)), y1 = max(a.y1, min(a.y2, b.y1));
	int x2 = min(a.x2, max(a.x1, b.x2)), y2 = min(a.y2, max(a.y1, b.y2));
	return { x1,y1,x2,y2 };
}

node get()
{
	int a, b, c, d;
	in >> a >> b >> c >> d;
	return { a,b,c,d };
}

int main()
{
	in.open("billboard.in");
	out.open("billboard.out");
	node r1 = get(), r2 = get(), truck = get();
	out << r1.area() + r2.area() - overlap(r1, truck).area() - overlap(r2, truck).area();
	in.close();
	out.close();
	return 0;
}