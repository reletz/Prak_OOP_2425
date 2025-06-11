public class Redis<K, V> {
    private K key;
    private V val;
    private long ttl;

    public Redis(K k, V v, long ttl) {
        if(ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.key = k;
        this.val = v;
        this.ttl = ttl;
    }

    public K getKey() {
        return key;
    }

    public void setKey(K k) {
        this.key = k;
    }

    public V getVal(long elapsedSeconds) {
        if(ttl - elapsedSeconds <= 0) {
            throw new TtlExpiredException(getKey() + " expired");
        }
        return val;
    }

    public void setVal(V v) {
        this.val = v;
    }

    public long getRemainingTtl(long elapsedSeconds) {
        long r = this.ttl - elapsedSeconds;
        return r < 0 ? 0 : r;
    }

    public void refresh(long newTtl) {
        if(newTtl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.ttl = newTtl;
    }

    public boolean isEqual(Redis<?, ?> c) {
        return this.getKey().equals(c.getKey()) && this.getVal(0).equals(c.getVal(0));
    }

    public int nearEQ(Redis<?, ?> c) {
        if (isEqual(c)) return 3;
        if(!this.getKey().equals(c.getKey()) && this.getVal(0).equals(c.getVal(0))) return 2;
        if(this.getKey().equals(c.getKey()) && !this.getVal(0).equals(c.getVal(0))) return 1;
        return 0;
    }

      public static void main(String[] args) {

        /* ---------- 1. Konstruktor & akses dasar ---------- */
        Redis<String, Integer> r1 = new Redis<>("token#A", 111, 5);
        System.out.println("r1 key   : " + r1.getKey());
        System.out.println("r1 value : " + r1.getVal(0));          // elapsed = 0
        System.out.println("r1 TTL   : " + r1.getRemainingTtl(2)); // elapsed = 2  -> 5 - 2 = 3
        System.out.println();

        /* ---------- 2. Exception: TTL habis ---------- */
        try {
            System.out.println("Access r1 after expired:");
            r1.getVal(6); // elapsed = 6 > 5  -> harus throw
        } catch (TtlExpiredException e) {
            System.out.println("[Expired] " + e.getMessage());
        }
        System.out.println();

        /* ---------- 3. refresh & akses lagi ---------- */
        r1.refresh(4); // ttl baru 4 s, anggap elapsed di-reset
        System.out.println("r1 TTL after refresh (elapsed 0): " + r1.getRemainingTtl(0));
        System.out.println("r1 value after refresh (elapsed 3): " + r1.getVal(3));
        System.out.println();

        /* ---------- 4. setKey & setVal ---------- */
        r1.setKey("token#A-updated");
        r1.setVal(222);
        System.out.println("r1 key setelah setKey : " + r1.getKey());
        System.out.println("r1 val (elapsed 1)     : " + r1.getVal(1));
        System.out.println();

        /* ---------- 5. Membuat r2, uji isEqual & nearEQ ---------- */
        Redis<String, Integer> r2 = new Redis<>("token#B", 222, 10);

        System.out.println("isEqual(r1,r2) : " + r1.isEqual(r2));      // false
        System.out.println("nearEQ(r1,r2)  : " + r1.nearEQ(r2));       // 2 (value sama)
        System.out.println();

        /* ---------- 6. Exception: TTL negatif saat konstruktor ---------- */
        try {
            Redis<String, String> bad = new Redis<>("x", "oops", 0);
        } catch (InvalidTtlException e) {
            System.out.println("[Invalid TTL] " + e.getMessage());
        }
    }
}