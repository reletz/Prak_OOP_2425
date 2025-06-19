import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Mengelola semua rak dan robot di gudang.
 */
public class WarehouseManager {
    private final Map<ItemType, Shelf> shelves;

    public WarehouseManager(Map<ItemType, Shelf> shelves) {
        this.shelves = shelves;
    }

    /**
     * TODO: Implementasikan method ini.
     * Buat dan jalankan semua thread robot (producer dan consumer).
     * Kemudian, tunggu sampai semua thread tersebut selesai.
     * @param producersPerShelf Jumlah producer per rak.
     * @param consumersPerShelf Jumlah consumer per rak.
     * @param itemsPerProducer Jumlah item yang diproduksi setiap producer.
     */
    public void startOperation(int producersPerShelf, int consumersPerShelf, int itemsPerProducer) throws InterruptedException {
        List<Thread> allThreads = new ArrayList<>();
        int totalItemsPerShelf = producersPerShelf * itemsPerProducer;

        for (ItemType type : shelves.keySet()) {
            Shelf currentShelf = shelves.get(type);

            // TODO: Buat thread untuk ProducerBot dan tambahkan ke 'allThreads'.
            for (int i = 0; i < producersPerShelf; i++) {
                Thread producerThread = new Thread(new ProducerBot(currentShelf, itemsPerProducer));
                allThreads.add(producerThread);
            }   
            
            
            // TODO: Buat thread untuk ConsumerBot dan tambahkan ke 'allThreads'.
            for (int i = 0; i < consumersPerShelf; i++) {
                Thread consumerThread = new Thread(new ConsumerBot(currentShelf, totalItemsPerShelf / consumersPerShelf));
                allThreads.add(consumerThread);
            }  
        }

        System.out.println("--- Gudang Mulai Beroperasi ---");
        
        // TODO: Jalankan semua thread.
        for (Thread t: allThreads) t.start();

        // TODO: Tunggu semua thread selesai menggunakan join().
        for (Thread t: allThreads) t.join();

        System.out.println("--- Semua Operasi Gudang Selesai ---");
    }
}
