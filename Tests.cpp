#include <iostream>
#include <vector>
#include <ctime>
#include "Graphs.h"
#include "ExtraFuns.h"
#include "Tests.h"

using namespace std;

void Gen_Chord_test(int n) {
	//unsigned int start_time = clock();

	int res = 0;
	for (int i = 0; i < 30; i++) {
		Graph A(n);
		A = A.Fill_Graph();

		//res += A.Gen_ChordalGr();
	}

	res = res / 30;
	cout << "RESSSSSSSSS " << res << endl;

	//unsigned int end_time = clock();
	//unsigned int search_time = end_time - start_time;
	//cout << "---------------------------" << endl;
	//cout << search_time << " Gen Chord test time" << endl;
	//cout << "---------------------------" << endl;
	//cout << endl;
}

void isChord_test(int n) {
	int res = 0;
	for (int i = 0; i < 1; i++) {
		Graph A(n);
		A = A.Fill_Graph();
		A.Gen_ChordalGr();
		unsigned int start_time = clock();


		bool result = A.isChordalGraph();

		unsigned int end_time = clock();

		//if (result) {
		//	cout << "The graph is chordal" << endl << endl;
		//}
		//else {
		//	cout << "The graph is not chordal" << endl << endl;
		//}

		unsigned int search_time = end_time - start_time;
		res += search_time;
		cout << "---------------------------" << endl;
		//cout << search_time << " Is Chord test time" << endl;
		//cout << "---------------------------" << endl;
	}
	res = res / 1;
	cout << "RESSSSSSSSS " << res;
}

void IndSet_test(Graph& A) {
	unsigned int start_time = clock();

	vector<int> indep_set = A.Independent_Set();

	unsigned int end_time = clock();

	for (int i = 0; i < indep_set.size(); i++)
		cout << indep_set[i] << " ";
	cout << endl;

	unsigned int search_time = end_time - start_time;
	cout << "---------------------------" << endl;
	cout << search_time << " Independent Set General test time" << endl;
	cout << "---------------------------" << endl;


	indep_set.clear();
	/*unsigned int */ start_time = clock();

	indep_set = A.Independent_Set2();

	/*unsigned int*/ end_time = clock();

	for (int i = 0; i < indep_set.size(); i++)
		cout << indep_set[i] << " ";
	cout << endl;

	/*unsigned int*/ search_time = end_time - start_time;
	cout << "---------------------------" << endl;
	cout << search_time << " 22222 Independent Set General test time" << endl;
	cout << "---------------------------" << endl;
}

void IndSetChord_absorbvert_test(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	A.Gen_ChordalGr();

	unsigned int start_time = clock();

	vector<int> indep_set = A.Independent_set_for_ChordalGr_Absorb_Ver();

	unsigned int end_time = clock();

	for (int i = 0; i < indep_set.size(); i++)
		cout << indep_set[i] << " ";
	cout << endl;

	unsigned int search_time = end_time - start_time;
	cout << "---------------------------" << endl;
	cout << search_time << " Independent Set for Chordal Graphs (absorbvert) test time" << endl;
	cout << "---------------------------" << endl;
}

void IndSetChord_simplvert_test(Graph &A) {
	unsigned int start_time = clock();

	vector<int> indep_set = A.Independent_set_for_ChordalGr_Simpl_Ver();

	unsigned int end_time = clock();

	for (int i = 0; i < indep_set.size(); i++)
		cout << indep_set[i] << " ";
	cout << endl;

	unsigned int search_time = end_time - start_time;
	cout << "---------------------------" << endl;
	cout << search_time << " Independent Set for Chordal Graphs (simplvert) test time" << endl;
	cout << "---------------------------" << endl;
}

void ColoringGeneral_forChord_test(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	A.Gen_ChordalGr();
	A.Coloring_General();
}

void ColoringChord_test(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	A.Gen_ChordalGr();
	A.Coloring_for_ChordalGr();
}

void ColoringGeneral_forRandomGenGraph_test(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	A.Coloring_General();
}

int ColoringGeneral_and_ColoringChord_forRandomChordGraph_test(int n) {
	Graph A(n);
	int p = 0;
	while (p < 80 || p > 83) {
		A.ClearM();
		A = A.Fill_Graph();
		A.Gen_ChordalGr();
		p = A.ProcentEdges();
	}

	cout << A.ProcentEdges() << " procent" << endl;

	//A.Coloring_for_ChordalGr();
	return A.Coloring_General();
}

