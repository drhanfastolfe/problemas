#include <iostream>
#include <algorithm>
using namespace std;

int * numAdigitos(int n)
{
    static int nArr[4];
    int num = n, resto, i = 3;
    
    while (num > 0)
    {
        resto = num % 10;
        num /= 10;
        nArr[i] = resto;     
        i--;
    }   

    while (i != -1)
    {
        nArr[i] = 0;
        i--;
    }
    
    return nArr;
}

bool digitosIguales(int *nArr)
{
    bool ret = true;
    int i = 1;

    while (ret && i < 4)
    {
        if (nArr[i - 1] != nArr[i])
        {
            ret = false;
        }
        i++;
    }
    
    return ret;
}

int main()
{
    int casosPrueba, n, k, *nArr;

    cin >> casosPrueba;

    while (casosPrueba--)
    {
        k = 0;
        cin >> n;

        nArr = numAdigitos(n);
        
        if (n == 0 || digitosIguales(nArr))
        {
            cout << 8 << "\n";
        }
        else
        {
            while (n != 6174)
            {
                sort(nArr, nArr + 4);

                int numAsc, numDes;

                numAsc = nArr[0] * 1000 + nArr[1] * 100 + nArr[2] * 10 + nArr[3];
                numDes = nArr[3] * 1000 + nArr[2] * 100 + nArr[1] * 10 + nArr[0];

                n = numDes - numAsc;

                nArr = numAdigitos(n);

                k++;
            }
            cout << k << "\n";
        }
    }
    
    return 0;
}