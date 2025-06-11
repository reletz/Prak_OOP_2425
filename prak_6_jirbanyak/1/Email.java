import java.util.regex.*;

public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws InvalidEmailException, InvalidDomainException {
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */
        if (email.equals("")) throw new InvalidEmailException("Email tidak boleh kosong");

        String[] splitted =  email.split("@");
        if (splitted.length != 2) throw new InvalidEmailException("Email harus mengandung tepat satu buah @");
        if (splitted[0].equals("")) throw new InvalidEmailException("@ tidak boleh di awal email");

        String[] splittedDomain = splitted[1].split("\\.");
        if (splittedDomain.length < 2) throw new InvalidDomainException();
        if (splittedDomain[0].equals("")) throw new InvalidDomainException();
        if (splittedDomain[splittedDomain.length - 1].equals("")) throw new InvalidDomainException();
        if (splitted[1].charAt(splitted[1].length() - 1) == '.') throw new InvalidDomainException();

        return true;
    }

    // public static void main(String[] args){
    //     String a = "woi@ha1.ha.";
    //     Email b = new Email(a);
    //     try {
    //         b.validateEmail();
    //     } catch (Exception e) {
    //         System.out.println("TITIK");
    //         return;
    //     }
    // }
}

class InvalidEmailException extends RuntimeException {
    public InvalidEmailException(String message) {
        super(message);
    }
}

class InvalidDomainException extends RuntimeException {
    public InvalidDomainException() {
        super("Email harus memiliki domain yang valid");
    }
}