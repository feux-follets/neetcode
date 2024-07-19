class Solution {
  public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);

		const int m = nums1.size();
		const int n = nums2.size();
		const int total = m + n;
		int low = 0, high = m;

		while (low <= high) {
			int i = low + (high - low) / 2;
			int j = (total + 1) / 2 - i;

			int a_max = i > 0 ? nums1[i - 1] : INT_MIN;
			int a_min = i < m ? nums1[i] : INT_MAX;

			int b_max = j > 0 ? nums2[j - 1] : INT_MIN;
			int b_min = j < n ? nums2[j] : INT_MAX;

			if (a_max <= b_min && b_max <= a_min) {
				if (total % 2)
					return max(a_max, b_max);
				return (max(a_max, b_max) + min(a_min, b_min)) / 2.0;
			} else if (a_max > b_min) {
				high = i - 1;
			} else {
				low = i + 1;
			}
		}
		return 0.0;
	}
};
