#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;

bool above(int a, int b){
    return a > b;
}


template<class T1, class T2> bool sravn(T1 a, T2 b);

struct Element1
{
    char    addr[50];
    char    name[50];
    double  price;

    Element1& operator = (Element1 const& e1) {
        if(this == &e1)
            return *this;
        strcpy(name, e1.name);
        strcpy(addr, e1.addr);
        price = e1.price;
        return *this;
    }
    friend ostream& operator<< (ostream& out, const Element1& m)
    {
        out << "addr: " << m.addr << endl;
        out << "name: " << m.name << endl;
        out << "price: " << m.price << endl;
        return out;
    }
    friend istream& operator>> (istream& in, Element1& m)
    {
        cout << "Введите addr, Name, price" << endl;
        in >> m.addr;
        in >> m.name;
        in >> m.price;
        return in;
    }
};
struct Element2
{
    char name[50];
    char addr[50];

    friend istream& operator>> (istream& in, Element2& m)
    {
        cout << "Введите addr, Name" << endl;
        in >> m.addr;
        in >> m.name;
        return in;
    }
    friend ostream& operator<< (ostream& out, const Element2& m)
    {
        out << "addr: " << m.addr << endl;
        out << "name: " << m.name << endl;
        return out;
    }
};
struct Element3
{
    char    name[50];
    char    addr[50];
    double  price;

    friend istream& operator>> (istream& in, Element3& m)
    {
        cout << "Введите addr, Name, price" << endl;
        in >> m.addr;
        in >> m.name;
        in >> m.price;
        return in;
    }
    friend ostream& operator<< (ostream& out, const Element3& m)
    {
        out << "addr: " << m.addr << endl;
        out << "name: " << m.name << endl;
        out << "price: " << m.price << endl;
        return out;
    }

    Element3& operator = (Element1& e1) {
        strcpy(name, e1.name);
        strcpy(addr, e1.addr);
        price = e1.price;
        return *this;
    }

};

struct Element4{
    char name[50];
    friend istream& operator>> (istream& in, Element4& m)
    {
        cout << "Введите Name" << endl;
        in >> m.name;
        return in;
    }
};
template<class T> class MASSIV
{
    int count;
    T* M;
public:
    MASSIV() {
        M = nullptr;
        count = 0;
    };
    explicit MASSIV(int n) {
        count = n;
        M = new T[n];
    };
    MASSIV(MASSIV <T>& m) {
        count = m.count;
        M = new T[count];
        for (int i = 0; i < count; i++)
            M[i] = m.M[i];
    };
    ~MASSIV()
    {
        delete (T*) M;
    }

    int getCount() {
        return count;
    }
    T& operator [] (int n) {
        return M[n];
    }

    template<class T2>
    MASSIV& operator = (MASSIV<T2>& m) {
        count = m.getCount();
        delete (T*)this->M;
        M = new T[count];
        for (int i = 0; i < count; i++) {
            this->M[i] = m[i];
        }
        return *this;
    }
    void sort() {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count - 1; j++) {
                if (above(M[j], M[j + 1])){
                    T a = M[j];
                    M[j] = M[j + 1];
                    M[j + 1] = a;
                }
            }
        }
    }

    template<class T2> MASSIV operator - (MASSIV<T2>& m) {
        MASSIV ans(this->count - m.getCount());
        int k = 0;
        bool a = false;
        for (int i = 0; i < count; i++) {
            for(int j = 0; j < m.getCount(); j++)
                if (sravn(this->M[i], m[j]))
                {
                    a = true;
                    break;
                }
            if (!a)
            {
                ans[k++] = M[i];
                a = false;
            }
        }
        return ans;
    }

    friend ostream& operator<< (ostream& out, const MASSIV& m)
    {
        out << "длина массива: " << m.count << endl;
        for (int i = 0; i < m.count; i++) {
            out << m.M[i] << endl;
        }
        out << endl;
        return out;
    }
    friend istream& operator>> (istream& in, MASSIV& m)
    {
        cout << "vvedi count: ";
        in >> m.count;
        delete (T*)m.M;
        m.M = new T[m.count];
        for (int i = 0; i < m.count; i++)
        {
            cout << "vvedi element:";
            in >> m.M[i];
        }


        return in;
    }

    void peresech(MASSIV<Element1>& a, MASSIV<Element2>& b) {
        int count1, count2;
        count1 = a.getCount();
        count2 = b.getCount();
        count = count1 - count2;
        delete (T*)M;
        M = new T[count];
        int k = 0;
        bool d = false;
        for (int i = 0; i < count1; i++) {
            for (int j = 0; j < count2; j++)
                if (sravn(a[i], b[j]))
                {
                    d = true;
                    break;
                }
            if (!d)
            {
                M[k] = a[i];
                k++;
            } else
                d = false;
        }
    }

    void WriteTextData(char* s)
    {
        fstream out;
        out.open(s, ofstream::out | ofstream::binary);
        if (!out.is_open())
        {
            cout << "Open file failed.\n";
        }
        else
        {
            int i = 0;
            while (i < count)
            {
                out.write((char*)&M[i], sizeof(T)); i++;
            }
            out.close();
        }
    }
    void ReadData(char* s)
    {
        fstream in;
        in.open(s, ofstream::in | ofstream::binary);

        in.seekg(0, ios_base::end); // go to end of the file
        auto filesize = in.tellg();
        if (!in.is_open())
        {
            cout << "Open file failed.\n";
        }

        M = new T[100];
        int i = 0;
        in.seekg(0, ios::beg);
        while (in.tellg() != filesize)
        {
        in.read((char*)&M[i++], sizeof(T));
        }
        count = i;
        in.close();
    }

};
template<class T1, class T2> bool above(T1 a, T2 b)
{
    int c = strcmp(a.addr, b.addr);
    if (c == -1)
        return false;
    if( c == 1)
        return true;
    c = strcmp(a.name, b.name);
    if (c == 1)
        return true;
    return false;
}
template<class T1, class T2> bool sravn(T1 a, T2 b)
{
    int c = strcmp(a.addr, b.addr);
    if(!c)
    {
        c = strcmp(a.name, b.name);
        if (!c)
            return true;
    }
    return false;
}

int main()
{
    setlocale(0, "");
    ifstream in ("input.txt");
    MASSIV<Element1> a(7);
    MASSIV<Element2> b(3);
    //in >> a;
    //cout << a;
    //a.sort();
    MASSIV<double> intM;
    in >> intM;
    cout << endl;
    cout << "non-sorted:" << endl << intM;
    intM.sort();
    cout << "sorted:"  << endl << intM;
    MASSIV<Element1> k;
    MASSIV<Element1> r;
    MASSIV<Element3> m;
    in >> k >> b;

    r.peresech(k, b);
    m = r;
    cout << m;
    MASSIV<Element4> dl;
    dl.ReadData((char*)"input1.txt");
    dl.WriteTextData((char*)"output1.txt");
}
