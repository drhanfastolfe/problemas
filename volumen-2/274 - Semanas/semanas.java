import java.util.Scanner;

public class semanas 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int casosPrueba, anio, semana, dia, semanasCompletas;
 
        casosPrueba = sc.nextInt();

        while (casosPrueba > 0)
        {
            anio = sc.nextInt();
            semana = sc.nextInt();
            dia = sc.nextInt();

            if (dia == 1)
            {
                semanasCompletas = anio / semana;
            }
            else
            {
                semanasCompletas = (anio - (semana - (dia - 1))) / semana;
            }

            System.out.println(semanasCompletas);

            casosPrueba--;    
        }
        sc.close();
    }    
}