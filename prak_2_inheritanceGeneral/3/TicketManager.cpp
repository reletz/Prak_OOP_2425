#include "TicketManager.hpp"

/*
    Ticket* tickets[VENUE_CAPACITY]; // Array untuk menyimpan tiket yang terjual
    string eventName; // Nama acara
    int vipCapacity; // Kapasitas maksimum tiket VIP
    int regularCapacity; // Kapasitas maksimum tiket Regular
    int ticketCount; // Jumlah tiket yang telah terjual
    int currentVIPTickets; // Jumlah tiket VIP yang telah dibeli
    int currentRegularTickets; // Jumlah tiket Regular yang telah dibeli
*/

TicketManager::TicketManager(string eventName): regularCapacity(10), vipCapacity(5), 
ticketCount(0), currentRegularTickets(0), currentVIPTickets(0){
    this->eventName = eventName;
}
    /* Constructor default:
     * - Membuat event dengan nama yang diberikan.
     * - Kapasitas default: 5 tiket VIP, 10 tiket Regular.
     * - Tidak ada tiket yang terjual pada awalnya.
     */

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity): 
ticketCount(0), currentRegularTickets(0), currentVIPTickets(0){
    int total = vipCapacity+regularCapacity;
    if (total > VENUE_CAPACITY) {
        cout << "The total capacity you construct is "<< total << ", meanwhile the venue capacity is 15" << '\n';
    }
    this->eventName = eventName;
    this->vipCapacity = vipCapacity;
    this->regularCapacity = regularCapacity;
}

TicketManager::~TicketManager(){
    for (int i = 0; i < (ticketCount); i++){
        delete tickets[i];
    }
}

string TicketManager::getEventName() const{
    return eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP){
    if (ticketCount >= VENUE_CAPACITY) {
        cout << "Error: All tickets are sold out!" << '\n';
        return;
    }

    if (isVIP) {
        if (vipCapacity == currentVIPTickets) {
        cout << "Error: No VIP tickets left!" << endl;
        return;
        }
        currentVIPTickets++;
        string tix = "V" + to_string(currentVIPTickets);
        tickets[ticketCount] = new VIPTicket(tix,ownerName);
        cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << tix << endl;
    }
    else {
        if (regularCapacity == currentRegularTickets) {
        cout << "Error: No Regular tickets left!" << endl;
        return;
         }
        currentRegularTickets++;
        string tix = "R" + to_string(currentRegularTickets);
        tickets[ticketCount] = new RegularTicket(tix,ownerName);
        cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << tix << endl;
    }
    ticketCount++;
}

    /* Membeli tiket untuk pengguna.
    * Input:
    * - ownerName: Nama pemilik tiket.
    * - isVIP: Jika true, membeli tiket VIP; jika false, membeli tiket Regular.
    *
    * Proses:
    * - Jika venue penuh, cetak "Error: All tickets are sold out!".
    * - Jika kapasitas VIP penuh, cetak "Error: No VIP tickets left!".
    * - Jika kapasitas Regular penuh, cetak "Error: No Regular tickets left!".
    *
    * - Jika pembelian berhasil, sistem akan membuat **ID tiket unik** berdasarkan jenis tiket:
    *   - Jika tiket VIP, ID akan berupa "V" diikuti nomor urut tiket VIP.
    *   - Jika tiket Regular, ID akan berupa "R" diikuti nomor urut tiket Regular.
    *
    * - Contoh penggunaan `to_string()` dalam pembuatan ID:
    *   int angka = 5;
    *   string hasil = "V" + to_string(angka); // hasil: "V5"
    *
    * - Jika pembelian berhasil, cetak:
    *   "Success: <ownerName> bought a <VIP/Regular> ticket! Ticket ID: <ticketID>"
    */

void TicketManager::checkTicket(const string &ticketID) const{
    for (int i = 0; i < (ticketCount); i++){
        if (tickets[i]->getTicketID() == ticketID) {
            tickets[i]->printTicket();
            return;
        } 
    } cout <<"Ticket ID is invalid!"<< "\n";
}
    /* Mengecek apakah tiket dengan ID tertentu valid.
     * Input:
     * - ticketID: ID tiket yang ingin diperiksa.
     *
     * Output:
     * - Jika ditemukan, cetak detail tiket menggunakan metode printTicket().
     * - Jika tidak ditemukan, cetak "Ticket ID is invalid!".
     */

void TicketManager::listAudience() const{
    if (ticketCount == 0) {
        cout << "No audience yet!" << "\n";
        return;
    }

    for (int i = 0; i < (ticketCount); i++){
        cout << i + 1 << ". ";
        tickets[i]->printTicket();
    }
}
    /* Menampilkan daftar semua pemegang tiket.
     * Output:
     * - Jika belum ada yang membeli tiket, cetak "No audience yet!".
     * - Jika ada, cetak dalam format:
     *   "<nomor>. <printTicket()>"
     *
     * - Nomor urut dalam output harus dimulai dari 1.
     */  


int TicketManager::calculateRevenue() const{
    return 500*currentVIPTickets + 275*currentRegularTickets;
}
/* Menghitung total pendapatan dari tiket yang terjual.
     * - Tiket VIP seharga 500.
     * - Tiket Regular seharga 275.
     * 
     * Output: Total pendapatan dalam bentuk integer.
     */
