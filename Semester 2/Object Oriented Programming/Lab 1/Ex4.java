import java.util.Scanner;

public class Ex4
{
    public static void main(String args[])
    {
        Scanner read = new Scanner(System.in);

        System.out.println("Introduceti numarul de randuri al matricei:");
            int row = read.nextInt();
        System.out.println("Introduceti numarul de coloane al matricei:");
            int col = read.nextInt();

        int matrix[][] = new int[row][col];
        System.out.println("Introduceti elementele matricei:");
            for(int i=0; i<row; ++i)
                for(int j=0; j<col; ++j)
                    matrix[i][j] = read.nextInt();
        System.out.println();

        String meniu[] = {"1. Afisare minim pe linii, maxim pe coloane.",
                        "2. Afisare diagonala principala si diagonala secundara.",
                        "3. Afisare matrice dupa interschimbare prima linie cu ultima.",
                        "4. Sa se elimine linia c si coloana l (citite de la tastatura), "+
                            "dupa care sa se afiseze matricea rezultata",
                        "5. Afisare produsul numerelor prime"};

        System.out.println();
        for(int i=0; i<5; ++i)
            System.out.println(meniu[i]);
        System.out.print("\nAlegeti o optiune: ");
            int optiune = read.nextInt();
        System.out.println();

        switch(optiune)
        {
            case (1):
                int minim[] = new int[col];
                int maxim[] = new int[row];
                for(int i=0; i<row;++i)
                    for(int j=0; j<col; ++j)
                        if(j==0)
                            minim[i] = matrix[i][j];
                        else if(matrix[i][j] < minim[i])
                            minim[i] = matrix[i][j];
                
                for(int j=0; j<col; ++j)
                    for(int i=0; i<row; ++i)
                        if(i==0)
                            maxim[i] = matrix[i][j];
                        else if(matrix[i][j] > maxim[i])
                            maxim[i] = matrix[i][j];

                System.out.println("Minimul pe linii este:");
                    for(int i=0; i<row; ++i)
                        System.out.println("Linia["+i+"]: "+minim[i]);
                System.out.println();

                System.out.println("Maximul pe coloane este:");
                    for(int j=0; j<col; ++j)
                        System.out.println("Coloana["+j+"]: "+maxim[j]);
                break;

            case (2):
                int minim_;
                if(row>col)
                    minim_ = col;
                else
                    minim_ = row;

                System.out.println("Diagonala principala este:");
                    for(int i=0,j=0; i<minim_; ++i,++j)
                        System.out.print(matrix[i][j]+"\t");
                System.out.println("\nDiagonala secundara este:");
                    for(int i=0,j=col-1; i<minim_; ++i,--j)
                        System.out.print(matrix[i][j]+"\t");
                System.out.println();
                break;

            case (3):
                System.out.println("Matricea dupa interschimbarea primei linii cu ultima:");
                    for(int i=0,j=0,x=row-1; j<col; ++j)
                    {
                        int aux = matrix[i][j];
                        matrix[i][j] = matrix[x][j];
                        matrix[x][j] = aux;
                    }
                    
                    for(int i=0; i<row; ++i)
                    {
                        for(int j=0; j<col; ++j)
                            System.out.print(matrix[i][j]+"\t");
                        System.out.println();
                    }
                break;

            case (4):
                System.out.print("Introduceti o linie care sa fie eliminata: ");
                    int elim_row = read.nextInt();
                System.out.print("Introduceti o coloana care sa fie eliminata: ");
                    int elim_col = read.nextInt();

                for(int i=0; i<row-1; ++i)
                    if(i>=elim_row-1)
                        for(int j=0; j<col; ++j)
                            matrix[i][j] = matrix[i+1][j];
                
                for(int j=0; j<col-1; ++j)
                    if(j>=elim_col-1)
                        for(int i=0; i<row-1; ++i)
                            matrix[i][j] = matrix[i][j+1];
                
                System.out.println("Matricea rezultata dupa eliminare este:");
                    for(int i=0; i<row-1; ++i)
                    {
                        for(int j=0; j<col-1; ++j)
                            System.out.print(matrix[i][j]+"\t");
                        System.out.println();
                    }
                break;

            case (5):
                int prod_nr_prime=0;

                for(int i=0; i<row; ++i)
                    for(int j=0; j<col; ++j)
                    {
                        int conditie = 1;
                        for(int z=2; z<matrix[i][j]; ++z)
                            if(matrix[i][j]%z == 0)
                            {
                                conditie = 0;
                                break;
                            }
            
                        if(prod_nr_prime==0 && conditie==1)
                            prod_nr_prime = matrix[i][j];
                        else if(prod_nr_prime!=0 && conditie==1)
                            prod_nr_prime *= matrix[i][j];
                    }
                        
                System.out.println("Produsul numerelor prime este: "+prod_nr_prime);
                break;
        }
    }    
}