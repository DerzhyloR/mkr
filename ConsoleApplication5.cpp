#include <string>
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

class Task8 {
    
private:
    double x;
    int m;
    int n;
    double** A_matrix;
    double** B_matrix;

public:
    Task8(double a, int b, int c) : x(a), m(b), n(c) {
        A_matrix = new double* [m];
        for (int i = 0; i < m; i++) {
            A_matrix[i] = new double[n];
        }
        B_matrix = new double* [m];
        for (int i = 0; i < m; i++) {
            B_matrix[i] = new double[n];
        }
    }

    ~Task8() {
        for (int i = 0; i < m; i++) {
            delete[] A_matrix[i];
            delete[] B_matrix[i];
        }
        delete[] A_matrix;
        delete[] B_matrix;
    }

    void matrixs() {
        double part1 = 0;
        double part2 = 0;
        double part3 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                part1 = pow(x, 2) - pow((i + 3 * j), 1.2);
                part2 = i+log2((pow(j, 2)) / 2);
                if (part2 != 0) {
                    part3 = part1 / part2;
                }
                else {
                    part3 = NAN;
                }
                A_matrix[i][j] = part3;
                B_matrix[i][j] = pow(x, 2) + (pow(i, 2) - cos(j)) / (x + (i * j) + 1.5);
            }
        }
        cout << "Якщо елемент в матриці= '-0' або '0', то означає, що логарифм під час обчислення значення елемента був НЕВИЗНАЧЕНИМ!\n";
        cout << "Матриця А:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << A_matrix[i][j]<<"\t";
            }
            cout << "\n";
        }
        cout << "\nМатриця В:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << B_matrix[i][j] << "\t\t";
            }
            cout << "\n";
        }
    }

    void obchysl() {
        cout << "\nОбчислення в матриці В:\n";
        double z=0;
        int kilkist = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j%2!=0) {
                    if (B_matrix[i][j] < 0) {
                        z += B_matrix[i][j];
                    }
                    else {
                        kilkist++;
                    }
                    
                }
            }
            if (kilkist!=2) {
                cout << "\nСума від'ємних елементів, які мають непарні номери в " << i+1 << " рядку= " << z;
            }
            else {
                cout << "\nВід'ємних елементів, які мають непарні номери в " << i+1 << " рядку= " << "НЕМАЄ! Тому сума=0";
            }
            z = 0;
            kilkist = 0;
        }
    
    }

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Task8 task(2.7,10,5);
    task.matrixs();
    task.obchysl();

    
}
