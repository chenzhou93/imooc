public class ArrayStack<E> implements Stack<E>{
    Array<E> array;//DynamicArray.java
    
    public ArrayStack(int capacity){
        array = new Array<>(capacity);
    }

    public ArrayStack(){
        array = new Array<>();
    }

    @Override
    public int getSize(){
        return array.getSize();
    }

    @Override
    public boolean isEmpty(){
        return array.isEmpty();
    }

    public int getCapacity(){//和 stack 无关
        return array.getCapacity();
    }

    @Override
    public void push(E e){
        array.addLast(e);
    }

    @Override
    public E pop(){
        return array.removeLast();
    }

    @Override
    public E peek(){
        return array.getLast();
    }

    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();
        res.append("Stack: ");
        res.append('[');
        for(int i=0; i<array.getSize(); i++){
            res.append(array.get(i));
            if(i != array.size() -1){
                res.append(", ");
            }
        }
        res.append('] top');
        return res.toString;
    }

}