void IndependentSet_AllAgorithms_test(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	A.Gen_ChordalGr();

	cout << "---------------------------" << endl;
	cout << A.ProcentEdges() << " procent" << endl;
	unsigned int start_time = clock();

	vector<int> indep_set = A.Independent_set_for_ChordalGr_Simpl_Ver();

	unsigned int end_time = clock();

	//for (int i = 0; i < indep_set.size(); i++)
	//	cout << indep_set[i] << " ";
	//cout << endl;

	unsigned int search_time = end_time - start_time;
	//cout << "---------------------------" << endl;
	cout << search_time << " SSSSS Independent Set for Chordal Graphs (simplvert) test time" << endl;
	//cout << "---------------------------" << endl;

	indep_set.clear();


	start_time = clock();

	indep_set = A.Independent_set_for_ChordalGr_Absorb_Ver();

	end_time = clock();

	//for (int i = 0; i < indep_set.size(); i++)
	//	cout << indep_set[i] << " ";
	//cout << endl;

	search_time = end_time - start_time;
	//cout << "---------------------------" << endl;
	cout << search_time << " AAAAA Independent Set for Chordal Graphs (absorbvert) test time" << endl;
	//cout << "---------------------------" << endl;

	indep_set.clear();

	//start_time = clock();

	//indep_set = A.Independent_Set2();

	//end_time = clock();

	//for (int i = 0; i < indep_set.size(); i++)
	//	cout << indep_set[i] << " ";
	//cout << endl;

	//search_time = end_time - start_time;
	//cout << "---------------------------" << endl;
	//cout << search_time << " GGGGG Independent Set General test time" << endl;
	//cout << "---------------------------" << endl;
}

int ArrangeChordNumInd(int n) {
	//в цикле фор создаем хорд граф нужного размера
	//инсет возвращает число независимости
	//складываем со всеми потом делим на количество операций
	//время не нужно
	int res = 0;
	int N = 1;
	for (int i = 0; i < N; i++) {
		Graph A(n);
		A = A.Fill_Graph();
		A.Gen_ChordalGr();
		cout << A.ProcentEdges() << " procent" << endl;

		vector<int> indep_set = A.Independent_set_for_ChordalGr_Simpl_Ver();
		for (int i = 0; i < indep_set.size(); i++)
			cout << indep_set[i] << " ";
		cout << endl;
		res += indep_set.size();
		indep_set.clear();

	}



	res = res / N;
	cout << "num verts " << n << endl;
	cout << "arrange num of indpendence " << res << endl;
	cout << endl;
	return res;
}

int NumIndGeneal(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	
	cout << "---------------------------" << endl;
	cout << A.ProcentEdges() << " procent" << endl;
	vector<int> indep_set = A.Independent_Set2();

	for (int i = 0; i < indep_set.size(); i++)
		cout << indep_set[i] << " ";
	cout << endl;

	
	cout << n << " num verts" << endl;
	cout << indep_set.size() << " IndSet General"  << endl;

	return indep_set.size();
}

int NumIndGenealAndChord(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	A.Gen_ChordalGr();
	int res = 0;
	cout << "---------------------------" << endl;
	cout << A.ProcentEdges() << " procent" << endl;
	vector<int> indep_set = A.Independent_Set2();
	for (int i = 0; i < indep_set.size(); i++)
		cout << indep_set[i] << " ";
	cout << endl;
	vector<int> indep_set2 = A.Independent_set_for_ChordalGr_Simpl_Ver();
	return res;
}

int ColorChordNum(int n) {
	Graph A(n);
	A = A.Fill_Graph();
	A.Gen_ChordalGr();

	int res = 0;
	cout << "---------------------------" << endl;
	cout << A.ProcentEdges() << " procent" << endl;
	res = A.Coloring_for_ChordalGr();
	//for (int i = 0; i < indep_set.size(); i++)
	//	cout << indep_set[i] << " ";
	//cout << endl;

	return res;
}

int ColorGeneralNum(int n) {
	Graph A(n);
	A = A.Fill_Graph();

	int res = 0;
	cout << "---------------------------" << endl;
	cout << A.ProcentEdges() << " procent" << endl;
	res = A.Coloring_General();
	//for (int i = 0; i < indep_set.size(); i++)
	//	cout << indep_set[i] << " ";
	//cout << endl;

	return res;
}
