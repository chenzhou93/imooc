public class SegmentTree<E>{

    private E[] data;
    private E[] tree;

    public SegmentTree(E[] arr){
        data = (E[]) new Object[arr.length];
        for(int i=0; i<arr.length; i++){
            data[i] = arr[i];
        }

        tree = (E[])new Object[arr.length * 4];
    }

    public int getSize(){
        return data.length;
    }

    public E get(int index){
        if(index < 0 || index >= data.length){
            throw;
        }
        return data[index];
    }

    private int leftChild(int index){
        return 2*index + 1;
    }

    private int rightChild(int index){
        return 2*index + 2;
    }
}