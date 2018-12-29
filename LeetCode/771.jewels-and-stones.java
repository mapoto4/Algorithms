class Solution {
    public int numJewelsInStones(String J, String S) {
        int M = J.length();
		int N = S.length();
		int count = 0;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				if(M.charAt(i)==N.charAt(j))
					count++;
			}
		}
		return count;
    }
}