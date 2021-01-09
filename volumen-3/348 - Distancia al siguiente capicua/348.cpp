#include <iostream>
#include <math.h>
using namespace std;

int nDigitos(int n) // Para n > 9
{
    int num = n, digitos = 0;

    while (num > 0)
    {
        num /= 10;
        digitos++;
    }    
    
    return digitos;
}

int numAdigitos(int n, int* array, int sizeOfArray)
{
    int num = n, resto, i = sizeOfArray - 1;
    
    while (num > 0)
    {
        resto = num % 10;
        num /= 10;
        array[i] = resto;     
        i--;
    }   
    
    return 0;
}

int mitadIzquierda(int* array, int* arrayMitad, int sizeArray)
{
    int impar = 1;

    if (sizeArray % 2 == 0)
    {
        impar = 0;
    }

    for (int i = 0; i < (sizeArray/2) + impar; i++)
    {
        arrayMitad[i] = array[i];
    }

    return 0;
}

int mitadDerecha(int* array, int* arrayMitad, int sizeArray)
{
    int impar = 1;

    if (sizeArray % 2 == 0)
    {
        impar = 0;
    }

    for (int i = 0; i < (sizeArray / 2) + impar; i++)
    {
        arrayMitad[i] = array[i + (sizeArray / 2)];
    }

    return 0;
}

int invierteArray(int* array, int* inversa, int size)
{
    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        inversa[i] = array[j];
    }

    return 0;
}

bool sonDigitos9(int* array, int size)
{
    bool son9 = true;
    int i = 0;

    while (son9 && i < size)
    {
        if (array[i] != 9)
        {
            son9 = false;
        }
        i++;
    }
    
    return son9;
}

bool sonDigitos1Y0(int* array, int size)
{
    bool son1Y0 = true;
    int i = 1;

    if (array[0] == 1)
    {
        while (son1Y0 && i < size)
        {
            if (array[i] != 0)
            {
                son1Y0 = false;
            }
            i++;
        }   
    }
    else
    {
        son1Y0 = false;
    }
    
    return son1Y0;
}

int digitosAnum(int* array, int nDigitos)
{
    int num = 0, exp = nDigitos -1;

    for (int i = 0; i < nDigitos; i++, exp--)
    {
        num += array[i] * pow(10, exp);
    }
    
    return num;
}

int quitaPrimerDigito(int n, int nDigitos)
{
    int num;
    
    num = n % (int)pow(10, (nDigitos - 1));

    return num;
}

