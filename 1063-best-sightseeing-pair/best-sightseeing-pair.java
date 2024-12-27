class Solution {
    public int maxScoreSightseeingPair(int[] v) {
        int s=0,x=v[0];
        for(int j=1;j<v.length;j++){
            s=Math.max(s,x+v[j]-j);
            x=Math.max(x,v[j]+j);
        }
        return s;
        
    }
}