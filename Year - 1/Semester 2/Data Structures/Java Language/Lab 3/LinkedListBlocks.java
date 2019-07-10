public class LinkedListBlocks
{
    private Node head;

    class Node
    {
        String blockName;
        LinkedListPersons personsList;
        Node next;
        
        public Node(String blockName, LinkedListPersons personList)
        {
            this.blockName = blockName;
            this.personsList = personList;
            next = null;
        }
    }

    public LinkedListBlocks()   {this.head = null;}
}