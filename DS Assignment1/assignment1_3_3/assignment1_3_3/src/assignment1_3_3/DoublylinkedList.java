package assignment1_3_3;

public class DoublylinkedList {
	private Node Head;
    private int Count;
    public DoublylinkedList() {
    	Head = new Node(null);
        Count=0;
    }
    
    private class Node {
        private Object data;
        private Node Prev;
        private Node Next;
        
        Node(Object data) {
            this.data = data;
            this.Prev = null;
            this.Next = null;
        }
    }
    
    private Node getNode(int Position) {
        
        if(Position < 0 || Position > Count) {
            throw new IndexOutOfBoundsException("Index : "+Position+", Size : " + Count);
        }
        
        Node node = Head;
        
        if(Position < (Count/2)) {
            
            for(int i =0; i<=Position; i++) {
                node = node.Next;
            }
            
        }
        else {
            for(int i = Count; i > Position; i--) {
                node = node.Prev;
            }
        }
        return node;
    }
    
    public Object get(int Position) {
        return getNode(Position).data;
    }

    public Object getFirst() {
        return get(0);
    }
    
    private int getNodeIndex(Object item) {
        if(Count<=0) {
            return -1;
        }
        
        int index =0;
        Node node = Head.Next;
        Object nodeDate = node.data;
        
        while(!item.equals(nodeDate)) {
            
            node = node.Next;
            
            if(node==null) {
                return -1;
            }
            nodeDate = node.data;
            index++;
        }
        return index+1;
    }
    
    public void InsertFirst(Object data) {
        Node newNode = new Node(data);    
        newNode.Next = Head.Next;    

        if(Head.Next != null) {
        	Head.Next.Prev = newNode;
        
        }
        else {
        	Head.Prev = newNode;
        }
        Head.Next = newNode;
        Count++;
    }
    
    public void Insert(int Position, Object Item) {
        if(Position ==0) {
        	InsertFirst(Item);
            return;
        }
        Node previous = getNode(Position-1);
        Node next = previous.Next;
        
        Node newNode = new Node(Item);
        
        previous.Next = newNode;
        newNode.Prev = previous;
        newNode.Next = next;
        
        if(newNode.Next != null) {
            next.Prev = newNode;
        }
        else {
        	Head.Prev = newNode;
        }
        Count++;
    }
    
    public void InsertLast(Object data) {
    	Insert(Count, data);
    }
    
    public void Insert(Object data) {
    	InsertLast(data);
    }
    
    public Object DeleteFirst() {
        Node firstNode = getNode(0);
        Head.Next = firstNode.Next;

        if(Head.Next != null) {
            firstNode.Next.Prev = null;
        }
        else {
        	Head.Prev = null;
        }   
        Count--;
        
        return firstNode.data;
    }

    public Object Delete(int Position) {
        
        if(Position<0 || Position>=Count) {
            throw new IndexOutOfBoundsException("Index : " + Position + ", Size : " + Count);
        }
        else if(Position==0) {
            return DeleteFirst();
        }
        
        Node deleteNode = getNode(Position);
        Node previous = deleteNode.Prev;
        Node next = deleteNode.Next;
        previous.Next = next;

        if(next!=null) {
            next.Prev = previous;
        }
        else {
        	Head.Prev = previous;  
        }
        Count--;

        return deleteNode.data;
    }
    
    public Object DeleteLast() {
        return Delete(Count-1);
    }
    
    public boolean isEmpty() {
        if(Count == 0) {
            return true;
        }
        else{
            return false;
        }
    }
    
    public int Length() {
        return Count;
    }
    
    public String toString() {
        StringBuffer result = new StringBuffer("(");
        Node node = Head.Next;
        
        if(node != null) {
            result.append(node.data);
            node = node.Next;
            
            while(node!=null) {
                result.append(", ");
                result.append(node.data);
                node = node.Next;
            }
        }
        result.append(")");
        
        return result.toString();
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DoublylinkedList a = new DoublylinkedList();
		
		System.out.println(a.isEmpty());
		a.Insert(50);
		a.Insert(40);
		a.Insert(80);
		a.Insert(120);
		a.Insert(150);
		System.out.println(a);
		
		a.Insert(3, 200);
		a.InsertFirst(75);
		a.InsertLast(450);
		System.out.println(a);
		
		System.out.println(a.getNodeIndex(a.get(5)) + "번째 " + a.get(5));
		System.out.println(a.getNodeIndex(a.get(2)) + "번째 " + a.get(5));
		
		a.Delete(3);
		a.Delete(5);
		System.out.println(a.isEmpty());
		System.out.println(a);
		
		a.DeleteFirst();
		a.DeleteLast();
		System.out.println(a);
		
		System.out.println(a.Length());
		
	}

}
