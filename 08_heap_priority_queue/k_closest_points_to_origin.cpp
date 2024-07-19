class Solution {
  public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		int left = 0;
		int right = points.size() - 1;
		int pivot_index = points.size();

		while (pivot_index != k) {
			pivot_index = partition(points, left, right);
			if (pivot_index < k) {
				// [0...pivotIdx-1] is smaller than k. we need more so our new search space becomes
				// [pivotIdx ...right];
				left = pivot_index;
			} else {
				right = pivot_index - 1;
				// more than needed has been included in [left..pivot index] so our search space
				// become [left,pivotIdx-1]
			}
		}

		return vector(points.begin(), points.begin() + k);
	}

	int partition(vector<vector<int>>& points, int left, int right) {
		int pivot = left + (right - left) / 2;
		int pivot_distance = get_distance(points[pivot]);

		while (left < right) {
			if (get_distance(points[left]) >= pivot_distance) {
				// All elements greater than or equal to pivot go right
				std::swap(points[left], points[right]);
				--right;
			} else {
				++left;
			}
		}
		// Check left element
		if (get_distance(points[left]) < pivot_distance)
			++left;
		return left;
	}

	int get_distance(const vector<int>& point) { return point[0] * point[0] + point[1] * point[1]; }
};
