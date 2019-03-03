import java.util.Scanner;

public class Ex1
{
    public static void main(String args[])
    {
        ContBancar cont = new ContBancar(0.0);  // class initialization

        Scanner read = new Scanner(System.in);

        for(int i=0; i<2; ++i)
        {
            System.out.print("Input the sum to be deposited: ");
                cont.depozitareSuma(read.nextInt());
        }
    }
}