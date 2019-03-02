int multiply(int x, int y) {
	if (y == 0)
		return 0

	int z = multiply(x, [y/2]);
	if (y%2==0)
		return 2*z
	else
		return x + 2*z
}

/*
- How large the result could be?
- How nuch time does it take?
T(N) = O(1) + T(N-1) + O(N) + O(2N)
Total = O(N^2) >> can better!
 */