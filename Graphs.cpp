#include <vector>
#include "Graphs.h"
#include "ExtraFuns.h"

Graph::Graph()
{
    n = 0;
    M = nullptr;
}
Graph::Graph(int _n)
{
    n = _n;
    M = new int[n * n];
}
Graph::Graph(int _n, std::vector<int> arr) // по треугольнику(массиву)
{
    n = _n;
    M = new int[n * n];
    int count = 0;

    for (int i = 0; i < n; i++) 
        for (int j = i; j < n; j++) 
        {
            M[i * n + j] = arr[count];
            M[j * n + i] = M[i * n + j];
            count++;
        }
}

Graph::Graph(const Graph& tmp)
{
    n = tmp.n;
    M = new int[n * n];
    for (int i = 0; i < n * n; i++)
    {
        M[i] = tmp.M[i];
    }
}
Graph::~Graph()
{
    n = 0;
    delete[] M;
}

const Graph& Graph::operator = (const Graph& gr) {
    if (*this == gr)
    {
        return *this;
    }
    if (this->n != gr.n)
    {
        delete[] this->M;
        this->n = gr.n;
        this->M = new int[n * n];
    }
    for (int i = 0; i < this->n * n; i++)
    {
        this->M[i] = gr.M[i];
    }
    return *this;
}
bool Graph::operator == (const Graph& gr) const {
    if (this->n != gr.n)
        return false;
    for (int i = 0; i < this->n * n; i++)
        if (M[i] != gr.M[i])
            return false;
    return true;
}

int Graph::GetN()
{
    return n;
}

int* Graph::GetM()
{
    return M;
}

Graph Graph::ReduceVert(int v)
{
    Graph tmp(n - 1);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == v)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (j == v)
                continue;
            tmp.M[count] = this->M[i * n + j];
            count++;
        }
    }
    return tmp;
}

bool Graph::Is_empty_matrix() const
{
    for (int i = 0; i < n * n; i++)
        if (M[i] == 1)
            return false;
    return true;
}

//нужна функция маркировки вершин
Graph Graph::Mark_Graph() {      //у функции маркировки есть существенный минус: в 1ой вершине появляется маркер 1,
    Graph tmp(*this);            //но наличие ребра так же обозначается, поэтому буду прибавлять +10 к значению вершины, чтобы избежать проблем 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                tmp.M[i * n + j] = i + 10;
    return tmp;
}

int Graph::Find_Ver_Most_Rel() {
    int count, v = -1, max = 0;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++)
            if (M[i * n + j] == 1)
                count++;
        if (max < count) {
            max = count;
            v = i;
        }
    }
    return v;
}

int Graph::Find_Ver_Less_Rel() {
    int count, v = -1, min = n;
    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++)
            if (M[i * n + j] == 1)
                count++;
        if (min > count&& count != 0) {
            min = count;
            v = i;
        }
    }
    return v;
}

//функция удаляет окрестность заданной вершины
Graph Graph::ReduceNeighborVert(int v) {
    Graph tmp(*this);
    vector<int> delvs;
    for (int i = 0; i < n; i++)   //записываем в вектор все смежные вершины относительно заданной
        if (M[v * n + i] == 1)
            delvs.push_back(M[i * n + i]);
    for (int i = 0; i < delvs.size(); i++) {  //удаление окрестности
        int j = 0;
        while (tmp.M[j * tmp.n + j] != delvs[i])   //поиск вершин из вектора окрестности
            j++;
        tmp = tmp.ReduceVert(j); //удаление вершины как ее находим
    }
    return tmp;
}

bool Graph::IsCompleteGraph() {
    //по вектору графа проходимся только по верхнему треугольнику и возвращаем фолсе если встретим хоть
    //один ноль
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (M[i * n + j] == 0)
                return false;
    return true;
}

Graph Graph::Fill_Graph() { //заполняем пустой граф размера n чтобы получился рандомный связный граф
    Graph tmp(*this);

    int size = tmp.n;
    std::vector<int> arr = genMas(size);
    int count = 0;
    

    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
        {
            tmp.M[i * size + j] = arr[count];
            tmp.M[j * size + i] = tmp.M[i * size + j];
            count++;
        }
    vector<int> path = mixMas(size);

    // проставляем ребра по этому пути
    for (int i = 0; i < size - 1; i++) {
        int x = path[i];
        int y = path[i + 1];
        tmp.M[x * size + y] = 1;
        tmp.M[y * size + x] = 1;
    }

    return tmp;
}

void Graph::ClearM() {
    int size = this->n;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            M[i * size + j] = 0;
        }
}

int Graph::ProcentEdges() {
    int eds = 0;
    for (int i = 0; i < this->n; i++)
        for (int j = 0; j < this->n; j++)
            if (M[i * n + j] == 1)
                eds += 1;
    //cout << eds << endl;
    //cout << n*n << endl;
    return eds * 100 / (n * n);
}