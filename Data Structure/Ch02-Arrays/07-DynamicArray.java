/*
    Generic class
*/
public class Array<E>{
    private E[] data;
    private int size;

    public Array(int capacity){
        data = (E[])new Object[capacity];
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

    //Add element to last
    public void addLast(E e){
        if(size == data.length){
            throw new IllegalArgumentException("AddLast failed, array is full");
        }
        data[size] = e;
        size++;

        //add(size, e);
    }

    //Add element to first
    public void addFirst(E e){
        add(0, e);
    }

    //Add element to specific position (insert)
    public void add(int index, E e){

        if(index < 0 || index > size){
            throw new IllegalArgumentException("Add failed, index");
        }

        if(size == data.length){
            resize(2 * data.length);
        }

        for(int i=size-1; i>=index; i--){
            data[i+1] = data[i];
        }
        data[index] = e;
        size++;
    }

    public E get(int index){
        if(index < 0 || index >= size){
            throw new IllegalArgumentException("Get failed, index");
        }
        return data[index];
    }

    public void set(int index, E e){
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

    public boolean contains(E e){
        for(int i=0; i<size; i++){
            if(data[i].equals(e)){
                return true;
            }
        }
        return false;
    }

    public int find(E e){
        for(int i=0; i<size; i++){
            if(data[i].equals(e)){
                return i;
            }
        }
        return -1;
    }

    public E remove(int index){
        if(index < 0 || index >= size){
            throw new IllegalArgumentException("Remove failed, index");
        }
        E ret = data[index];
        for(int i=index+1; i<size; i++){
            data[i-1] = data[i];
        }
        size--;
        //loitering objects != memory leak
        data[size] = null;//data size的对象引用释放，非必须
        //还在程序中，垃圾回收机制还没处理

        //2-7 缩小容量
        // if(size == data.length/2){
        //     resize(data.length/2);
        // }

        //2-9 lazy
        if(size == data.length/4 && data.length/2 != 0){
            resize(data.length/2);
        }

        return ret;
    }

    public E removeFirst(){
        return remove(0);
    }

    public E removeLast(){
        return remove(size-1);
    }

    //delete 1 e only
    public void removeElement(E e){
        int index = find(e);
        if(index != -1){
            remove(index);
        }
    }

    private void resize(int newCapacity){
        E[] newData = (E[])Object[newCapacity];
        for(int i=0; i<size; i++){
            newData[i] = data[i];
        }
        data = newData;
    }

}