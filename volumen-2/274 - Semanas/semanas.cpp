#include <iostream>
using namespace std;

int main()
{
    int casosPrueba, anio, semana, dia, semanasCompletas;

    cin >> casosPrueba;

    while (casosPrueba > 0)
    {
        cin >> anio >> semana >> dia;

        if (dia == 1)
        {
            semanasCompletas = anio / semana;
        }
        else
        {
            semanasCompletas = (anio - (semana - (dia - 1))) / semana;
        }

        cout << semanasCompletas << '\n';
        
        casosPrueba--;
    }
    
    return 0;
}