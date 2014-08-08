#include "Graph.h"

class TwoColor
{
public:
	TwoColor(Graph&);
	bool IsBipartite();
private:
	bool* marked;
	bool* color;
	bool isTwoColor;
	void DFS(Graph&, int);
};

TwoColor::TwoColor(Graph& gra)
	:marked(NULL), color(NULL), isTwoColor(true)
{
	int ver = gra.GetVertex();
	marked = new bool[ver];
	color = new bool[ver];
	for (int i = 0; i < ver; ++i)
		marked[i] = false;
	for (int i = 0; i < ver; ++i)
		color[i] = false;
	for (int s = 0; s < ver; ++s)
		if (!marked[s])
			DFS(gra, s);
}

void TwoColor::DFS(Graph& gra, int v)
{
	marked[v] = true;
	list<int>::iterator it = gra.GetAdj(v).begin();
	for (; it != gra.GetAdj(v).end(); ++it)
	{
		if (!marked[*it])
		{
			color[*it] = !color[v];
			DFS(gra, *it);
		}
		else if (color[*it] == color[v])
			isTwoColor = false;
	}
}

bool TwoColor::IsBipartite()
{
	return isTwoColor;
}