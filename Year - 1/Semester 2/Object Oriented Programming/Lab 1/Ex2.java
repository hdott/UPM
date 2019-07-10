import java.util.Scanner;

public class Ex2
{
    public static void main(String args[])
    {
        Scanner read = new Scanner(System.in);

        System.out.println("Introduceti un numar intreg de 4 cifre: ");
            int nr = read.nextInt();

        int array[] = new int[4];
        for(int i=0; i<4; ++i)
        {
            array[i]=nr%10;
            nr/=10;
        }

        String strings[] = {"1. Afisare paritate ultima cifra.",
                            "2. Afisare paritate prima cifra.",
                            "3. Afisare suma cifrelor."};

        for(int i=0; i<3; ++i)
            System.out.println(strings[i]);
        System.out.print("Alegeti o optiune: ");
            int optiune = read.nextInt();

        switch(optiune)
        {
            case (1):
                if(array[0]%2 == 0)
                    System.out.println("Ultima cifra este para!");
                else
                    System.out.println("Ultima cifra este impara!");
                break;
            case (2):
                if(array[3]%2 == 0)
                    System.out.println("Prima cifra este para!");
                else
                    System.out.println("Prima cifra este impara!");
                break;
            case (3):
                int sum = 0;
                for(int i=0; i<4; ++i)
                    sum+=array[i];
                System.out.println("Suma cifrelor este: " + sum);
                break;
        }
    }
}