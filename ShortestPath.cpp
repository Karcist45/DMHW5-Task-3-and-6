///тест, загнанный в этот код, также находится в репозитории
#include <bits/stdc++.h>

using namespace std;
vector<char> ans;
void PrintShortestPath(int u, int v, vector<vector<int>> &p){//функция для восстановления ответа по матрице p
    ans.push_back((char)(v + 'a' == 'u' ? 'z' : v + 'a'));
    if(p[u][v] != u){
        PrintShortestPath(u, p[u][v],  p);
    }


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, 1e9)); // матрица, хранящая граф в виде матрицы смежности
    vector<vector<int>> p(n, vector<int>(n, -1)); //матрица предков
    /// формат ввода: n и m - количество вершин и рёбер соответсвенно
    /// далее следует m троек вида {x, y, w}, где (x, y) -ребро графа, w -его вес
    for(int i = 0; i < n; ++ i){
        a[i][i] = 0;
        p[i][i] = i;
    }
    for(int i = 0; i < m; ++ i){
        char x, y;
        cin >> x >> y;
        int w;
        cin >> w;
        a[x - 'a'][y - 'a'] = w;
        a[y - 'a'][x - 'a'] = w;
        p[x - 'a'][y - 'a'] = x - 'a';
        p[y - 'a'][x - 'a'] = y - 'a';
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = k;
                }
            }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << setw(3) << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << "Shortest paths matrix:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << setw(3) << a[i][j] << " ";
        }
        cout << endl;
    }
    PrintShortestPath(0, 20, p);
    ans.push_back('a');
    reverse(ans.begin(), ans.end());
    cout << "Shortest path is: ";
    for(auto c: ans){
        cout << c << " ";
    }
    return 0;
}
