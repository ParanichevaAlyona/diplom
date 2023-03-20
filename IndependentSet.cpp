#include <iostream>
#include <queue>
#include <vector>

#include "Graphs.h"

using namespace std;

vector<int> Graph::Independent_Set() {
	
	queue<Graph> q;
	Graph tmp = this->Mark_Graph();         //маркируем и создаем граф 
	q.push(tmp);

	Graph gr_res; // граф для ответа 

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		int v = tmp.Find_Ver_Most_Rel();    //ищем вершину с наибольшим числом ребер
		Graph tmpv(tmp.ReduceVert(v));      //удаляем эту вершину и создаем новый граф
		if (!tmpv.Is_empty_matrix())        // проверяем остались ли еще ребра в графе
			q.push(tmpv);                   // если да, добавляем граф в очередь дальше искать независ множество
		else if (gr_res.n < tmpv.n)
			gr_res = tmpv;                  //записываем граф без ребер в ответ только если количество вершин больше уже записанного
		// надо удалять ту же вершину, а не новую
		//v = tmp.Find_Ver_Less_Rel();        //ищем вершину с наименьшим числом ребер ????
		                                    // надо удалить вершины явл окрестностью найденной вершины  ????
		Graph tmpe = tmp.ReduceNeighborVert(v); //удаляем вершину являющ окрестностью вершины с наим окрестностью
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
	Graph tmp = this->Mark_Graph();         //маркируем и создаем граф 
	q.push(tmp);

	Graph gr_res; // граф для ответа 

	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		int v = tmp.Find_Ver_Most_Rel();    //ищем вершину с наибольшим числом ребер
		Graph tmpv(tmp.ReduceVert(v));      //удаляем эту вершину и создаем новый граф
		if (!tmpv.Is_empty_matrix())        // проверяем остались ли еще ребра в графе
			q.push(tmpv);                   // если да, добавляем граф в очередь дальше искать независ множество
		else if (gr_res.n < tmpv.n)
			gr_res = tmpv;                  //записываем граф без ребер в ответ только если количество вершин больше уже записанного
		// надо удалять ту же вершину, а не новую
		v = tmp.Find_Ver_Less_Rel();        //ищем вершину с наименьшим числом ребер ????
											// надо удалить вершины явл окрестностью найденной вершины  ????
		Graph tmpe = tmp.ReduceNeighborVert(v); //удаляем вершину являющ окрестностью вершины с наим окрестностью
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
