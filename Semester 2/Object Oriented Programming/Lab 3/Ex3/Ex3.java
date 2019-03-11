public class Ex3
{
    public static void main(String args[])
    {
        Masina car1 = new Masina();
            System.out.println("car.type = " + car1.getType());
            System.out.println("car.colour = " + car1.getCoulour());
            System.out.println("car.speed = " + car1.getSpeed());
            System.out.println();
        
        Masina car2 = new Masina("SUV");
            System.out.println("car.type = " + car2.getType());
            System.out.println("car.colour = " + car2.getCoulour());
            System.out.println("car.speed = " + car2.getSpeed());
            System.out.println();

        Masina car3 = new Masina("Hatchback", "Pink");
            System.out.println("car.type = " + car3.getType());
            System.out.println("car.colour = " + car3.getCoulour());
            System.out.println("car.speed = " + car3.getSpeed());
            System.out.println();

        Masina car4 = new Masina("Crossover", "Fucshia", 155.2);
            System.out.println("car.type = " + car4.getType());
            System.out.println("car.colour = " + car4.getCoulour());
            System.out.println("car.speed = " + car4.getSpeed());
            System.out.println();
    }
}