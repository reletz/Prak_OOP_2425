import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class IntegerListProcessor {
    private static void printList(List<Integer> list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i));
            if (i < list.size() - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    // Wajib menggunakan Java Collections API untuk semua operasi pada list
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 1. Baca N. N adalah jumlah input
        int N = sc.nextInt();

        // 2. Baca N bilangan dan simpan ke List<Integer>
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++){
            list.add(sc.nextInt());
        }

        // 3. Hapus semua elemen genap
        list.removeIf(num -> num % 2 == 0);

        // 4. Jika panjang list sekarang ganjil, sort ascending; else sort descending
        if (list.size() % 2 == 1) {
            Collections.sort(list);
        } else {
            Collections.sort(list, Collections.reverseOrder());
        }
    
        // 5. Untuk setiap elemen, kalikan dengan tiga
        list.replaceAll(num -> num * 3);

        // 6. Cetak elemen menggunakan method printList
        printList(list);
        
        sc.close();
    }
}
