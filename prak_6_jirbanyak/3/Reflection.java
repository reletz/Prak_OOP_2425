import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.lang.reflect.*;
import java.lang.StringBuilder;

public class Reflection{
  //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
  //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
  //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

  public ArrayList<String> ghostMethods(){
    Ghost g = new Ghost();
    Method[] m = g.getClass().getDeclaredMethods();

    ArrayList<String> list = new ArrayList<>();
    for(Method method : m) {
      list.add(method.getName());
    }
    return list;
  }   

  public Integer sumGhost() throws Exception{
    try {
      Ghost g = new Ghost();
      Method[] m = g.getClass().getDeclaredMethods();
      Integer sum = 0;

      for (Method method : m){
        if (method.getReturnType() == Integer.class || method.getReturnType() == int.class) {
          method.setAccessible(true);
          Object result = method.invoke(g);
          if (result != null) sum += (Integer) result;
        }
      }
      return sum;
    } catch (Exception e) {
      throw e;
    }
  }

  public String letterGhost() throws Exception{
    try {
      StringBuilder sb = new StringBuilder("");
      Ghost g = new Ghost();
      Method[] m = g.getClass().getDeclaredMethods();

      for (Method method : m){
        if (method.getReturnType() == String.class){
          method.setAccessible(true);
          Object result = method.invoke(g);
          if (result != null) sb.append(result);
        }
      }
      return sb.toString();
    } catch (Exception e) {
      throw e;
    }
  }

  public String findSecretId(List<Secret> sl, String email) throws Exception{
    try {
      for (Secret sc : sl){
        if (sc.isThis(email)) {
          Field f = sc.getClass().getDeclaredField("uniqueId");
          f.setAccessible(true);
          return (String) f.get(sc);
        }
      } 
      return "NaN";
    } catch (Exception e) {
      throw e;
    }
  }
}