import java.util.List;
import java.util.Stack;
import java.util.ArrayList;

/**
 * Sebuah prosesor generik yang mengeksekusi perintah dan mengelola riwayat
 * untuk fungsionalitas undo.
 */
public class CommandProcessor<T extends Command> {

    private final Stack<T> commandHistory;

    public CommandProcessor() {
        commandHistory = new Stack<>();
    }

    /**
     * Memproses command dan menyimpannya ke dalam history stack.
     * 
     * @param command Perintah yang akan diproses.
     * @throws InvalidCommandException jika command adalah null dengan pesan
     *                                 "Command
     *                                 tidak boleh null"
     */
    public void processCommand(T command) throws InvalidCommandException {
        if (command == null) {
            throw new InvalidCommandException("Command tidak boleh null");
        }
        command.execute();
        commandHistory.push(command);
    }

    /**
     * Membatalkan perintah terakhir dengan mengeluarkannya (pop) dari history
     * stack. Mencetak pesan "Undo: <perintah terakhir>"
     * Contoh:
     * 
     * Undo: DrawShapeCommand{shape='circle'}
     * 
     * @throws InvalidCommandException jika history stack kosong dengan pesan
     *                                 "Riwayat command kosong"
     */
    public void undoLastCommand() throws InvalidCommandException {
        if (commandHistory.empty()) {
            throw new InvalidCommandException("Riwayat command kosong");
        }
        T c = commandHistory.pop();
        System.out.println("Undo: " + c.toString());
    }

    /**
     * Memproses sekumpulan perintah dari sebuah list.
     * Mencetak pesan "Memproses Kumpulan Perintah" sebelum memproses perintah dan
     * "Pemrosesan Batch Selesai" setelah selesai.
     * 
     * @param commands Sebuah list perintah yang akan diproses.
     * @throws InvalidCommandException Pada pengecekan awal, jika list commands
     *                                 kosong dengan pesan "List
     *                                 command kosong"
     */
    public void processAll(List<? extends T> commands) throws InvalidCommandException {
        System.out.println("Memproses Kumpulan Perintah");
        if (commands.isEmpty()){
            throw new InvalidCommandException("List command kosong");
        } 
        for (T c: commands){
            c.execute();
            commandHistory.push(c);
        } System.out.println("Pemrosesan Batch Selesai");
    }

    /**
     * Mencari semua perintah dalam history stack yang merupakan instance dari
     * tipe yang diberikan.
     * 
     * @param type Kelas yang mewakili tipe perintah yang dicari.
     * @return Sebuah List berisi perintah yang cocok dengan tipe yang diberikan.
     */
    public List<T> findCommandsByType(Class<? extends T> type) {
        List<T> a = new ArrayList<>();
        
        for (T c: commandHistory){
            if (c.getClass().equals(type)){
                a.add(c);
            }
        } return a;
    }

    /**
     * Mendapatkan ukuran history stack.
     * 
     * @return Jumlah perintah dalam history stack.
     */
    public int getHistorySize() {
        return commandHistory.size();
    }
}