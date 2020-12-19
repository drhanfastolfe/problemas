import java.util.Arrays;
import java.util.Scanner;

public class constanteKaprekar
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int nNums, num, resultado, numAsc, numDes, i, k;
        
        System.out.println("Introduce el número de casos de prueba:");
        nNums = sc.nextInt();
        
        int[] iteraciones = new int[nNums];
        int[] nums = new int[nNums];

        for(i = 0; i < nNums; i++)
        {
            do
            {
                System.out.println("Introduce el caso de prueba " + (i + 1) + ":");
                num = sc.nextInt();
            } while (!(num > 0) || digitosIguales(num) || nDigitos(num) > 4);
            
            nums[i] = num;
        }

        for(i = 0; i < nums.length; i++)
        {
            k = 0;
            resultado = nums[i];
            while (resultado != 6174)
            {
                int[] arrNumAsc = ordenaDigitosAscendente(resultado);
                numAsc = arrNumAsc[0] * 1000 + arrNumAsc[1] * 100 + arrNumAsc[2] * 10 + arrNumAsc[3];

                int[] arrNumDes = invierteArray(arrNumAsc);
                numDes = arrNumDes[0] * 1000 + arrNumDes[1] * 100 + arrNumDes[2] * 10 + arrNumDes[3];

                resultado = numDes - numAsc;

                k++; 
            }
            iteraciones[i] = k;
        }

        for(i = 0; i < iteraciones.length; i++)
        {
            System.out.println(iteraciones[i]);
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

    public static int nDigitos(int n)
    {
        return String.valueOf(n).length();
    }

    public static int[] ordenaDigitosAscendente(int n)
    {
        int num = n;
        String strNum;
        int[] arrNum = new int[4];

        while (num < 999)
        {
            num *= 10;    
        }

        strNum = String.valueOf(num);

        for(int i = 0; i < strNum.length(); i++)
        {
            arrNum[i] = Character.getNumericValue(strNum.charAt(i));
            
        }
        
        Arrays.sort(arrNum); 

        return arrNum;
    }
    
    public static int[] invierteArray(int[] n)
    {
        int[] inverso = new int[n.length];
        int j = 0;
        for(int i = n.length-1; i >= 0; i--)
        {
            inverso[j] = n[i]; 
            j++;
        }

        return inverso;
    }
}