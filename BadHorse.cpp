#include <iostream>
#include <fstream>
#include "SymbolGraph.h"

//using namespace std;

ifstream& OpenFile(ifstream& in, const string& filename)
{
	in.close();
	in.clear();
	in.open(filename.c_str());
	return in;
}

ofstream& OpenFile(ofstream& out, const string& filename)
{
	out.close();
	out.clear();
	out.open(filename.c_str());
	return out;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
		throw runtime_error("wrong number of arguments");

	ifstream infile;
	if (!OpenFile(infile, argv[1]))
		throw runtime_error("no input file");

	ofstream outfile;
	if (!OpenFile(outfile, argv[2]))
		throw runtime_error("no input file");

	int nCases;
	infile >> nCases;

	for (int index = 1; index <= nCases; ++index)
	{
		int nLines;
		infile >> nLines;
		/* store current case into outbuf */
		ostringstream outbuf;
		for (int i = 0; i < nLines; ++i)
		{
			string str1, str2;
			infile >> str1 >> str2;
			outbuf << str1 << " " << str2 << "\n";
		}

		SymbolGraph sgra(outbuf.str(), nLines);
		TwoColor bip(sgra.GetGraph());

		outfile << "Case #" << index << ": " << (bip.IsBipartite() ? "YES" : "NO") << endl;
	}

	return 0;
}