import java.util.Scanner;

public class Ex1
{
    public static void main(String args[])
    {
        Scanner read = new Scanner(System.in);

        int size1, size2;

        System.out.print("Introduceti marimea primului Vector: ");
            size1 = read.nextInt();
        System.out.print("Introduceti marimea celui de-al doilea Vector: ");
            size2 = read.nextInt();

        int v1[] = new int[size1];
        int v2[] = new int[size2];

        System.out.println("\nIntroduceti elementele primului Vector:");
            for(int i=0; i<size1; ++i)
            {
                System.out.print("[" + (i+1) + "] = ");
                v1[i] = read.nextInt();
            }

        System.out.println("\nIntroduceti elementele celui de-al doilea Vector:");
            for(int i=0; i<size2; ++i)
            {
                System.out.println("[" + (i+1) + "] = ");
                v2[i] = read.nextInt();
            }
        

        int v3[], v4[], v5[], v6[];
        v3 = OpMatrici.AddVector(v1, size1, v2, size2);
        v4 = OpMatrici.SubstractVector(v1, size1, v2, size2);
        v5 = OpMatrici.VectorMultiplication(v1, size1, v2, size2);
        v6 = OpMatrici.VectorDivision(v1, size1, v2, size2);
    }
}