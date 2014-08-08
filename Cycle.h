#include "Graph.h"

//using namespace std;

class Cycle
{
public:
	Cycle(Graph&);
	bool HasCycle();
private:
	bool* marked;
	bool hasCycle;
	void DFS(Graph&, int, int);
};

Cycle::Cycle(Graph& gra):marked(NULL), hasCycle(false)
{
	int ver = gra.GetVertex();
	marked = new bool[ver];
	for (int i = 0; i < ver; ++i)
		marked[i] = false;
	for (int s = 0; s < ver; ++s)
		if (!marked[s])
			DFS(gra, s, s);
}

void Cycle::DFS(Graph& gra, int v, int u)
{
	marked[v] = true;
	list<int>::iterator it = gra.GetAdj(v).begin();
	for (; it != gra.GetAdj(v).end(); ++it)
	{
		if (!marked[*it])
			DFS(gra, *it, v);
		else if (*it != u)
			hasCycle = true;
	}
}

bool Cycle::HasCycle()
{
	return hasCycle;
}