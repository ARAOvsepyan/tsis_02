#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

double fun2(double x)
{
    return (cos(x) * tanh(x));
}

void printN(std::vector<double> P, std::vector<double> q, int N[20][10]) // вывод зависимости N от q и P
{
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "+---------------------------------------------------------------------------------------+\n| q/P\t";
    for (int i = 0; i < P.size(); i++)
        std::cout << "| " << P[i] << "\t";
    std::cout << "|\n+---------------------------------------------------------------------------------------+\n";
    for (int i = 0; i < q.size(); i++) {
        std::cout << "| " << q[i] << "\t";
        for (int j = 0; j < P.size(); j++)
            std::cout << "| " << N[i][j] << "\t";
        std::cout << "|\n";
        std::cout << "+---------------------------------------------------------------------------------------+\n";
    }
}

void print(std::vector<double> P, std::vector<double> q, double X[20][10]) // Вывод экстремума в зависимости от q и P
{
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "+---------------------------------------------------------------------------------------+\n| q/P\t";
    for (int i = 0; i < P.size(); i++)
        std::cout << "| " << P[i] << " ";
    std::cout << "|\n+---------------------------------------------------------------------------------------+\n";
    for (int i = 0; i < q.size(); i++) {
        std::cout << "| " << q[i] << " ";
        for (int j = 0; j < P.size(); j++) {
            if (fun2(X[i][j]) > 0) {
                std::cout << "| " << fun2(X[i][j]) << " ";
            }
            else {
                std::cout << "| " << fun2(X[i][j]);
            }
        }
        std::cout << "|\n";
    }
    std::cout << "+---------------------------------------------------------------------------------------+\n";
}

void random_search(double a, double b, char modal) {
    std::vector<double> P;
    std::vector<double> q;
    std::vector<double> x;
    double X[20][10];
    int N[20][10];
    for (double i = 0.9; i <= 0.991; i += 0.01) {
        P.push_back(i);
    }
    for (double i = 0.005; i <= 0.104; i += 0.005) {
        q.push_back(i);
    }
    for (int i = 0; i < q.size(); i++) {
        for (int j = 0; j < P.size(); j++) {
            N[i][j] = log(1 - P[j]) / log(1 - q[i]);
        }
    }
    for (int i = 0; i < q.size(); i++)
        for (int j = 0; j < P.size(); j++) {
            for (int k = 0; k < N[i][j]; k++)
                x.push_back(a + (double)(rand()) / RAND_MAX * (b - a) + fabs(a));
            X[i][j] = x[0];

            for (int k = 0; k < N[i][j]; k++) {
                if (modal == 'u')
                    if (fabs(fun2(X[i][j])) < fabs(fun2(x[k])))
                        X[i][j] = x[k];
                if (modal == 'm')
                    if (fabs(fun2(X[i][j]) * sin(5 * X[i][j])) < fabs(fun2(x[k])) * sin(5 * X[i][j]))
                        X[i][j] = x[k];
            }
            x.clear();
        }
    if (modal == 'u')
        printN(P, q, N);
    print(P, q, X);
}
