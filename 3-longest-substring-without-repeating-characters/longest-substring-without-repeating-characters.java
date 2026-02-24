class Solution {
    public int lengthOfLongestSubstring(String s) {
        int size = s.length();
        if(size==0) return 0;

        int left=0;
        int maxiLength = Integer.MIN_VALUE;
        HashSet<Character>st = new HashSet<>();

        for(int right=0;right<size;right++){
            while(st.contains(s.charAt(right))){
                st.remove(s.charAt(left));
                left++;
            }
            st.add(s.charAt(right));
            maxiLength = Math.max(maxiLength,right-left+1);
        }
        return maxiLength;
    }
}