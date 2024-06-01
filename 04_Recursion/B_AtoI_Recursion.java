class B_AtoI_Recursion {
    
        public static double myPow(double x, int n) {
            if (n == 0) {
                return 1;
            }
            
            boolean neg = n < 0;
            long absN = Math.abs((long)n);  // Use long to handle the case where n is Integer.MIN_VALUE
            
            double result = myPowp(x, absN);
            
            return neg ? 1 / result : result;
            
        }
        public static double myPowp(double x, long n) {
            if(n==1){
                return (double)x;
            }
            if(n==2){
                return (double)x*x;
            }    
            if(n==0){
                return (double)1;
            }
            
            double half = myPowp(x, n / 2);
    
            if (n % 2 == 0) {
                return half * half;
            } else {
                return half * half * x;
            }
    
        }
    

    public static void main(String[] args) {
        // double x=3.000;
        // int n=-3;
        double x =0.00001;
        int n =2147483647;
        double ans=myPow(x,n);
        System.out.println(ans);
    }
}
