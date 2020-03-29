
// modifed by oznur tastan  07/12/2015

import java.util.*; // to throw exceptions
public class Queue
{
    private int size;      // number of elements on queue
    private Node first;    // beginning of queue
    private Node last;     // end of queue

    /**
     * Initializes an empty queue.
     */
    public Queue() 
    {
        first = null;
        last  = null;
        size = 0;
    }

    /**
     * Is this queue empty?
     * @return true if this queue is empty; false otherwise
     */
    public boolean isEmpty()
    {
        return first == null;
    }

    /**
     * Returns the number of items in this queue.
     * @return the number of items in this queue
     */
    public int size() {
        return size;     
    }

    /**
     * Returns the item least recently added to this queue.
     * @return the item least recently added to this queue
     * @throws java.util.NoSuchElementException if this queue is empty
     */
    public int peek() {
        if (isEmpty())
        	 throw new NoSuchElementException("Queue underflow");
        	
        return first.item;
    }

    /**
     * Adds the item to this queue.
     * @param item the item to add
     */
    public void enqueue(int item) {
        Node oldlast = last;
        
        last = new Node(item, null);
        
        if (isEmpty()) 
        	first = last;
        else           
        	oldlast.next = last;
        
        size++;
    }

    /**
     * Removes and returns the item on this queue that was least recently added.
     * @return the item on this queue that was least recently added
     * @throws java.util.NoSuchElementException if this queue is empty
     */
    public int dequeue() {
    
        if (isEmpty())
        {
        	 throw new NoSuchElementException("Queue underflow");
        }
        int item = first.item;
        first = first.next;
        
        size--;
    
        return item;
    }

    /**
     * Returns a string representation of this queue.
     * @return the sequence of items in FIFO order, separated by spaces
     */
    public String toString() {
        String s = "";
        
        if (isEmpty())
            return s;

        Node current;
        for (current = first; current.next!= null; current = current.next)
             s  += current.item + ", ";
         
         s += current.item;  
        return s;
    } 
    	
       // helper linked list class
     private class Node
    {
    	private int item;
    	private Node next;
    	
    	public Node()
    	{
    		
    	}
    	public Node (int item)
    	{
    		this.item = item;
    		next = null;
    	}
    	public Node (int item, Node next)
    	{ 
           	this.item = item;
            this.next = next;
    	}
    }

}