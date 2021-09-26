/*
    Число называется совершенным, если оно равно сумме всех своих делителей, меньших его самого. Требуется найти все совершенные числа от M до N.
    Входной файл INPUT.TXT содержит числа M и N, разделенные пробелом. (1 ≤ M ≤ N ≤ 5*10^18)
    В выходной файл OUTPUT.TXT выведите по одному числу в строке в порядке возрастания все совершенные числа, находящихся на отрезке [M, N]. 
    В том случае, когда таких чисел нет следует вывести «Absent».
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool Is_Simple(unsigned long long ch)
{
    for (unsigned long long i = 2; i <= sqrt(ch); i++)
    {
        if (ch % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");
    unsigned long long m = 0;
    unsigned long long n = 0;
    fin >> m;
    fin >> n;
    bool exist = false;
    unsigned long long i = 2;
    while (pow(2, i - 1) * (pow(2, i) - 1) < m)
        i++;
    while ((pow(2, i - 1) * (pow(2, i) - 1)) <= n)
    {
        if (Is_Simple(pow(2, i) - 1))
        {
            exist = true;
            fout << (unsigned long long)(pow(2, i - 1) * (pow(2, i) - 1)) << endl;
        }
        i++;
    }
    if (!exist)
        fout << "Absent" << endl;
    return 0;
}
