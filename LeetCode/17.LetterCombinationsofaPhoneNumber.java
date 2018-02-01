class Solution {
    	List<String> res;
    public List<String> letterCombinations(String digits) {
	String[] table = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		StringBuilder tmp = new StringBuilder();

		res = new LinkedList<String>();
		helper(table, 0, tmp, digits);
		return res;
    }
    
	private void helper(String[] table, int idx, StringBuilder tmp, String digits) {
		if (idx == digits.length()) {
			if (tmp.length() != 0)
				res.add(tmp.toString());

		} else {
			String candidates = table[digits.charAt(idx) - '0'];
			for (int i = 0; i < candidates.length(); i++) ·
				tmp.append(candidates.charAt(i));
				helper(table, idx + 1, tmp, digits);
				tmp.deleteCharAt(tmp.length() - 1);
			}
		}
	}   
}