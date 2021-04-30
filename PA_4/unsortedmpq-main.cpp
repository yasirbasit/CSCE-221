#include "UnsortedMPQ.h"
#include <iostream>

using namespace std;

int main() {
    {
        UnsortedMPQ<int> mpq;
        cout << "Inserting 1 - 5" << endl;
        mpq.insert(1);
        mpq.insert(2);
        mpq.insert(3);
        mpq.insert(4);
        mpq.insert(5);
        cout << "Remove min five times" << endl;
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << endl << endl;
    }
    {
        UnsortedMPQ<int> mpq;
        cout << "Inserting 5 - 1" << endl;
        mpq.insert(5);
        mpq.insert(4);
        mpq.insert(3);
        mpq.insert(2);
        mpq.insert(1);
        cout << "Remove min five times" << endl;
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << endl << endl;
    }
    {
        UnsortedMPQ<int> mpq;
        cout << "Inserting mixed order 1-5" << endl;
        mpq.insert(5);
        mpq.insert(2);
        mpq.insert(4);
        mpq.insert(3);
        mpq.insert(1);
        cout << "Remove min five times" << endl;
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << endl << endl;
    }
    {
        UnsortedMPQ<int> mpq;
        cout << "Testing exception" << endl;
        try {
            mpq.remove_min();
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
        cout << endl;
    }
    {
        UnsortedMPQ<int> mpq;
        cout << "Inserting mixed order 1-5" << endl;
        mpq.insert(5);
        mpq.insert(2);
        mpq.insert(4);
        mpq.insert(3);
        mpq.insert(1);
        cout << "Remove min five times" << endl;
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << endl;
        cout << "Inserting mixed order 11-15" << endl;
        mpq.insert(15);
        mpq.insert(12);
        mpq.insert(14);
        mpq.insert(13);
        mpq.insert(11);
        cout << "Remove min five times" << endl;
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << ", ";
        cout << mpq.remove_min() << endl;
        cout << "Testing exception" << endl;
        try {
            mpq.remove_min();
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}