#include <ctime>
#include <stack>
#include <vector>
#include "Graphs.h"
#include "ExtraFuns.h"

using namespace std;

int Graph::Check_Cycle_with_Vert(int top, std::vector<int> used) { // ���������� �� ������� � ������� ������� �������� ����
    int check_v = used[top];
    int cycle_v = -1;
    while (check_v != 0) {
        check_v = used[check_v];
        if (M[top * n + check_v] == 1) {
            cycle_v = check_v;
        }
    }
    return cycle_v;
}

int Graph::Find_Unused_Vert(int top, std::vector<int> used) { // ���������� ������ ������������ ������� ������� � �������
    for (int i = 0; i < n; i++)
        if (M[top * n + i] == 1 && used[i] == -1)
            return i;
    return -1;
}

void Graph::Gen_ChordalGr() {
    //������� ��������� ������� ���� �� � ������
    //    ���� ���� �� ������
    //      ������� ������� ����� ������� �� ��������� �� �� - �� ��� �����
    //            ���� ���������� �� ��������� ����� ���� �������� �� ������� ����������� �����
    //      ���� ����� ������������ ������� ��� �����
    //            ���� �� ������� ������� ������ ������� � ������������ �� ������������ �����
    //            ���� ����� ����� � ����

    // ���������� ��������� ���� � �������� ��� �������

    unsigned int start_time = clock();

    stack<int> stack;
    stack.push(0);

    // ������ � ������� �������������� ������
    vector<int> used(n);
    for (int i = 0; i < n; i++)
        used[i] = -1;

    used[0] = 0;

    while (!stack.empty()) {

        int top = stack.top();

        // ������� �� ��������� �� ����
        int cycle_v = this->Check_Cycle_with_Vert(top, used); // ���������� �� ������� � ������� ������� �������� ����
        if (cycle_v != -1) {
            int new_adj_v = used[top];
            while (new_adj_v != cycle_v) { //����������� ����� ����� ����� ��������������� ����
                new_adj_v = used[new_adj_v];
                M[top * n + new_adj_v] = 1;
                M[new_adj_v * n + top] = 1;
            }
        }

        // �������� ����� ����� ������� ������� ������� � �������
        int new_top = -1;
        while (new_top == -1 && !stack.empty()) {
            top = stack.top();
            new_top = this->Find_Unused_Vert(top, used);
            if (new_top != -1) {
                used[new_top] = top;
                top = new_top;
                stack.push(top);
            }
            else {
                stack.pop();
            }
        }
    }

    vector<int> branches(n);
    for (int i = 0; i < n; i++)
        branches[i] = 0;
    for (int i = 0; i < n; i++)
        branches[used[i]]++;

    int full_rel = 0;
    for (int i = 1; i < n; i++)
    {
        if (branches[i] >= 2)
        {
            for (int ind = i; ind != full_rel; ind = used[ind]) {
                if (ind == 0)
                    break;
                for (int ind2 = used[ind]; ind2 != 0; ind2 = used[ind2])
                {
                    M[ind * n + ind2] = 1;
                    M[ind2 * n + ind] = 1;
                }
                full_rel = ind;
                M[ind * n + 0] = 1;
                M[ind] = 1;
                
            }
        }
    }

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    //cout << "---------------------------" << endl;
    //cout << search_time << " Gen Chord graph time" << endl;
    //cout << "---------------------------" << endl;
    //return search_time;
}

bool Graph::IsCompleteArea(vector<int> arr, int* _M) const
{
    for (int i = 0; i < arr.size(); i++) //�������� �� ������� �������� (�����������)
        for (int j = i + 1; j < arr.size(); j++)
            if (_M[arr[i] * n + arr[j]] != 1)
                return false;
    return true;
}

int Graph::SimplVer()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> arr;
        for (int j = 0; j < n; j++)
            if (M[i * n + j] == 1)
                arr.push_back(j); //����������� ������� i (��� ������� �������� � �����������)
        if (arr.empty())
            continue;
        if (IsCompleteArea(arr, M))
            return i;
    }
    return -1;
}

bool Graph::isChordalGraph() const
{
    Graph tmp(*this);

    tmp = tmp.Mark_Graph();

    while (tmp.n != 1)
    {
        int simpver;
        simpver = tmp.SimplVer();
        if (simpver == -1)
            return false;
        tmp = tmp.ReduceVert(simpver);
    }
    return true;
}

///������� ���� � ���� �����
//   ���� �� ���� ���� ����� ���� ����� ����� ���� � ����������
//   �� ���� ��������� �� ������ ���� � �������� ����� ��� � ���� ���� �� ������� ������ � ������
//        ����� ����� ���� ������� ���� ������ � ������ ����� ������������ ��� �� ��� ������� ������ ���� ������
//        ����� ����� ������ ����� �� ������ � ������
//        ������� �� ��� � ������� ������������
//   ���������� ����� �������(��� ��������� ���������) � ���������� ��� � ������� ��
//   �� ����� ������ ������� ����� ��������� ����� ������ ������� ����� ������� � �����
//   (���� ������ �� ����� ����� � �� ���� ���� ��� ���� ������ ���� ���������� ������� ��������� ����� ��� � ���� �����)

