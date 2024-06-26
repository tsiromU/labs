#include<QList>
#include<iostream>
#include<list>
#include<QDebug>
#include<QTextStream>
#include<QtAlgorithms>
using namespace std;

void FromQToStd_List(QList<quint8> &Qlist,list<int> &STDList)
{
    for (int size=0; size<Qlist.size(); size++)
    {
        STDList.push_back(Qlist.at(size));
    }
}
void FromSTDToQ_List(list<int>&STDList, QList<quint8> &Qlist)
{
    Qlist.clear();
    //Qlist.squeeze();

    for (auto it = STDList.begin(); it!=STDList.end(); advance(it,1))
    {
        Qlist.push_back(*it);
    }
}
void ShowList(QList<quint8>& list1)
{
    cout<<" Your List: "<<endl<<endl;
    cout << "length:"<<list1.size();
    for (auto it=list1.begin(); it!=list1.end();)
    {
        qDebug()<<*it;
        advance(it,1);
    }
    cout<<endl;

}


void addNewElement(QList<quint8>& list1){
    int a, b;
    cout << "введите позицию" << endl;
    cin >> a;
    if(a > list1.length()){
        cout << "слишком далеко" << endl;
        return;
    }
    cout << "введите новый элемент" << endl;
    cin >> b;
    list1.insert(a-1, b);
    return;
}

void addElements(QList<quint8>& list1) {
    cout << "сколько элементов хотите ввести" << endl;
    int n, a;
    cin >> n;
    cout << "введите элементы" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a;
        list1.push_back(a);
    }
}

void removeByValue(QList<quint8>& list1){
    int a;
    cout << "введите значение которое нужно удалить" << endl;
    cin >> a;
    auto it = std::find(list1.begin(), list1.end(), a);
    if(it == list1.end())
        cout << "нет такого"<< endl;
    else
        list1.erase(it);
}

void populCount(QList<quint8>& list1){
    int a;
    cout << "введите номер элемента" << endl;
    cin >> a;
    auto it = list1.begin();
    advance(it, a-1);
    cout << "едениц в двичной записи: " <<  qPopulationCount(*it) << endl;
}

//qPopulationCount(quint8 v), qStableSort()
int main()
{
    QList<quint8> list1;
    int a=1;
    while(a)
    {
        cout << "\n Available operations: " << endl;
        cout << "\n 1. Check list " << endl;
        cout << " 2. Add new element in center" << endl;
        cout << " 3. Add new elements in the end" << endl;
        cout << " 4. Remove  element (by value)" << endl;
        cout << " 5. вывестиколичество едениц в двоичной записи элемента массива" << endl;
        cout << " 6. QStableSort " << endl;
        cout << " 7. Exit " << endl;

        cout << "\n Enter number of operation: ";
        cin  >> a;
        cout << endl;
        switch (a)
        {

        case 1:
            ShowList(list1);break;
        case 2:
            addNewElement(list1);break;
        case 3:
            addElements(list1);break;
        case 4:
            removeByValue(list1);break;
        case 5:
            populCount(list1);break;
        case 6:
            qStableSort(list1.begin(), list1.end());break;
        case 0:
            cout << " The end" << endl;
            break;
        }
    }

    cout << "из qt в stl" << endl;
    list<int> stdList;
    FromQToStd_List(list1, stdList);
    cout << "список:";
    copy(list1.begin(), list1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "обратно" << endl;
    FromSTDToQ_List(stdList, list1);
    ShowList(list1);
    return 0;
}

/*
12. Разработать программу для работы со списком (использовать list). Информационное поле каждого элемента – целые числа. Программа должна выводить на экран компьютера меню вида:
    1.Просмотреть состояние списка
    2.Добавить элемент в середину списка
    4.Добавить несколько элементов
    5.Удалить элемент по значению
    6. Проверяет, является ли один список подмножеством другого(includes или  mismatch )
    7.Перемещение элементов из другого списка(splice)
    8.Выход из программы

*/

