#include <vector>
#include <list>

using namespace std;

class Graph
{
public:
	void init(int);
	int GetVertex();
	void addEdge(int, int);
	list<int>& GetAdj(int);
private:
	int vertex;
	int edge;
	vector<list<int> > adj;
};

void Graph::init(int ver)
{
	vertex = ver;
	edge = 0;
	for (int i = 0; i < ver; ++i)
		adj.push_back(list<int>());
}

int Graph::GetVertex()
{
	return vertex;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
	++edge;
}

list<int>& Graph::GetAdj(int v)
{
	return adj[v];
}