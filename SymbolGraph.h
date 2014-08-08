#include <sstream>
#include <map>
#include "TwoColor.h"

//using namespace std;

class SymbolGraph
{
public:
	SymbolGraph(string&, int);
	Graph& GetGraph();
private:	
	map<string, int> st;
	Graph gra;
};

SymbolGraph::SymbolGraph(string& oneCase, int nLines)
{
	/* construct st */
	istringstream inbuf(oneCase);
	for (int i = 0; i < nLines * 2; ++i)
	{
		string key;
		inbuf >> key;
		st.insert(make_pair(key, st.size()));
	}
	/* construct gra */
	inbuf.str(oneCase);
	gra.init(st.size());
	for (int i = 0; i < nLines; ++i)
	{
		string key1, key2;
		inbuf >> key1 >> key2;
		gra.addEdge(st[key1], st[key2]);
	}
}

Graph& SymbolGraph::GetGraph()
{
	return gra;
}