vector<int> Graph::Independent_set_for_ChordalGr_Absorb_Ver()
{
    Graph tmp(this->Mark_Graph());

    int delver;
    while (true)
    {
        if (tmp.Is_empty_matrix())
        {
            vector<int> res;
            for (int i = 0; i < tmp.n; i++)
                res.push_back(tmp.M[i * tmp.n + i] - 10);

            return res;
        }
        delver = tmp.AbsorbVer();
        tmp = tmp.ReduceVert(delver);
    }
}

int Graph::AbsorbVer()
{
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.clear();
        arr.push_back(i);                    // ����������� ������� i ������ ������� � ����������� �����������
        for (int j = 0; j < n; j++)
            if (M[i * n + j] == 1) {
                arr.push_back(j);
            }                                //����������� ������� i (��� ������� �������� � �����������)
        for (int j = 1; j < arr.size(); j++) //�������� �� ��������� ��� ������� i � ��� ������� � ��� ������
        {
            bool flag = true;
            for (int k = 0; k < arr.size(); k++)
            {
                if (j == k)
                    continue;
                if (M[arr[j] * n + arr[k]] != 1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                return arr[j];
            }
        }
    }
}


vector<int> Graph::Independent_set_for_ChordalGr_Simpl_Ver()
{
    // � ���� ������� �� ���� �� ����� ���� ����� �������
    // � ����� ������� ������� �� �����������
    // ��� ������ �� ��� ��� ���� � ����� ���� �����
    // ���������� ������� ������� ���������
    Graph tmp(this->Mark_Graph());

    int simplver;
    while (true)
    {
        if (tmp.Is_empty_matrix())
        {
            vector<int> res;
            for (int i = 0; i < tmp.n; i++)
                res.push_back(tmp.M[i * tmp.n + i] - 10);

            return res;
        }
        simplver = tmp.SimplVer();
        tmp = tmp.ReduceNeighborVert(simplver);
    }
}

int Graph::ClickNumber(int simpver) {
    int click_num = 1;
    for (int i = 0; i < n; i++)
        if (M[simpver * n + i] == 1)
            click_num++;
    return click_num;
}

int Graph::Coloring_for_ChordalGr() {

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

    Graph initial_gr(this->Mark_Graph());
    Graph tmp(this->Mark_Graph());

    //���������� ������ �� ����� ������ � ������ ����� ������ ������������ �����
    vector<int> mass_simplver(tmp.n);
    int chromatic_num = 0;
    int count = 0;
    while (tmp.n != 1)
    {
        int simpver = tmp.SimplVer(); // �������� ������ � �� ����������
        mass_simplver[count] = tmp.M[simpver * tmp.n + simpver] - 10; // ����� ������� 10 ��������� ���������� ������ ������� � �������� �����
        if (chromatic_num < tmp.n) {
            int click_num = tmp.ClickNumber(simpver);
            if (click_num > chromatic_num)
                chromatic_num = click_num;
        }

        tmp = tmp.ReduceVert(simpver);
        count++;
    }
    mass_simplver[count] = tmp.M[0] - 10;

    //� ����� ���������� � ���� ������ ��������� ���� (�� �������� ����� �� ������� ������ ��������� ���������)
    vector<int> coloring_verts(initial_gr.n);
    for (int i = 0; i < initial_gr.n; i++)
        coloring_verts[i] = -1;

    int idx = initial_gr.n - 1;
    while (idx >= 0) {
        int cur_simpvert = mass_simplver[idx];

        vector<bool> order_colors(chromatic_num);
        for (int i = 0; i < chromatic_num; i++)
            order_colors[i] = false;

        for (int i = idx + 1; i < initial_gr.n; i++) {
            int prev_vert = mass_simplver[i];
            if (initial_gr.M[cur_simpvert * initial_gr.n + prev_vert] == 1)
                order_colors[coloring_verts[prev_vert]] = true;
        }

        int k = 0;
        while (coloring_verts[cur_simpvert] == -1) {
            if (order_colors[k] == false) {
                coloring_verts[cur_simpvert] = k;
            }
            k++;
        }
        idx--;
    }

    // ��������� �������
    unsigned int end_time = clock();

    //����� ������
    cout << "+++++++++Coloring_for_Chordal_Graph+++++++++" << endl;
    //cout << endl;
    cout << "Chromatic number " << chromatic_num << endl;
    //cout << "Colors:" << endl;
    //for (int i = 0; i < coloring_verts.size(); i++)
    //    cout << coloring_verts[i] << " ";
    //cout << endl;
    //cout << endl;

    //����� �������
    unsigned int search_time = end_time - start_time;
    cout << "Chordal Coloring time " << search_time << endl;
    cout << endl;
    //cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

    return search_time;
}
