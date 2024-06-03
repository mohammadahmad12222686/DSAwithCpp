class C_Count_Good_Numbers {
    private static final int MOD = 1000000007;

    // Recursive function to perform modular exponentiation
    private long modExp(long base, long exp, long mod) {
        if (exp == 0) return 1;
        long half = modExp(base, exp / 2, mod);
        if (exp % 2 == 0) {
            return (half * half) % mod;
        } else {
            return ((half * half) % mod * base) % mod;
        }
    }

    public int countGoodNumbers(long n) {
        long evenPos = n / 2;
        long oddPos = n - evenPos;

        long powerOf5 = modExp(5, oddPos, MOD);
        long powerOf4 = modExp(4, evenPos, MOD);

        long result = (powerOf5 * powerOf4) % MOD;
        return (int) result;
    }

    public static void main(String[] args) {
        C_Count_Good_Numbers sol = new C_Count_Good_Numbers();
        System.out.println(sol.countGoodNumbers(50)); // Example usage
    }
}
