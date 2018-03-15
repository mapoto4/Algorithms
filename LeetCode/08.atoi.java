	public static int solution(String s) {

		if (s == null || s.length() < 1)
			return 0;

		char flag = '+';
		s = s.trim();
		int i = 0;

		if (s.charAt(0) == '-') {
			flag = '-';
			i++;
		} else if (s.charAt(0) == '+') {
			i++;
		}

		int result = 0;

		while (s.length() > i && s.charAt(i) >= '0' && s.charAt(i) <= '9') {

			if (Integer.MAX_VALUE / 10 < result
					|| (Integer.MAX_VALUE / 10 == result && Integer.MAX_VALUE % 10 < (s.charAt(i) - '0')))
				return flag == '-' ? Integer.MIN_VALUE : Integer.MAX_VALUE;

			result = result * 10 + (s.charAt(i) - '0');
			i++;
		}

		if (flag == '-')
			result = -result;

		return result;

	}