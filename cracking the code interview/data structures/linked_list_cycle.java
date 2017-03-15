boolean hasCycle(Node head) {

    ArrayList<Node> seenNodes = new ArrayList<Node>();
    if (head == null)
    {
        return false;
    }
    else
    {
            while(head!=null)
            {
             if (seenNodes.contains(head)) 
              {
                return true;    
              }
            else 
             {
                seenNodes.add(head);    
                head=head.next;
             }
           }
        return false;
    }
}