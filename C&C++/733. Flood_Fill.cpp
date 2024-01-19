//此解法會導致推疊溢位，所以我們採用下面的改良版
/*
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row_len = image.size();
        int col_len = image[0].size();
        
        if(sr < row_len - 1 && image[sr+1][sc] == image[sr][sc])
            floodFill(image, sr+1, sc, color);
        
        if(sr > 0 && image[sr-1][sc] == image[sr][sc])
            floodFill(image, sr-1, sc, color);

        if(sc < col_len - 1 && image[sr][sc+1] == image[sr][sc])
            floodFill(image, sr, sc+1, color);

        if(sc > 0 && image[sr][sc-1] == image[sr][sc])
            floodFill(image, sr, sc-1, color);
        
        image[sr][sc] = color;

        return image;
    }
};
*/


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row_len = image.size();
        int col_len = image[0].size();
        
        int original_color = image[sr][sc];
        if (original_color == color) {
            // 如果目標顏色已經是目前像素的顏色，無需進行填充
            return image;
        }

        stack<pair<int, int>> stack;
        stack.push({sr, sc});

        while (!stack.empty()) {
            auto [r, c] = stack.top();
            stack.pop();

            if (r < 0 || r >= row_len || c < 0 || c >= col_len || image[r][c] != original_color) {
                // 超出邊界或當前像素不是原始顏色，跳過
                continue;
            }

            // 填充當前像素
            image[r][c] = color;

            // 將相鄰像素入堆疊
            stack.push({r + 1, c});
            stack.push({r - 1, c});
            stack.push({r, c + 1});
            stack.push({r, c - 1});
        }

        return image;
    }
};
