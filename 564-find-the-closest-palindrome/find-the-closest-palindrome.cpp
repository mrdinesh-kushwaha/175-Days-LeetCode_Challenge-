class Solution {
public:
    long func(long firstHalf,bool isEven){

        long resultNum=firstHalf;
        if(isEven==false){ // n was odd:
            firstHalf/=10;
        }

        while(firstHalf > 0){
            int digit= firstHalf % 10;
            resultNum= (resultNum*10)+digit;

            firstHalf/=10;
        }
        return resultNum;
    }
    string nearestPalindromic(string n) {
        
        int L=n.length();
        int mid = L / 2;
        long firstHalfLength= (L % 2==0)? mid : mid+1;

        long firstHalf= stol(n.substr(0,firstHalfLength));

        vector<long>possibleResults;
        // no of possible cases : 123
        possibleResults.push_back(func(firstHalf,L%2==0)); //123
        possibleResults.push_back(func(firstHalf+1,L%2==0)); //131
        possibleResults.push_back(func(firstHalf-1,L%2==0));  //111
        possibleResults.push_back((long)pow(10,L-1)-1);  //99
        possibleResults.push_back((long)pow(10,L)+1); //1001

        long diff=LONG_MAX;

        long result=INT_MAX;

        long originalNum=stol(n);

        for(long & num: possibleResults){
            if(num==originalNum) continue;

            if(abs(num-originalNum)<diff){
                diff=abs(num-originalNum);
                result=num;
            }
            else if(abs(num-originalNum)==diff){
                result=min(result,num);
            }
        }
        return to_string(result);
    }
};