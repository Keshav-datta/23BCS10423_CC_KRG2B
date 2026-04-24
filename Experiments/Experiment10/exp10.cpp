#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> count;

    void mergeSort(vector<pair<int,int>>& arr, int left, int right){
        if(left >= right) return;

        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }

    void merge(vector<pair<int,int>>& arr, int left, int mid, int right){
        vector<pair<int,int>> temp;
        int i = left;
        int j = mid + 1;

        int rightCount = 0;

        while(i <= mid && j <= right){
            if(arr[j].first < arr[i].first){
                rightCount++;
                temp.push_back(arr[j]);
                j++;
            } else {
                count[arr[i].second] += rightCount;
                temp.push_back(arr[i]);
                i++;
            }
        }

        while(i <= mid){
            count[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }

        while(j <= right){
            temp.push_back(arr[j]);
            j++;
        }

        for(int k = left; k <= right; k++){
            arr[k] = temp[k - left];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count = vector<int>(n, 0);

        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1);
        return count;
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.countSmaller(nums);

    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
