class A_StringToInteger {
    public int myAtoi(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int i = 0, n = s.length();

        // Skip leading whitespaces
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }

        // Handle sign
        boolean negative = false;
        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            negative = (s.charAt(i) == '-');
            i++;
        }

        int result = 0;
        while (i < n && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            int digit = s.charAt(i) - '0';

            // Check overflow and underflow conditions
            if (result > (Integer.MAX_VALUE - digit) / 10) {
                return negative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }

            result = result * 10 + digit;
            i++;
        }

        return negative ? -result : result;
    }

    public static void main(String[] args) {
        A_StringToInteger solution = new A_StringToInteger();

        // Test cases
        String[] testCases = {
            "42",
            "   -42",
            "4193 with words",
            "words and 987",
            "-91283472332",
            "91283472332"
        };

        for (String testCase : testCases) {
            int result = solution.myAtoi(testCase);
            System.out.println("Input: \"" + testCase + "\" -> Output: " + result);
        }
    }
}
