	public boolean isMatch(String s, String p) {

		if (p.length() == 0)
			return s.length() == 0;

		if (s.length() == 0) {
			if (p.length() > 1 && p.charAt(1) == '*')
				return isMatch(s, p.substring(2));
			else
				return false;
		} else {
			if (p.length() > 1 && p.charAt(1) == '*') {
				if (isMatch(s, p.substring(2)))
					return true;
				else if (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')
					return isMatch(s.substring(1), p);
				else
					return false;

			} else {
				if (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')
					return isMatch(s.substring(1), p.substring(1));
				else
					return false;
			}
		}
	}