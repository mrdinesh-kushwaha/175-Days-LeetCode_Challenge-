class node{
    public:
    int data;
    int row;
    int col;

    node(int data,int r,int c){
        this->data=data;
        this->row=r;
        this->col=c;
        }    
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data >b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        //create Min Heap:
        priority_queue<node* ,vector<node*>,compare>minHeap;

        int mini=INT_MAX;
        int maxi=INT_MIN;

        int k=nums.size();

        for(int i=0;i<k;i++){ // insert k element all k rows
            int ele=nums[i][0];
            mini=min(mini,ele);
            maxi=max(maxi,ele);
            minHeap.push(new node(ele,i,0));
        }

        int ansMax=maxi;
        int ansMin=mini;

        while(!minHeap.empty()){
            node* temp=minHeap.top();

            int topEle=temp->data;
            int topRow=temp->row;
            int topCol=temp->col;
            minHeap.pop();

            mini=topEle; //update mini element:

            // check range
            int currrange=maxi-mini;
            int ansrange=ansMax-ansMin;

            if(currrange<ansrange){
                ansMax=maxi;
                ansMin=mini;
            }

            // now next insert next ele from min list:

            if(topCol+1 < nums[topRow].size()){
                maxi= max(maxi,nums[topRow][topCol+1]); // update max element
                node* newNode=new node(nums[topRow][topCol+1],topRow,topCol+1);

                minHeap.push(newNode);

            }
            else{
                break; // list empty::
            }
        }
        vector<int>ans;
        ans.push_back(ansMin);
        ans.push_back(ansMax);
        return ans;     
    }
};