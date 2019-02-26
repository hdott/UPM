import java.util.Scanner;

public class Ex3
{
    public static void main(String args[])
    {
        Scanner read = new Scanner(System.in);

        System.out.println("Introduceti marimea unui sir de numere intregi:");
            int size = read.nextInt();

        int array[] = new int[size];
        System.out.println("Introduceti un sir de "+size+" numere intregi:");
            for(int i=0; i<size; ++i)
                array[i] = read.nextInt();
        
        System.out.println();
        String strings[] = {"1. Afisare maxim.",
                            "2. Afisare minim",
                            "3. Afisare suma numerelor pare.",
                            "4. Afisare produsul numerelor prime"};

        for(int i=0; i<4;++i)
            System.out.println(strings[i]);

        int maxim = array[0];
        int minim = array[0];
        for(int i = 0; i<size; ++i)
        {
            if(array[i]>maxim)
                maxim=array[i];
            if(array[i]<minim)
                minim=array[i];
        }

        int sum_nr_pare = 0;
        for(int i=0; i<size;++i)
            if(array[i]%2 == 0)
                sum_nr_pare+=array[i];

        int prod_nr_prime = 0;
        for(int i=0; i<size;++i)
        {
            int conditie = 1;
            for(int j=2; j<array[i]; ++j)
                if(array[i]%j == 0)
                {
                    conditie = 0;
                    break;
                }

            if(prod_nr_prime==0 && conditie==1)
                prod_nr_prime = array[i];
            else if(prod_nr_prime!=0 && conditie==1)
                prod_nr_prime *= array[i];
        }

        System.out.print("\nAlegeti o optiune: ");
            int optiune = read.nextInt();

        switch(optiune)
        {
            case (1):
                System.out.println("\nMaximul este: " + maxim);
                break;
            case (2):
                System.out.println("\nMinimul este: " + minim);
                break;
            case (3):
                System.out.println("\nSuma numerelor pare este: " + sum_nr_pare);
                break;
            case (4):
                System.out.println("\nProdusul numerelor prime este: " + prod_nr_prime);
                break;
            default:
                System.out.println("Optiunea selectata nu este disponibila!");
        }
    }
}