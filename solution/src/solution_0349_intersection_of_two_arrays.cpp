//
// Created by v4kst1z on 2021/3/20.
//

class Solution {
private:
    int paration(vector<int> &arr, int left, int right) {
        int tmp = arr[left];
        while (left < right) {
            while (left < right && arr[right] >= tmp)
                right--;
            arr[left] = arr[right];
            while (left < right && arr[left] <= tmp)
                left++;
            arr[right] = arr[left];
        }
        arr[left] = tmp;
        return left;
    }

    void quickSort(vector<int> &arr, int left, int right) {
        if(left < right) {
            int id = this->paration(arr, left, right);
            this->quickSort(arr, left, id - 1);
            this->quickSort(arr, id + 1, right);
        }
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        this->quickSort(nums1, 0, nums1.size() - 1);
        this->quickSort(nums2, 0, nums2.size() - 1);

        vector<int> result;
        int jd = 0;
        int id = 0;
        while (id < nums1.size()) {
            int tmp = nums1[id];
            if(nums1[id] == nums2[jd]) {
                result.push_back(nums2[jd]);
                while (jd < nums2.size() && tmp == nums2[jd])
                    jd++;
                if(jd == nums2.size()) break;
                while (id < nums1.size() && tmp == nums1[id])
                    id++;
                if(id == nums1.size()) break;
            } else {
                if (nums1[id] > nums2[jd]) {
                    while (jd < nums2.size() && nums1[id] > nums2[jd])
                        jd++;
                    if(jd == nums2.size()) break;
                } else {
                    while (id < nums1.size() && nums1[id] < nums2[jd])
                        id++;
                    if(id == nums1.size()) break;
                }
            }
        }
        return result;
    }
};