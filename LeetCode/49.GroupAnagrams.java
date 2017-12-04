class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        	List<List<String>> result = new ArrayList<List<String>>();

		int length = strs.length;

		if (length < 1)
			return result;

		Map<String, List<String>> map = new HashMap<String, List<String>>();
		String temp = "";
		for (int i = 0; i < length; i++) {
			temp = strs[i];
			char[] arryOfString = temp.toCharArray();
			Arrays.sort(arryOfString);
			temp = new String(arryOfString);

			if (map.containsKey(temp)) {
				map.get(temp).add(strs[i]);

			} else {
				List<String> item = new ArrayList<String>();
				item.add(strs[i]);
				map.put(temp, item);
			}

		}
		for (List<String> value : map.values()) {
			result.add(value);
		}
		return result;
    }
}