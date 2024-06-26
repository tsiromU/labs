#include <QCoreApplication>
#include <QMultiMap>
#include <iomanip>
#include <iostream>

using namespace std;

typedef int cost;
typedef int code;
typedef pair<cost, code> datum;

struct CMP {
    bool operator()(const int& p1, const int& p2) const {
          return p1 % 5 < p2 % 5;
    }
};

void print(QMultiMap<cost, code>& d) {

    cout << "current multimap:" << endl;
    cout << setw(10) << "Cost" << setw(10) << "Code" << endl;
    for (auto it = d.begin(); it != d.end();it++) {
          cout << setw(10) << it.key() << setw(10) << it.value() << endl;
    }
    cout << endl;
}

void add(QMultiMap<cost, code>& d) {
    cout << "enter cost and code" << endl;
    datum a;
    cin >> a.first >> a.second;
    d.insert(a.first, a.second);
    print(d);
}

void delet(QMultiMap<cost, code>& d) {
    cout << "enter diapozon" << endl;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
          auto range = d.equal_range(i);
          for (auto it = range.first; it != range.second;) {
              it = d.erase(it);
          }
    }
    print(d);
}

void findLess(QMultiMap<cost, code>& d) {
    int a;
    cout << "введаите число, по которому должен идти поиск" << endl;
    cin >> a;
    auto it1 = d.lowerBound(a);

    cout << "элементы с ключом меньше заданного:" << endl;
    cout << setw(10) << "Cost" << setw(10) << "Code" << endl;
    for (auto it = d.begin(); it != it1; it++) {
          cout << setw(10) << it.key() << setw(10) << it.value() << endl;
    }
    cout << endl;
}

void swapmaps(QMultiMap<int, cost>& d, QMultiMap<int, code>& f) {
    f.swap(d);
    print(d);
}

void change(QMultiMap<cost, code>& d) {
    int n, a;
    cout <<  "введите номер изменяемого" << endl;
    cin >> n;
    cout << "введите новый cost";
    cin >> a;
    auto it = d.begin();
    while (--n) {
          it++;
    }
    it.value() = a;
    print(d);
}
/*
void comparemaps(QMultiMap<cost, code>& d, QMultiMap<int, code>& f) {
    if (d > f)
          cout << "текущий map больше" << endl;
    else if (f > d)
          cout << "текущий map меньше" << endl;
    else cout << "равны" << endl;
}
*/
int main()
{
    QTextStream out(stdout);

    QMultiMap <cost, code> d;
    QMultiMap <cost, code> f;
    d.insert(1,3);
    d.insert(4,3);
    d.insert(6,5);
    d.insert(2,1);
    f.insert(4,3);
    f.insert(4,7);
    f.insert(4,1);
    f.insert(9,6);
    int c = 1;
    while(c){
        cout << "1.Добавить  элемент" << endl;
        cout << "2.Удалить элементы из заданного диапазона" << endl;
        cout << "3.Поиск элементов меньших заданного ключа" << endl;
        cout << "4.Обменивает  значения двух объектов(отображений)" << endl;
        cout << "5.Замена значения элемента" << endl;
        cout << "0.Выход из программы" << endl << endl;
                cin >> c;
        switch (c) {
        case 1:add(d); break;
        case 2:delet(d); break;
        case 3:findLess(d); break;
        case 4:swapmaps(d, f); break;
        case 5:change(d); break;
/*        case 6:comparemaps(d,f); break;*/
        case 0:break;
        }
    }
    return 0;
}
/*
 *
Использовать объекты pair<,>

Определить собственные типы через typedef

Использовать собственный критерий сортировки.

При сравнение отображений использовать перегруженные операторы


12. Разработать программу для работы с отображениями (multimap).
Информационное поле каждого элемента представляет собой: код(целое число), цена (целое число) -ключ.
Программа должна выводить на экран компьютера меню вида и результаты работы:

1.Добавить элемент

2.Удалить элемент

3.Поиск первого элемента с ключом, меньшим заданного ключа(upper_bound или lower_bound)

4.Обменивает  значения двух объектов (отображений)

5. Замена элемента

6. Сравнение отображений (>)

7.Выход из программы
 */
