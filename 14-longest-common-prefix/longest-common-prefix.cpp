class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    int childcount;

    TrieNode(char d){
        this->data=d;
        isTerminal=false;
        childcount=0;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
       
    }
};
class Solution {
public:

    void insertTrieNode(TrieNode* root, string word){  // Insert TrieNode

    //cout<<"Inserting "<<word<<endl;
    //base case:
    if(word.size()==0){

        // means word end ho gya then mark isterminal as True:
        root->isTerminal=true;
        return;
    }

    char ch= word[0];
    int index=ch-'a';
    TrieNode* child;

    // check present 
    if(root->children[index]!=NULL){
        child=root->children[index];
    }  
    else{ // present nhi hai:
        root->childcount++;
        child=new TrieNode(ch);
        root->children[index]=child;
    }

    // recursion call
    insertTrieNode(child,word.substr(1));
}

bool findWord(TrieNode* root,string word){ // Searching TrieNode

    //base case
    if(word.size()==0){
        return root->isTerminal;
    }

    char ch=word[0];
    int index=ch-'a';

    TrieNode * child;
    if(root->children[index]!=NULL){
        // nove
        child=root->children[index];
    }
    else{
        return false;
    }

    // call recursion
    return findWord(child,word.substr(1));
 
   }

   void LCA(TrieNode* root,string first,string &ans){

    if(root->isTerminal) // String NULL ho jaye 
        return ;
        
    for(int i=0;i<first.length();i++){
        char ch=first[i];

        if(root->childcount==1){
            ans.push_back(ch);
            int index=ch-'a';
            root=root->children[index];
        }
        else{
            break;
        }
        if(root->isTerminal){
            break;
        }
    }

   }


    string longestCommonPrefix(vector<string>& s) {

    //  string ans;
    //  sort(s.begin(),s.end());
    //  int n= s.size();
    //  string first=s[0],last=s[n-1];
    //  for(int i=0;i<min(first.length(),last.length());i++)
    //  {
    //      if(first[i]!=last[i])
    //      return ans;

    //      ans+=first[i];
    //  }
    //   return ans;


//*************M-2****************************//

    // string ans="";
    // bool match=true;

    // for(int i=0;i<s[0].length();i++){
    //     char ch=s[0][i];  // first string ke char ko point kr rha hai::

    //     for(int j=1;j<s.size();j++){
    //         if(ch!=s[j][i]){
    //             match=false;
    //            break;
    //         }
    //     }
    //     if(match!=true)
    //     break;
    //     else
    //     ans+=ch;
    // }
    // return ans;

    //Method- 3 Using Trie Data Structure:::::::::::************

        //Insert Each string in TrieNode
        TrieNode* root=new TrieNode('-');

        for(int i=0;i<s.size();i++){
            insertTrieNode(root,s[i]);
        }

        string ans="";
        string first=s[0];

        LCA(root,first,ans);

        return ans;



    }
};