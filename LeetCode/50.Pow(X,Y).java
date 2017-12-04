class Solution {
    public double myPow(double x, int n) {
        		if (x == 0) {
			return 0;
		}
		if (n == 1) {
			return x;
		}
		if (n == 0) {
			return 1;
		}
		if (n < 0) {
			x = 1 / x;
			n = -1 * n;
		}
		double sum = (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
		if (sum >= 2147483647 || sum <= -2147483648)
			return 0;
		else
			return sum;
	
    }
}