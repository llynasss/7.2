#include <iostream>  

#include <iomanip>  

#include <time.h>  



using namespace std;



void create(int** a, const int rowCount, const int colCount, const int Low, const int High);

void print(int** a, const int rowCount, const int colCount);

void max_j_change(int** a, int n, int i);

void second(int** a, int n);



int main() {

    srand((unsigned)time(NULL));



    int Low = -15;

    int High = 15;

    int n = 8;



    int** a = new int* [n];

    for (int i = 0; i < n; i++) {

        a[i] = new int[n];

    }



    create(a, n, n, Low, High);



    print(a, n, n);



    second(a, n);



    print(a, n, n);



    for (int i = 0; i < n; i++)

        delete[] a[i];

    delete[] a;



    return 0;

}



void create(int** a, const int rowCount, const int colCount, const int Low, const int High) {

    for (int i = 0; i < rowCount; i++)

        for (int j = 0; j < colCount; j++)

            a[i][j] = Low + rand() % (High - Low + 1);

}



void print(int** a, const int rowCount, const int colCount) {

    cout << endl;

    for (int i = 0; i < rowCount; i++) {

        if (i % 2 == 1) {

            cout << "|";

        }

        else {

            cout << " ";

        }

        for (int j = 0; j < colCount; j++)

            cout << setw(4) << a[i][j];

        cout << endl;

    }

    cout << endl;

}



void max_j_change(int** a, int n, int i) {

    int a_max = a[i][0];

    int j_max = 0;

    int tmp;

    for (int p = 0; p < n; p++) {

        for (int u = 0; u < n; u++) {

            if (a[i][p] > a_max) {

                a_max = a[i][p];

                j_max = p;

            }

        }

    }



    tmp = a[i][i];

    a[i][i] = a[i][j_max];

    a[i][j_max] = tmp;

}



void second(int** a, int n) {

    for (int i = 0; i < n; i++) {

        if (i % 2 == 1) {

            max_j_change(a, n, i);

        }

    }

}