#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

list<int> list1;
void show_list() {
    cout << "список:";
    copy(list1.begin(), list1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void add_elem() {
    cout << "введите новый элемент" << endl;
    int a;
    cin >> a;
    list1.push_back(a);
};

void add_elems() {
    cout << "сколько элементов хотите ввести" << endl;
    int n, a;
    cin >> n;
    cout << "введите элементы" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a;
        list1.push_back(a);
    }
}

void delet_elem() {
    list1.pop_back();
};

void incl() {
    list<int> list2;
    cout << "сколько элементов будет в новом листе, после введите их" << endl;
    int a, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        list2.push_back(a);
    }
    if (!is_sorted(list2.begin(), list2.end())) {
        cout << "includes работает только с отсортироваными контейнерами"  << endl;
        return;
    }
    cout << "Ответ:";
    cout << includes(list1.begin(), list1.end(), list2.begin(), list2.end()) << endl;
}

void splice() {
    list<int> list2;
    cout << "сколько элементов будет в новом листе, после введите их" << endl;
    int a, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a; 
        list2.push_back(a);
    }
    cout << "после какого элемента ведется вставка" << endl;
    cin >> a;
    auto i1begin = list1.begin();
    advance(i1begin, a);
    list1.splice(i1begin, list2, list2.begin(), list2.end());

};

int main()
{
    setlocale(0, "");

    int a = 1;
    while (a)
    {
        cout << "1.Просмотреть состояние списка" << endl;
        cout << "2.Добавить элемент" << endl;
        cout << "4.Добавить несколько элементов" << endl;
        cout << "5.Удалить элемент" << endl;
        cout << "6.Проверяет, является ли один список подмножеством другого(includes)" << endl;
        cout << "7.Перемещение элементов из другого списка(splice)" << endl;
        cout << "0.Выход из программы" << endl;
        cout << endl;

        cin >> a;
        switch(a) {
            case 1:show_list();   break;
            case 2:add_elem();     break;
            case 4:add_elems();    break;
            case 5:delet_elem();   break;
            case 6:incl();         break;
            case 7:splice();       break;
        }   
    }
    return 0;
}
