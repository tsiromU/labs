#include <iostream>
#include <algorithm>
#include <utility> 
#include <map> 
#include <iomanip>

using namespace std;

typedef int cost;
typedef int code;
typedef pair<cost, code> datum;

struct CMP {
    bool operator()(const int& p1, const int& p2) const {
        return p1 % 5 < p2 % 5;
    }
};


multimap < int, code, CMP> d;
multimap<int, code, CMP> f;

void print() {

    cout << "current multimap:" << endl;
    cout << setw(10) << "Cost" << setw(10) << "Code" << endl;
    for (auto pr : d) {
        cout << setw(10) << pr.first << setw(10) << pr.second << endl;
    }
    cout << endl;
}
void add() {
    cout << "enter cost and code" << endl;
    datum a;
    cin >> a.first >> a.second;
    d.insert(a);
    print();
}
void delet() {
    cout << "enter diapozon" << endl;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        auto range = d.equal_range(i);
        for (auto it = range.first; it != range.second;) {
            it = d.erase(it);
        }
    }
    print();
}
void findLess() {
    int a;
    cout << "введаите число, по которому должен идти поиск" << endl;
    cin >> a;
    auto it1 = d.lower_bound(a);

    cout << "элементы с ключом меньше заданного:" << endl;
    cout << setw(10) << "Cost" << setw(10) << "Code" << endl;
    for (auto it = d.begin(); it != it1; it++) {
        cout << setw(10) << it->first << setw(10) << it->second << endl;
    }
    cout << endl;
}
void swapmaps() {
    f.swap(d);
    print();
}
void change() {
    int n, a; 
    cout <<  "введите номер изменяемого" << endl;
    cin >> n;
    cout << "введите новый cost";
    cin >> a;
    auto it = d.begin();
    while (--n) {
        it++;
    }
    it->second = a;
    print();
}
void comparemaps() {
    if (d > f)
        cout << "текущий map больше" << endl;
    else if (f > d)
        cout << "текущий map меньше" << endl;
    else cout << "равны" << endl;
};
int main()
{
    setlocale(0, "");
    while(int c = 1){
        cout << "1.Добавить  элемент" << endl;
        cout << "2.Удалить элементы из заданного диапазона" << endl;
        cout << "3.Поиск элементов меньших заданного ключа" << endl;
        cout << "4.Обменивает  значения двух объектов(отображений)" << endl;
        cout << "5.Замена значения элемента" << endl;
        cout << "0.Выход из программы" << endl << endl;
        cin >> c;
        switch (c) {
        case 1:add(); break;
        case 2:delet(); break;
        case 3:findLess(); break;
        case 4:swapmaps(); break;
        case 5:change(); break;
        case 6:comparemaps(); break;
        }


    }

}
