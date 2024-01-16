package homework1;

import java.util.AbstractList;
import java.util.Collection;
import java.util.List;

public class LDLinkedList<E> extends AbstractList<E> implements List<E>{

    private Node<E> head;
    private int size;
    private int deletedCount;

    private static class Node<E>{
        E data;
        Node<E> next;
        boolean deleted;

        Node(E data){
            this.data = data;
            this.deleted = false;
        }

        @Override
        public String toString() {
            return String.format("%s %s", data, deleted ? "(deleted)" : "");
        }
    }

    public LDLinkedList(){
        this.head = null;
        this.size = 0;
        this.deletedCount = 0;
    }

    @Override
    public int size() {
        return this.size;
    }

    
    private Node<E> getNode(int index){
        if(index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of bounds.");
        
        int i = 0;
        Node<E> current = this.head;
        while(current != null){
            if(!current.deleted && i == index)
                return current;

            if(!current.deleted)
                i++;
            current = current.next;
        }
        throw new IndexOutOfBoundsException("Index out of bounds.");  
    }   

    @Override
    public E get(int index){  
        if(index < 0 || index >= size)
            throw new IndexOutOfBoundsException(
                String.format("Index out of bounds. index: %s, size: %s",index, size)); //todo delete.
        return getNode(index).data;
    }


    @Override
    public boolean add(E e) {
        add(size, e);
        return true;
    }

    @Override
    public void add(int index, E element){
        if(index < 0 || index > size)
            throw new IndexOutOfBoundsException("Index out of bounds.");

        Node<E> toAdd = new Node<E>(element);

        if(index == 0){
            toAdd.next = head;
            head = toAdd;
        }
        else{
            Node<E> back = getNode(index - 1);

            if(back.next != null){
                toAdd.next = back.next;
            }
            
            back.next = toAdd;
        }

        size++;
    }

    private void removeDeletedNodes() {
        if (deletedCount < 2)
            return;

        Node<E> current = head;
        Node<E> previous = null;

        while (current != null) {

            if (current.deleted) {
                if (previous == null) 
                    head = current.next;
                else 
                    previous.next = current.next;
            } 
            else 
                previous = current;
            
            current = current.next;
        }
        deletedCount = 0;
    }
    
    @Override
    public E remove(int index) {
        if(index < 0 || index >= size)
            throw new IndexOutOfBoundsException("Index out of bounds.");
        
        Node<E> toDel = getNode(index);
        toDel.deleted = true;

        deletedCount++;

        if(deletedCount >= 2)
            removeDeletedNodes();

        size--;

        return toDel.data;
    }

    @Override
    public boolean remove(Object o) {
        for(int i = 0; i < size; ++i){
            if(get(i).equals(o)){
                remove(i);
                return true;
            }
        }
        return false;
    }

    @Override
    public boolean addAll(Collection<? extends E> c) {
        for (E element : c) {
            add(element);
        }
        return true;    
    }

    public void printAllNodes(){
        Node<E> current = head;
        String toPrint = "";

        while(current != null){
            toPrint += current.toString() + ", ";
            current = current.next;
        }
        System.out.println("[" + toPrint + "]");
    }

}