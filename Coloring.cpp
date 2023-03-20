#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "Graphs.h"
#include "ExtraFuns.h"

using namespace std;

int Graph::Coloring_General() {

	unsigned int start_time = clock();

	// ������ ����� �������� ���� ������
	if (this->IsCompleteGraph()) { // ����� ���� ���� ������
		//��������� �������
		unsigned int end_time = clock();

		// ����� �������������� ����� � ������ ������
		cout << "===========General_Coloring===========" << endl;
		cout << endl;
		cout << "Chromatic number " << this->n << endl;
		cout << "Colors:" << endl;
		for (int i = 0; i < this->n; i++) {
			cout << i << " " << endl;
		}
		cout << endl;
		cout << endl;

		//����� �������
		unsigned int search_time = end_time - start_time;
		cout << "General_Coloring time " << search_time << endl;
		cout << endl;
		cout << "======================================" << endl;

		return this->n;
	}

	queue<Graph> q;

	queue<vector<int>> q_mas_unionverts;
	vector<int> mas_unionverts(n);
	for (int i = 0; i < n; i++)
		mas_unionverts[i] = i;
	Graph tmp = this->Mark_Graph(); //��������� � ������� ���� 

	q.push(tmp);
	q_mas_unionverts.push(mas_unionverts);


	Graph gr_res(tmp); // ���� ��� ������ 
	vector<int> resmas_unionverts(mas_unionverts);

	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		mas_unionverts = q_mas_unionverts.front();
		q_mas_unionverts.pop();

		pair <int, int> pair_nonadj_vert = tmp.PairNonAdjVert();
		int ind_v1 = pair_nonadj_vert.first;
		int ind_v2 = pair_nonadj_vert.second;

		int v1 = tmp.M[ind_v1 * tmp.n + ind_v1] - 10;
		int v2 = tmp.M[ind_v2 * tmp.n + ind_v2] - 10;

		// ����� ������ ����� �������� ����� ����� ���������� ���������
		Graph leftcase(tmp);
		leftcase.M[ind_v1 * leftcase.n + ind_v2] = 1;
		leftcase.M[ind_v2 * leftcase.n + ind_v1] = 1;


		if (leftcase.IsCompleteGraph()) { // ��������� ���� �� �������, ���� ������� ����������� ����������� �� �������, ��� ����� ����� ����� ������� ������� ����� (�� ������ ��������� �� ������������ �� ������� 1)
			if (gr_res.n > leftcase.n) {
				gr_res = leftcase;
				resmas_unionverts = mas_unionverts;
			}
		}
		else {
			q.push(leftcase);
			q_mas_unionverts.push(mas_unionverts);
		}

		// ������ ������, ����� ���������� �������
		mas_unionverts = LabelingUnionVerts(mas_unionverts, v1, v2);

		Graph rightcase = tmp.UnionPairVert(ind_v1, ind_v2); //��������� ������������� � ��� ��� �������������

		if (rightcase.IsCompleteGraph()) { // ��������� ���� �� �������, ���� ������� ����������� ����������� �� �������, ��� ����� ����� ����� ������� ������� ����� (�� ������ ��������� �� ������������ �� ������� 1)
			if (gr_res.n > rightcase.n) {
				gr_res = rightcase;
				resmas_unionverts = mas_unionverts;
			}
		}
		else {
			q.push(rightcase);
			q_mas_unionverts.push(mas_unionverts);
		}
	}

	//������������� ���� �������
	unsigned int end_time = clock();

	// ����� �������������� ����� � ������ ������
	cout << "===========General_Coloring===========" << endl;
	//cout << endl;
	cout << "Chromatic number " << gr_res.n << endl;
	//cout << "Colors:" << endl;
	//for (int i = 0; i < resmas_unionverts.size(); i++)
	//	cout << resmas_unionverts[i] << " ";
	cout << endl;
	//cout << endl;

	//����� �������
	unsigned int search_time = end_time - start_time;
	cout << "General_Coloring time " << search_time << endl;
	cout << endl;
	//cout << "======================================" << endl;
	return search_time;
}

pair <int, int> Graph::PairNonAdjVert() { //������������ ������� �� ����������
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (M[i * n + j] == 0)
				return { i, j };
	return { -1, -1 };
}

Graph Graph::UnionPairVert(int ind_v1, int ind_v2) {
	Graph tmp(*this);
	for(int i = 0; i < tmp.n; i++)
		if (M[ind_v2 * n + i] == 1) {
			tmp.M[ind_v1 * tmp.n + i] = 1;
			tmp.M[i * tmp.n + ind_v1] = 1;
		}
	tmp = tmp.ReduceVert(ind_v2);
	return tmp;
}

vector<int> Graph::LabelingUnionVerts(vector<int> label_mas, int v1, int v2) {
	for (int i = 0; i < label_mas.size(); i++)
		if (label_mas[i] == v2)
			label_mas[i] = v1;
	return label_mas;
}
