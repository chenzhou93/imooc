/*
    Create own array
    class Array
    members: data, capacity, size
*/

public class Array{
    private int[] data;
    private int size;

    /*
        02 - Create own array
    */

    public Array(int capacity){
        data = new int[capacity];
        size = 0;
    }

    public Array(){
        this(10);
    }

    public int getSize(){
        return size;
    }

    public int getCapacity(){
        return data.length;
    }

    public boolean isEmpty(){
        return size==0;
    }

    /*
        03 - Add new element to array
    */

    //Add element to last
    public void addLast(int e){
        if(size == data.length){
            throw new IllegalArgumentException("AddLast failed, array is full");
        }
        data[size] = e;
        size++;

        //add(size, e);
    }

    //Add element to first
    public void addLast(int e){
        add(0, e);
    }

    //Add element to specific position (insert)
    public void add(int index, int e){
        if(size == data.length){
            throw new IllegalArgumentException("Add failed, array is full");
        }
        if(index < 0 || index > size){
            throw new IllegalArgumentException("Add failed, index");
        }
        for(int i=size-1; i>=index; i--){
            data[i+1] = data[i];
        }
        data[index] = e;
        size++;
    }

    /*
        04 - Query and Update
    */

    public int get(int index){
        if(index < 0 || index >= size){
            throw new IllegalArgumentException("Get failed, index");
        }
        return data[index];
    }

    public void set(int index, int e){
        if(index < 0 || index >= size){
            throw new IllegalArgumentException("Get failed, index");
        }
        data[index] = e;
    }

    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();
        res.append(String.format("Array: Size = %d, capacity = %d\n", size, data.length));
        res.append('[');
        for(int i=0; i<size; i++){
            res.append(data[i]);
            if(i != size-1){
                res.append(", ");
            }
        }
        res.append(']');
    }

    /*
        05 - Contain, Find, Remove
    */
    public boolean contains(int e){
        for(int i=0; i<size; i++){
            if(data[i] == e){
                return true;
            }
        }
        return false;
    }

    public int find(int e){
        for(int i=0; i<size; i++){
            if(data[i] == e){
                return i;
            }
        }
        return -1;
    }

    public int remove(int index){
        if(index < 0 || index >= size){
            throw new IllegalArgumentException("Remove failed, index");
        }
        int ret = data[index];
        for(int i=index+1; i<size; i++){
            data[i-1] = data[i];
        }
        size--;
        return ret;
    }

    public int removeFirst(){
        return remove(0);
    }

    public int removeLast(){
        return remove(size-1);
    }

    //delete 1 e only
    public void removeElement(int e){
        int index = find(e);
        if(index != -1){
            remove(index);
        }
    }



}