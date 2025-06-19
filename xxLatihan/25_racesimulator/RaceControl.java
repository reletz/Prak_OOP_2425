import java.util.ArrayList;
import java.util.List;

/**
 * Mengelola jalannya balapan, memulai, menghentikan, dan melaporkan hasil.
 */
public class RaceControl {
    private final List<Car> cars;
    private final List<Thread> carThreads = new ArrayList<>();

    public RaceControl(List<Car> cars) {
        this.cars = cars;
        for (Car car : cars) {
            carThreads.add(new Thread(car));
        }
    }

    /**
     * TODO: Implementasikan method ini.
     * 1. Mulai semua thread mobil.
     * 2. Tunggu selama durasi balapan (raceDurationMs).
     * 3. Setelah waktu habis, interupsi semua thread mobil.
     * 4. Tunggu (join) sampai semua thread mobil benar-benar berhenti.
     * 5. Cetak hasil akhir balapan.
     * @param raceDurationMs Durasi balapan dalam milidetik.
     */
    public void startRace(long raceDurationMs) {
        System.out.println("--- Balapan Dimulai ("+ raceDurationMs +"ms) ---");
        // TODO: 1. Mulai semua thread di 'carThreads'.
        for (Thread car: carThreads) car.start();

        // TODO: 2. Tunggu selama durasi balapan.
        try {
            Thread.sleep(raceDurationMs);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        System.out.println("\n--- Waktu Habis! Mengibarkan Bendera Finis! ---");
        // TODO: 3. Interupsi semua thread mobil.
        for (Thread car: carThreads) car.interrupt();
        

        // TODO: 4. Tunggu semua thread selesai menggunakan join().
        System.out.println("Menunggu semua mobil berhenti...");
        try {
            for (Thread car: carThreads) car.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        
        // TODO: 5. Cetak hasil akhir.
        printFinalResults();
    }

    private void printFinalResults() {
        System.out.println("\n--- HASIL AKHIR BALAPAN ---");
        cars.sort((c1, c2) -> Double.compare(c2.getDistanceCovered(), c1.getDistanceCovered()));
        for (int i = 0; i < cars.size(); i++) {
            Car car = cars.get(i);
            System.out.printf("Posisi %d: %s - Jarak: %.2f meter\n", i + 1, car.getName(), car.getDistanceCovered());
        }
        System.out.println("---------------------------");
    }
}
