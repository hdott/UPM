import java.util.Random;

public class Ex2
{
    public static void main(String args[])
    {
        ContBancar cont = new ContBancar(500);

        // depoziteaza 300 RON
        cont.depozitareSuma(300);
        
        // intorgheaza soldul
        System.out.println(cont.getSold());

        // genereaza un numar aleator N (0-1000)
        Random rnd = new Random();
        
        int N = rnd.nextInt(1000);

        /* Sa se efectueze N operatii aleatorii (cu valori aleatorii intre 0-100)
         *  asupra contului bancar, fiecare din cele doua operatii se va efectua
         *  cu o probabilitate de 50%;
         */
        int depozit, retragere;
        depozit = retragere = 0;
        
        for(int i=0; i<N; ++i)
        {
            int probabilitate = rnd.nextInt(99);

            if(probabilitate < 50)
            {
                cont.depozitareSuma(rnd.nextInt(100));
                System.out.println(cont.getSold());
                depozit++;
            }
            else
            {
                System.out.print(cont.getSold());
                System.out.println(" "+cont.retrageSuma(rnd.nextInt(100)));
                retragere++;
            }
        }

        System.out.println("\ndepozit = "+ depozit + "\tretragere = "+ retragere);
    }
}