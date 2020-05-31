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

        //2-6 generic
        Array<Integer> array = new Array<>(20);
        // Array<Integer> array = new Array<Integer>(20);

        //2-7 Dynamic
        Array<Integer> array2 = new Array<>();
        for(int i=0; i<10; i++){
            array2.addLast(i);
        }
        array2.add(1, 100);
        array2.addFirst(101);

    }
}