import java.util.Scanner;

public class constanteKaprekar
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int nNums, num;

        System.out.println("Introduce el número de casos de prueba:");
        nNums = sc.nextInt();

        int[] nums = new int[nNums];

        for(int i = 0; i < nNums; i++)
        {
            do
            {
                System.out.println("Introduce el caso de prueba " + (i + 1) + ":");
                num = sc.nextInt();
            } while (!(num > 0) || digitosIguales(num));
            
            nums[i] = num;
        }


    }

    public static boolean digitosIguales(int n)
    {
        boolean iguales = true;
        String nStr = String.valueOf(n);
        int i;

        if (n > 999)
        {
            i = 1;
            while (iguales && i < nStr.length())
            {
                if(nStr.charAt(i - 1) != nStr.charAt(i))
                {
                    iguales = false;
                }
                i++;
            }    
        }
        else
        {
            iguales = false;
        }

        return iguales;
    }
}