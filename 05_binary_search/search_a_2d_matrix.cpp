class Solution {
  public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		// Choose the correct matrix
		const int num_row = matrix.size();
		const int num_col = matrix[0].size();

		int low = 0;
		int high = num_row - 1;
		int mid = 0;
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (matrix[mid][0] == target || matrix[mid][num_col - 1] == target)
				return true;
			if (matrix[mid][0] > target)
				high = mid - 1;
			else if (matrix[mid][num_col - 1] < target)
				low = mid + 1;
			else
				break;
		}

		low = 0;
		high = num_col - 1;
		const int found = mid;
		while (low <= high) {
			mid = low + (high - low) / 2;
			if (matrix[found][mid] > target)
				high = mid - 1;
			else if (matrix[found][mid] < target)
				low = mid + 1;
			else
				return true;
		}
		return false;
	}
};
