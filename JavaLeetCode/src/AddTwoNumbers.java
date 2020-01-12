class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}

public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode mergeHeadNode=new ListNode(0);
        ListNode mergeMoveNode=mergeHeadNode;
        ListNode TempNode;
        boolean isFirst=true;
        boolean isAddOne=false;
        while (l1!=null||l2!=null)
        {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;
            int addResult=x+y;
            if (isAddOne)
            {
                addResult++;
            }
            if (addResult < 10)
            {
                isAddOne = false;
                TempNode = new ListNode(addResult);
                mergeMoveNode.next = TempNode;
                mergeMoveNode = TempNode;
            }
            else
            {
                isAddOne = true;
                TempNode = new ListNode(addResult - 10);
                mergeMoveNode.next = TempNode;
                mergeMoveNode = TempNode;
            }
            if (isFirst)
            {
                mergeHeadNode = mergeMoveNode;
                isFirst = false;
            }
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        if (isAddOne)
        {
            TempNode = new ListNode(1);
            mergeMoveNode.next = TempNode;
            mergeMoveNode = TempNode;
        }

        return mergeHeadNode;
    }
}
