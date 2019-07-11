import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;

import javax.swing.JLabel;
import javax.swing.JPanel;

public class LinkedList{
    
    private Node head;

    class Node{
        Person person;
        Node next;

        public Node (Person person){
            this.person = person;
            next = null;
        }
    }


    public LinkedList() {
        this.head = null;
    }

    public Node getIterator(){
        return head;
    }

    public Node getNext(Node tracer){
        return tracer.next;
    }

    public boolean hasNext(Node tracer){
        if (tracer.next != null) {
            return true;
        }

        return false;
    }

    /*
     * Insert Methods
     */
    public void insertStart (Person person){
        Node newN = new Node(person);

        if (this.head == null)   this.head = newN;
        else{
            newN.next = this.head;
            
            this.head = newN;
        }
    }

    public void insertEnd(Person person){
        Node newN = new Node(person);

        if (this.head == null)   this.head = newN;
        else{
            Node tracer = this.head;

            while (tracer.next != null) {
                tracer = tracer.next;                
            }

            tracer.next = newN;
        }
    }


    /*
     * Delete Methods
     */
    public void deleteFirst(){
        if (this.head == null) {
            this.head = this.head.next;            
        }
    }

    public void deleteLast(){
        if (this.head == null) {
            return;            
        } else {
            Node tracer = this.head;

            while (tracer.next.next != null) {
                tracer = tracer.next;                
            }

            tracer.next = null;
        }
    }


    /*
     * Draw Methods
     */
    // @Override
    // protected void paintComponent(Graphics g) {
    //     super.paintComponents(g);
    //     // var g2 = (Graphics2D) g;
       
    //     Node tracer = this.head;

    //     int x = 10,
    //         y = 10;

    //     while (tracer != null) {
    //         String persoana = tracer.toString();
    //         g.drawString(persoana, x, y);
    //         x += 10;
    //         y += 10;
    //     }
    // }

    // public synchronized void buildList(){
    //     removeAll();

    //     Node tracer = this.head;
    //     int i = 0;

    //     while (tracer != null) {
    //         // var label = new JLabel(tracer.person.toString());
    //         add(new JLabel(tracer.person.toString()), i++);
    //         revalidate();
    //         repaint();
    //         System.out.println(tracer.person.toString());
    //         tracer = tracer.next;
    //     }

        
    //     revalidate();
    //     repaint();
    // }
}