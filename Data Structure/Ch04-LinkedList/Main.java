public class Main{
    public static void main(String[] args){
        LinkedList<Integer> linkedlist = new LinkedList<>();

        for(int i=0; i<5; i++){
            linkedlist.addFirst(i);
            System.out.println(linkedlist);
        }

        linkedlist.addFirst(2, 666);
        System.out.println(linkedlist);
    }
}