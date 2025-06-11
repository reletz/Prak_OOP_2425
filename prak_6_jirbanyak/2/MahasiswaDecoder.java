import java.lang.reflect.*;

public class MahasiswaDecoder {
  private Mahasiswa ma;

  MahasiswaDecoder(Mahasiswa mahasiswa) {
    ma = mahasiswa;
  }

  public void addMatkul(String name) throws Exception {
    try {
        Method m = ma.getClass().getDeclaredMethod("addMatkul", String.class);
        m.setAccessible(true);
        m.invoke(ma, name);
    } catch (Exception e) {
        throw e;
    }
  }

  public int getNIM() throws Exception {
    try {
        Field f = ma.getClass().getDeclaredField("NIM");
        f.setAccessible(true);
        return (int) f.get(ma);
    } catch (Exception e) {
        throw e;
    }
  }

  public double getIPK() throws Exception {
    try {
        Field f = ma.getClass().getDeclaredField("IPK");
        f.setAccessible(true);
        return (double) f.get(ma);
    } catch (Exception e) {
        throw e;
    }
  }
}