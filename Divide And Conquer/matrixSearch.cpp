int greatestlesser(vector<vector<int>>& matrix,int low, int high, int key)
{
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low + 1) / 2;
        int midVal = matrix[mid][0];
        if (midVal < key) ans = mid,low = mid + 1;
        else if (midVal > key) high = mid - 1;
        else if (midVal == key) high = mid - 1;
    }
    return ans;
}
int contains1(vector<vector<int>>& matrix,int low, int high, int key)
{
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midVal = matrix[mid][0];
        if (midVal < key) low = mid + 1;
        else if (midVal > key) high = mid - 1;
        else if (midVal == key) {
            ans = mid;
            break;
        }
    }

    return ans;
}
int contains2(vector<int>& list,int low, int high, int key)
{
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midVal = list[mid];
        if (midVal < key) low = mid + 1;
        else if (midVal > key) high = mid - 1;
        else if (midVal == key) {
            ans = mid;
            break;
        }
    }

    return ans;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int row = contains1(matrix,0,matrix.size()-1,target);
        if(row!=-1) return true;
        row = greatestlesser(matrix,0,matrix.size()-1,target);
        if(row==-1) return false;
        int col=contains2(matrix[row],0,matrix[row].size()-1,target);
        if(col!=-1) return true;
        return false;
}
