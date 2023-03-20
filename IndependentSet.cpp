#include <iostream>
#include <queue>
#include <vector>

#include "Graphs.h"

using namespace std;

vector<int> Graph::Independent_Set() {
	
	queue<Graph> q;
	Graph tmp = this->Mark_Graph();         //��������� � ������� ���� 
	q.push(tmp);

	Graph gr_res; // ���� ��� ������ 

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		int v = tmp.Find_Ver_Most_Rel();    //���� ������� � ���������� ������ �����
		Graph tmpv(tmp.ReduceVert(v));      //������� ��� ������� � ������� ����� ����
		if (!tmpv.Is_empty_matrix())        // ��������� �������� �� ��� ����� � �����
			q.push(tmpv);                   // ���� ��, ��������� ���� � ������� ������ ������ ������� ���������
		else if (gr_res.n < tmpv.n)
			gr_res = tmpv;                  //���������� ���� ��� ����� � ����� ������ ���� ���������� ������ ������ ��� �����������
		// ���� ������� �� �� �������, � �� �����
		//v = tmp.Find_Ver_Less_Rel();        //���� ������� � ���������� ������ ����� ????
		                                    // ���� ������� ������� ��� ������������ ��������� �������  ????
		Graph tmpe = tmp.ReduceNeighborVert(v); //������� ������� ������ ������������ ������� � ���� ������������
		if (!tmpe.Is_empty_matrix())
			q.push(tmpe);
		else if (gr_res.n < tmpe.n)
			gr_res = tmpe;
	}
	
	vector<int> res;
	for (int i = 0; i < gr_res.n; i++) {
		res.push_back(gr_res.M[i * gr_res.n + i] - 10);
	}
	return res;
}

vector<int> Graph::Independent_Set2() {

	queue<Graph> q;
	Graph tmp = this->Mark_Graph();         //��������� � ������� ���� 
	q.push(tmp);

	Graph gr_res; // ���� ��� ������ 

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		int v = tmp.Find_Ver_Most_Rel();    //���� ������� � ���������� ������ �����
		Graph tmpv(tmp.ReduceVert(v));      //������� ��� ������� � ������� ����� ����
		if (!tmpv.Is_empty_matrix())        // ��������� �������� �� ��� ����� � �����
			q.push(tmpv);                   // ���� ��, ��������� ���� � ������� ������ ������ ������� ���������
		else if (gr_res.n < tmpv.n)
			gr_res = tmpv;                  //���������� ���� ��� ����� � ����� ������ ���� ���������� ������ ������ ��� �����������
		// ���� ������� �� �� �������, � �� �����
		v = tmp.Find_Ver_Less_Rel();        //���� ������� � ���������� ������ ����� ????
											// ���� ������� ������� ��� ������������ ��������� �������  ????
		Graph tmpe = tmp.ReduceNeighborVert(v); //������� ������� ������ ������������ ������� � ���� ������������
		if (!tmpe.Is_empty_matrix())
			q.push(tmpe);
		else if (gr_res.n < tmpe.n)
			gr_res = tmpe;
	}

	vector<int> res;
	for (int i = 0; i < gr_res.n; i++) {
		res.push_back(gr_res.M[i * gr_res.n + i] - 10);
	}
	return res;
}
