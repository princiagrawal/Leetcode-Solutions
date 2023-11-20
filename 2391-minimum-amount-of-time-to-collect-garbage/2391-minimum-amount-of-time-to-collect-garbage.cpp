class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int t=travel.size();
        int p=0,m=0,g=0,sum=0;
        for(int i=0;i<n;i++){
            for(char ch:garbage[i]){
                if(ch=='P'){
                    p=i;
                }
                else if(ch=='M'){
                    m=i;
                }
                else{
                    g=i;
                }
                sum++;      // add 1 min for every pick-up
            }
        }
        for(int i=1;i<t;i++){
            travel[i]=travel[i]+travel[i-1];
        }
        if(p!=0){
            sum+=travel[p-1];
        }
        if(m!=0){
            sum+=travel[m-1];
        }
        if(g!=0){
            sum+=travel[g-1];
        }
        return sum;
    }
/*Firstly sum up the amount of gabages in total. Second find up the last position for each type.
Calculate the prefix sum array of the travel distance.Sum up the distance for each type of garbage.*/
};