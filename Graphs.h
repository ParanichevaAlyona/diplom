#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>

using namespace std;

class Graph
{
private:
    int n;
    int* M;
public:
    Graph();
    Graph(int _n);
    Graph(int _n, std::vector<int> _M);
    Graph(const Graph& tmp);
    ~Graph();

    const Graph& operator = (const Graph&);
    bool operator == (const Graph&) const;

    int GetN();
    int* GetM();
    Graph Mark_Graph();
    Graph ReduceVert(int v);
    int Find_Ver_Most_Rel();
    int Find_Ver_Less_Rel();
    Graph ReduceNeighborVert(int v);
    bool IsCompleteGraph();
    Graph Fill_Graph();

    void Gen_ChordalGr();
    bool IsCompleteArea(vector<int> arr, int* _M) const;
    int SimplVer();
    bool isChordalGraph() const;
    vector<int> Independent_set_for_ChordalGr_Absorb_Ver();
    int AbsorbVer();
    int ClickNumber(int);
    int Coloring_for_ChordalGr();
    vector<int> Independent_set_for_ChordalGr_Simpl_Ver();
    bool Is_empty_matrix() const;

    vector<int> Independent_Set();
    vector<int> Independent_Set2();

    int Coloring_General();
    pair <int, int> PairNonAdjVert();
    Graph UnionPairVert(int, int);
    static vector<int> LabelingUnionVerts(vector<int>, int, int);

    int Check_Cycle_with_Vert(int, std::vector<int>);
    int Find_Unused_Vert(int top, std::vector<int> used);

    void ClearM();
    int ProcentEdges();

	friend istream& operator >> (istream& input, Graph& g)
	{

		for (int i = 0; i < g.n * g.n; i++)
			input >> g.M[i];
		return input;
	}

	friend ostream& operator << (ostream& output, const Graph& g)
	{
        output << "Quantity of vertex is " << g.n << endl;
        output << "The adjacency matrix: ";
        for (int i = 0; i < g.n * g.n; i++)
        {
            if (i % g.n == 0)
                output << endl;
            output << setw(5) << setprecision(2) << right << g.M[i];
        }
        output << endl;
		return output;
	}
};

#endif