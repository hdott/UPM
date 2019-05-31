public class Person
{
    private String lastName;
    private String firstName;
    private int age;

    public Person(String lastName, String firstName, int age)
    {
        this.lastName = lastName;
        this.firstName = firstName;
        this.age = age;
    }

    public String getLastName()     {return lastName;}
    public String getFirstName()    {return firstName;}
    public int getAge()             {return age;}

    public void setLastName(String name)    {this.lastName = name;}
    public void setFirstName(String name)   {this.firstName = name;}
    public void setAge(int age)             {this.age = age;}

    public String toString()
    {
        return (firstName + ", " + lastName + " " + age);
    }
}