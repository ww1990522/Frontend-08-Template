class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> hash1;
        set<int> set2;
        for(auto num : arr2){
            set2.insert(num);
        }
        for(vector<int>::iterator iter=arr1.begin();iter!=arr1.end();){
            if(set2.count(*iter)>0){
                if(hash1.count(*iter)==0)  hash1[*iter]=1;
                else hash1[*iter]++;
                iter = arr1.erase(iter);
            }
            else{
                iter++;
            }
        }
        vector<int> vr;
        for(auto num : arr2){
            while(hash1[num]>0){
                vr.push_back(num);
                hash1[num]--;
            } 
        }
        sort(arr1.begin(),arr1.end());
        for(auto num : arr1){
            vr.push_back(num);
        }
        return vr;
    }
};