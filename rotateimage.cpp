class Solution {
public:
    void ring(vector<vector<int>>& matrix, const int depth, const int n) {
        int i = depth;
        int j = depth;
        int prev = matrix[depth+1][depth];
        int state = 0; // right
        do {
            int next_i = i;
            int next_j = j;
            switch (state) {
                case 0: // right
                    next_j++;
                    if (next_j >= n-depth) {
                        state = 1;
                        next_j--;
                        next_i++;
                    }
                    break;
                case 1: // down
                    next_i++;
                    if (next_i >= n-depth) {
                        state = 2;
                        next_i--;
                        next_j--;
                    }
                    break;
                case 2: // left
                    next_j--;
                    if (next_j < depth) {
                        state = 3;
                        next_j++;
                        next_i--;
                    }
                    break;
                case 3: // up
                    next_i--;
                    if (next_i < depth) {
                        state = 0; // don't really care about state here
                        next_i++;
                        next_j++;
                    }
                    break;
            }
            matrix[i][j] ^= prev;
            prev ^= matrix[i][j];
            matrix[i][j] ^= prev;
            i = next_i;
            j = next_j;
        } while (i != depth || j != depth);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        int depth = 0;
        while (depth < n/2) {
            const int shifts = n - (depth*2) - 1;
            for(int s = 0; s < shifts; s++) {
                ring(matrix, depth, n);
            }
            depth++;
        } 
    }
};
