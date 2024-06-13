// class Solution {
// public:
//     int minMovesToSeat(vector<int>& seats, vector<int>& students) {

//         sort(begin(seats),end(seats));
//         sort(begin(students),end(students));

//         int ans=0;
//         int n= seats.size();
//         for(int i=0;i<n;i++){
//             ans+=abs(seats[i]-students[i]);   // T.C= O(n*logn)
//         }                                     // S.C = O(1)
//         return ans;   
//     }
// };

// Method-2:

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

        //using taking two extra space::
        vector<int>freq_seats(101,0); // this is the freq array: store the freq of seats
        vector<int>freq_students(101,0); // this is the freq array: store the freq of students

        for(int &i :seats) freq_seats[i]++;
        for(int &i: students) freq_students[i]++;

        int i=0,j=0,ans=0;
        int n=seats.size();
        while(n>0){
            if(freq_seats[i]==0) i++;
            if(freq_students[j]==0) j++;

            if(freq_seats[i]!=0 && freq_students[j]!=0){
                ans+=abs(j-i);
                freq_seats[i]--; // decrease freq by 1:
                freq_students[j]--; // decrease freq by 1:
                n--; 
            }
        }                        // T.C= O(n)
                                 // S.c= O(101)
        return ans;
    }
};