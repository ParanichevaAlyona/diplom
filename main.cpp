#include <iostream>
#include <vector>
#include <ctime>
#include "Graphs.h"
#include "ExtraFuns.h"
#include "Tests.h"

#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main() {

	//std::vector<int> arr = { 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0 };
	//std::vector<int> arr = { 0, 1, 0, 1, 0, 1, 1, 0, 1, 0 };
	int n = 75; //6
	//std::vector<int> arr = { 0, 1, 0, 1,   0, 1, 1,   0, 1,   0 };
	//std::vector<int> arr = { 0, 1, 1, 1,   0, 1, 1,   0, 1,   0 }; // полный граф n=4
	//std::vector<int> arr = { 0, 1, 0, 0, 0, 0,   0, 1, 0, 0, 0,   0, 1, 0, 0,  0, 1, 0,  0, 1,  0 }; //путь n=6
	//std::vector<int> arr = { 0, 1, 0, 0, 0, 1,   0, 1, 0, 0, 0,   0, 1, 0, 0,  0, 1, 0,  0, 1,  0 }; //цикл n=6
	// 
	//std::vector<int> arr = { 0, 0, 1, 1, 0, 1,   0, 1, 1, 0, 1,   0, 0, 1, 1,  0, 1, 0,  0, 1,  0 }; //рандомный связанный граф n=6
	// 
	//std::vector<int> arr = { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,   0, 1, 0, 0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0,   
	//0, 1, 1, 0, 0, 0, 0,    0, 1, 0, 0, 0, 0,    0, 1, 0, 0, 0,  0, 1, 1, 0,   0, 1, 0,   0, 1,  0 }; //10 вершин треугольники соед ребром
	//cout << "Enter the number of vertices in the graph" << endl;
	//cin >> n;

    
	//std::vector<int> arr = { 0, 1, 1, 1, 0, 0,   0, 1, 1, 1, 0,   0, 1, 0, 0,  0, 1, 0,  0, 1,  0 }; //n= 6, gr n1
	// 
	//std::vector<int> arr = { 0, 1, 1, 1, 0, 0, 0,  0, 1, 0, 0, 0, 0,   0, 1, 1, 0, 0,   0, 0, 0, 0,  0, 1, 1,  0, 1,  0 }; //n=7, возникновение ошибки

	//Graph A(7, arr);
	//cout << A.isChordalGraph() << endl;
	//Graph A(n);
	//A = A.Fill_Graph();
	//A.Gen_ChordalGr();

	//IndSet_test(A);


	//A.Gen_ChordalGr();

	//Chord_test(A);

	//isChord_test(400);
	//Graph A1(n);
	//A1 = A1.Fill_Graph();
	//A1.Gen_ChordalGr();

	//Graph A2(n);
	//A2 = A2.Fill_Graph();
	//A2.Gen_ChordalGr();

	//Graph A3(n);
	//A3 = A3.Fill_Graph();
	//A3.Gen_ChordalGr();

	//Graph A4(n);
	//A4 = A4.Fill_Graph();
	//A4.Gen_ChordalGr();

	//Graph A5(n);
	//A5 = A5.Fill_Graph();
	//A5.Gen_ChordalGr();
	
	//int res = 0;
	//res += ColorGeneralNum(13);
	//res += ColorGeneralNum(14);
	//res += ColorGeneralNum(15);
	//res += ColorGeneralNum(16);
	//res += ColorGeneralNum(17);
	//res = res / 5;
	//cout << res << " medium";

	int res = 0;
	res += ColoringGeneral_and_ColoringChord_forRandomChordGraph_test(23);
	res += ColoringGeneral_and_ColoringChord_forRandomChordGraph_test(24);
	res += ColoringGeneral_and_ColoringChord_forRandomChordGraph_test(25);
	res += ColoringGeneral_and_ColoringChord_forRandomChordGraph_test(26);
	res += ColoringGeneral_and_ColoringChord_forRandomChordGraph_test(27);
	res = res / 5;
	cout << res << " medium";

	//IndependentSet_AllAgorithms_test(148);
	//IndependentSet_AllAgorithms_test(149);
	//IndependentSet_AllAgorithms_test(150);
	//IndependentSet_AllAgorithms_test(151);
	//IndependentSet_AllAgorithms_test(152);
	//res = res / 5;
	//cout << res << " chord medium res";


	//res += ArrangeChordNumInd(247);
	//res += ArrangeChordNumInd(248);
	//res += ArrangeChordNumInd(249);
	//res += ArrangeChordNumInd(250);
	//res += ArrangeChordNumInd(251);
	//res += ArrangeChordNumInd(252);
	//res += ArrangeChordNumInd(253);
	//res = res / 7;
	//cout << res << "  arr res";

	//ArrangeChordNumInd(247);
	//ArrangeChordNumInd(248);
	//ArrangeChordNumInd(249);
	//ArrangeChordNumInd(250);
	//ArrangeChordNumInd(251);
	//ArrangeChordNumInd(252);
	//ArrangeChordNumInd(253);

	return 0;
}
