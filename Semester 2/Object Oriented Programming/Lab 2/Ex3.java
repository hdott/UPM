import java.util.Scanner;

public class Ex3
{
    public static void main(String args[])
    {
        Masina car = new Masina("SUV","BLUE",170);

        car.setType("SUV");
        car.setColour("BLUE");
        car.setSpeed(170);

        System.out.println("car.type = " + car.getType());
        System.out.println("car.colour = " + car.getCoulour());
        System.out.println("car.speed = " + car.getSpeed());

        Scanner read = new Scanner(System.in);
        
        System.out.print("Input a number: ");
            int N = read.nextInt();

        Masina vector[] = new Masina[N];
        for(int i=0; i<N; ++i)
        {
            read.nextLine();    // reads a newline from the buffer
            System.out.print("\nInput car type = ");
                String type = read.nextLine();
            System.out.print("Input car colour = ");
                String colour = read.nextLine();
            System.out.print("Input car speed = ");
                double speed = read.nextDouble();
            
            vector[i] = new Masina(type,colour,speed);
        }
        System.out.println("\n");

        for(int i=0; i<N; ++i)
            System.out.println(vector[i]);
    }    
}