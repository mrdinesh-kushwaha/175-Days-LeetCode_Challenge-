class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>>pq;

        if(a>0){
            pq.push(make_pair(a,'a'));
        }
        if(b>0){
            pq.push(make_pair(b,'b'));
        }
        if(c>0){
            pq.push(make_pair(c,'c'));
        }
        string ans="";
        while(pq.size()>1){
            auto temp1=pq.top();
            pq.pop();
            auto temp2=pq.top();
            pq.pop();

            if(temp1.first>=2){
                ans+=temp1.second;
                ans+=temp1.second;
                temp1.first-=2;
            }
            else{
                ans+=temp1.second;
                temp1.first--;
            }

            if(temp2.first>=2 && temp2.first >= temp1.first){
                ans+=temp2.second;
                ans+=temp2.second;
                temp2.first-=2;
            }
            else{
                ans+=temp2.second;
                temp2.first--;
            }

            if(temp1.first>0){
                pq.push(temp1);
            }
            if(temp2.first>0){
                pq.push(temp2);
            }
            
        }

        if(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            if(temp.first>=2){
                ans+=temp.second;
                ans+=temp.second;
                temp.first-=2;
            }
            else{
                ans+=temp.second;
                temp.first--;
            }
        }
        return ans;
    }
};