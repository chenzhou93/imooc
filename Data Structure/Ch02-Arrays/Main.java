public class Main{
    public static void main(Stirng[] args){
        Array arr = new Array(20);
        for(int i=0; i<10; i++){
            arr.addLast(i);
        }

        System.out.println(arr);//toString()

        arr.add(1, 100);
        System.out.println(arr);

        arr.remove(2);
        System.out.println(arr);
    }
}