import java.util.Scanner;

public class laLoteriaDeLaPeniaAtletica
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int casosPrueba, nDecimos, decimo, pares;

        casosPrueba = sc.nextInt();

        while (casosPrueba > 0)
        {
            nDecimos = sc.nextInt();
            pares = 0;

            for (int i = 0; i < nDecimos; i++)
            {
                decimo = sc.nextInt();

                if (decimo % 2 == 0)
                {
                    pares++;
                }
            }

            System.out.println(pares);
            casosPrueba--;    
        }

        sc.close();
    }    
}