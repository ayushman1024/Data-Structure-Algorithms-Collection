class Node{
  int data;
  Node next;
  Node(int key){
    this.data = key;
  }
}

class List{
  Node head;
  void insertBegin(int key){
    Node temp = new Node(key);
    temp.next = head;
    head = temp;
  }
  void insertLast(int key){
    if(head == null){
      head = new Node(key);
      return;
    }
    Node temp = head;
    while(temp.next != null){
      temp = temp.next;
    }
    Node newNode = new Node(key);
    temp.next = newNode;
  }
  int middleNode(){
    Node slow = head;
    Node fast = head;
    while(fast != null && fast.next != null){
      slow = slow.next;
      fast = fast.next.next;
    }
    System.out.println("mid:  "+slow.data);
    return 0;
  }

  Node nthNodeFromEnd(int n){
    Node first = head;
    Node second = head;
    while(n>0){
      second = second.next;
      n--;
    }
    while(second != null){
      if(first == null) return null;
      first = first.next;
      second = second.next;
    }
    return first;
  }
  
  void printList(){
    Node temp = head;
    while(temp != null){
      System.out.print(temp.data+" ");
      temp = temp.next;
    }
  }
  void reverseList(){
    Node curr = head;
    Node prev = null;
    Node next;
    while(curr!=null){
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }
}
class Main {
  public static void main(String[] args) {
    List list = new List();
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);
    list.insertLast(50);
    list.insertLast(60);
    list.middleNode();
    list.printList();
    System.out.println("\nNth node from end: "+list.nthNodeFromEnd(4).data);
    list.reverseList();
    list.printList();
  }
}