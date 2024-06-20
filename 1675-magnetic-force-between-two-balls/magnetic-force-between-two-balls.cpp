class Solution {
public:

    bool possibleToPlace(vector<int>&position,int force,int m){
        int prev = position[0];
        int countBalls= 1; // bcz hamne ek ball rkh diya hai first position pr
        for(int i=1;i<position.size();i++){
            int curr= position[i];

            if(curr-prev >=force){
                countBalls++;
                prev=curr;// change new prev
            }
            if(countBalls==m) break;
        }
        return countBalls==m;
    }
    int maxDistance(vector<int>& position, int m) {
        
        // using binary search apply in answer : bcz ans is always in sorted order like : 1, 2,3,...
        sort(begin(position),end(position));
        int n= position.size();
        int minForce=1;
        int maxForce= position[n-1]-position[0]; 
        int ans=0;
        while(minForce <= maxForce){
            int mid = (minForce + maxForce)/2;

            if(possibleToPlace(position,mid,m)){
                ans=mid;
                minForce=mid+1;
            }
            else{
                maxForce=mid-1;
            }
        }
        return ans;
    }
};