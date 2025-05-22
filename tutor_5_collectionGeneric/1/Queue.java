// Queue.java

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head;
    private int tail;
    private int size;

    // Ctor queue (kosong) dengan alokasi kapasitas maksimum
    public Queue() {
        this.data = (T[]) new Object[MAX_CAPACITY]; 
        head = 0;
        tail = 0;
        size = 0;
     }

    // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] data) {
        this();
        for (T item : data) {
            push(item);
        }
     }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() {
        if (size == 0) {
            return null;
        }
        return data[head];
    }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() { 
        if (size == 0) {
            return null;
        }
        T item = data[head];
        data[head] = null;
        head = (head + 1) % MAX_CAPACITY;
        size--;
        return item;
    }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) { 
        data[tail] = o;
        tail = (tail + 1) % MAX_CAPACITY;
        size++;
    }

    // Menghitung panjang queue.
    public int size() {
        return size;
    }

    // Getter attribute
    public T[] getData() { return data; }
    public int getHead() { return head; }
    public int getTail() { return tail; }
}