int main()
{
    int casosPrueba, n, distancia = -1;
    
    cin >> casosPrueba;

    while (casosPrueba--)
    {
        cin >> n;

        if(n < 9)
        {
            distancia = 1;
        }
        else if (n == 9)
        {
            distancia = 2;
        }
        else
        {
            int size = nDigitos(n), nArr[size];
            numAdigitos(n, nArr, size);

            if (sonDigitos9(nArr, size))
            {
                distancia = 2;
            }
            else if (sonDigitos1Y0(nArr, size))
            {
                distancia = 1;
            }
            else if (size % 2 == 0)
            {
                int nArrMitad0[size/2], nArrMitad1[size/2], nArrMitad0Inversa[size/2], mitad0Inversa, mitad0, mitad1, capicua0, arrCapicua0[size], arrMitad0C0[size/2], mitad0C0, capicua1, mitad0C1, arrMitad0C1[size/2], arrMitad0C1Inversa[size/2], mitad1C1;

                mitadIzquierda(nArr, nArrMitad0, size);
                mitadDerecha(nArr, nArrMitad1, size);
                invierteArray(nArrMitad0, nArrMitad0Inversa, size/2);
                mitad0Inversa = digitosAnum(nArrMitad0Inversa, size/2);
                mitad1 = digitosAnum(nArrMitad1, size/2);
                
                if (mitad0Inversa > mitad1)
                {
                    distancia = mitad0Inversa - mitad1;
                }
                else if (mitad0Inversa < mitad1)
                {
                    capicua0 = n - (mitad1 - mitad0Inversa);
                    numAdigitos(capicua0, arrCapicua0, size);
                    mitadIzquierda(arrCapicua0, arrMitad0C0, size);
                    mitad0C0 = digitosAnum(arrMitad0C0, size/2);
                    mitad0C1 = mitad0C0 + 1;
                    numAdigitos(mitad0C1, arrMitad0C1, size/2);
                    invierteArray(arrMitad0C1, arrMitad0C1Inversa, size/2);
                    mitad1C1 = digitosAnum(arrMitad0C1Inversa, size/2);
                    capicua1 = (mitad0C1 * pow(10, size/2)) + mitad1C1;
                    distancia = capicua1 - n;
                }
                else
                {
                    mitad0 = digitosAnum(nArrMitad0, size/2);
                    mitad0C1 = mitad0 + 1;
                    numAdigitos(mitad0C1, arrMitad0C1, size/2);
                    invierteArray(arrMitad0C1, arrMitad0C1Inversa, size/2);
                    mitad1C1 = digitosAnum(arrMitad0C1Inversa, size/2);
                    capicua1 = (mitad0C1 * pow(10, size/2)) + mitad1C1;
                    distancia = capicua1 - n;
                }
            }
            else
            {
                
                int nArrMitad0[(size/2) + 1], nArrMitad1[(size/2) + 1], nArrMitad0Inversa[(size/2) + 1], mitad0Inversa, mitad0, mitad1, capicua0, arrCapicua0[size], arrMitad0C0[(size/2) + 1], mitad0C0, capicua1, mitad0C1, arrMitad0C1[(size/2) + 1], arrMitad0C1Inversa[(size/2) + 1], mitad1C1;

                mitadIzquierda(nArr, nArrMitad0, size);
                mitadDerecha(nArr, nArrMitad1, size);
                invierteArray(nArrMitad0, nArrMitad0Inversa, ((size/2) + 1));
                mitad0Inversa = digitosAnum(nArrMitad0Inversa, ((size/2) + 1));
                mitad1 = digitosAnum(nArrMitad1, ((size/2) + 1));

                if (mitad0Inversa > mitad1)
                {
                    distancia = mitad0Inversa - mitad1;
                }
                else if (mitad0Inversa < mitad1)
                {
                    capicua0 = n - (mitad1 - mitad0Inversa);
                    numAdigitos(capicua0, arrCapicua0, size);
                    mitadIzquierda(arrCapicua0, arrMitad0C0, size);
                    mitad0C0 = digitosAnum(arrMitad0C0, ((size/2) + 1));
                    mitad0C1 = mitad0C0 + 1;
                    numAdigitos(mitad0C1, arrMitad0C1, ((size/2) + 1));
                    invierteArray(arrMitad0C1, arrMitad0C1Inversa, ((size/2) + 1));
                    mitad1C1 = digitosAnum(arrMitad0C1Inversa, ((size/2) + 1));
                    capicua1 = (mitad0C1 * pow(10, (size/2))) + quitaPrimerDigito(mitad1C1, (size/2)+1);
                    distancia = capicua1 - n;
                }
                else
                {
                    mitad0 = digitosAnum(nArrMitad0, ((size/2) + 1));
                    mitad0C1 = mitad0 + 1;
                    numAdigitos(mitad0C1, arrMitad0C1, ((size/2) + 1));
                    invierteArray(arrMitad0C1, arrMitad0C1Inversa, ((size/2) + 1));
                    mitad1C1 = digitosAnum(arrMitad0C1Inversa, ((size/2) + 1));
                    capicua1 = (mitad0C1 * pow(10, (size/2)) + quitaPrimerDigito(mitad1C1, (size/2)+1));
                    distancia = capicua1 - n;
                }
            }
            
        }
        cout << distancia << "\n";
    }
    
    return 0;
}