public class Ex1
{
    public static void main(String args[])
    {
        Masina car = new Masina();

        car.setType("SUV");
        car.setColour("BLUE");
        car.setSpeed(170);

        System.out.println("car.type = " + car.getType());
        System.out.println("car.colour = " + car.getCoulour());
        System.out.println("car.speed = " + car.getSpeed());

    }
}