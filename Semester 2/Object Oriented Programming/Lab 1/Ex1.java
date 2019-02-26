import java.util.Scanner;
import java.util.Random;

public class Ex1
{
    public static void main(String args[])
    {
        Scanner read = new Scanner(System.in);
        
        System.out.println("Introduceti 2 numere intregi: ");
            int nr1 = read.nextInt();
            int nr2 = read.nextInt();

        System.out.println("Suma numerelor este: "+ (nr1+nr2));
        System.out.println("Produsul numerelor este: "+ (nr1*nr2));
        System.out.println("Catul impartirii "+ nr1 + " la " + nr2 + "este: "+ (nr1/nr2));
        System.out.println("Restul impartirii "+ nr1 + " la " + nr2 + "este: "+ (nr1%nr2));
 
        Random rnd = new Random();
        
        int random1 = rnd.nextInt(255);
        int random2 = rnd.nextInt(255);
        System.out.println("Valoarea "+nr1+" dupa inmultirea cu "+random1+" este: "+(nr1*random1));
        System.out.println("Valoarea "+nr2+" dupa inmultirea cu "+random2+" este: "+(nr2*random2));
    }
}