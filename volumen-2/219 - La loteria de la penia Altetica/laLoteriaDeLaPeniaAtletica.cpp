#include <iostream>
using namespace std;

int main()
{
    int casosPrueba, nDecimos, decimo, pares;

    cin >> casosPrueba;

    while (casosPrueba--)
    {
        cin >> nDecimos;
        pares = 0;

        for (int i = 0; i < nDecimos; i++)
        {
            cin >> decimo;

            if (decimo % 2 == 0)
            {
                pares++;
            }
        }

        cout << pares << '\n';    
    }
     
    return 0;
}