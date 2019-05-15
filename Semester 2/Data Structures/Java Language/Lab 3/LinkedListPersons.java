import java.util.Objects;

public class LinkedListPersons
{
    private Node head;

    class Node
    {
        Person person;
        Node next;

        public Node(Person person)
        {
            this.person = person;
            next = null;
        }
    }

    public LinkedListPersons()  {this.head = null;}

    //insert Methods
    public void insertStart(Person person)
    {
        Node newN = new Node(person);

        if(this.head == null)   this.head = newN;
        else
        {
            newN.next = this.head;
            
            this.head = newN;
        }
    }

    public void insertEnd(Person person)
    {
        Node newN = new Node(person);

        if(this.head == null)   this.head = newN;
        else
        {
            Node tracer = this.head;

            while(tracer.next != null)  tracer = tracer.next;

            tracer.next = newN;
        }
    }

    public void insertBeforeKey(Person person, String key)
    {
        Node newN = new Node(person);

        if(this.head == null)   this.head = newN;
        else
        {
            Node tracer = this.head;

            while(tracer.next != null && !Objects.equals(
                    tracer.next.person.getFirstName(), key))
                tracer = tracer.next;

            newN.next = tracer.next;
            tracer.next = newN;
        }
    }

    public void insertAfterKey(Person person, String key)
    {
        Node newN = new Node(person);
        
        if(this.head == null)   this.head = newN;
        else
        {
            Node tracer = this.head;

            while(tracer != null && !Objects.equals(
                    tracer.person.getFirstName(), key))
                tracer = tracer.next;

            newN.next = tracer.next;
            tracer.next = newN;
        }
    }

    //delete Methods
    public void deleteFirst()
    {
        if(this.head != null)   this.head = this.head.next;
    }

    public void deleteLast()
    {
        if(this.head == null)   return;
        else
        {
            Node tracer = this.head;

            while(tracer.next != null)  tracer = tracer.next;

            tracer.next = null;
        }
    }

    public void deleteKey(String lastName, String firstName)
    {
        boolean present = false;
        Node tracer = this.head;

        while(tracer != null)
        {
            if(Objects.equals(tracer.next.person.getLastName(), lastName) &&
                Objects.equals(tracer.next.person.getFirstName(), firstName))
            {
                person = true;
                break;
            }

            tracer = tracer.next;
        }

        if(present) tracer.next = tracer.next.next;
        else    System.out.println("Elementul nu a fost Gasit!");
    }

    //search Methods
    public void searchFirstName(String firstName)
    {
        boolean present = false;
        Node tracer = this.head;

        while(tracer != null)
        {
            if(Objects.equals(tracer.person.getFirstName(), firstName))
            {
                present = true;
                break;
            }

            tracer = tracer.next;
        }

        if(present) System.out.println(tracer.person);
        else        System.out.println("Person is not Present!");
    }

    public void searchLastName(String lastName)
    {
        boolean present = false;
        Node tracer = this.head;

        while(tracer != null)
        {
            if(Objects.equals(tracer.person.getLastName(), lastName))
            {
                present = true;
                break;
            }

            tracer = tracer.next;
        }

        if(present) System.out.println(tracer.person);
        else        System.out.println("Person is not Present!");
    }

    public void searchAge(int age)
    {
        boolean present = false;
        Node tracer = this.head;

        while(tracer != null)
        {
            if(tracer.person.getAge() == age)
            {
                present = true;
                break;
            }

            tracer = tracer.next;
        }

        if(present) System.out.println(tracer.person);
        else        System.out.println("Person is not Present!");
    }

    //print Method
    public void printList()
    {
        Node tracer = this.head;

        if(tracer == null)  return;
        else
        {
            while(tracer != null)
            {
                System.out.println(tracer.person);

                tracer = tracer.next;
            }
        }
    }

    //destroy Method
    public void Destroy()
    {
        this.head = null;
    }

    // public static void main(String[] args)
    // {
    //     var Lista = new LinkedListPersons();

    //     Lista.insertStart(new Person("Nuta", "Horia", 26));
    //     Lista.insertStart(new Person("Radulescu", "Ioana", 19));
    //     Lista.insertBeforeKey(new Person("lala", "lala2", 44), "Horia");   


    //     Lista.printList();
    // }
}