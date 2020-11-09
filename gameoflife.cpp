#include "gameoflife.hpp"

int vector_count_llu(vector<int> vec, int value)
{
    int count = 0;
    for(int i = 0; i < vec.size(); i++)
        if(vec[i] == value)
            count++;
    return count;
}

vector<int> vector_slice_llu(vector<int> vec, int start, int end, int stride=1)
{
    auto res = vector<int>{};
    for(int i = start; i < end; i += stride)
        res.push_back(vec[i]);
    return res;
}

void render(vector<vector<int>> board)
{
    for(int row = 1; row < board.size()-1; ++row)
    {
        for(int col = 1; col < board[0].size()-1; ++col)
        {
          if(board[row][col] == 0)
              cout << "   ";
          else
              cout << " # ";
        }
        cout << endl;
    }
}

vector<vector<int>> dead_state(int width=10, int height=10)
{
    auto res = vector<vector<int>>{};
    auto temp = vector<int>{};
    width += 2; height += 2;
    for(int row = 0; row < width; ++row)
    {
        for(int col = 0; col < height; ++col)
        {
            temp.push_back(0);
        }
        res.push_back(temp);
        temp.clear();
    }
    return res;
}

vector<vector<int>> random_state(int width=10, int height=10, int threshold=30)
{
    auto board = dead_state(width, height);
    int max_random_value = 100;
    srand(time(0));
    for(int row = 1; row < width+1; ++row)
    {
        for(int col = 1; col < height+1; ++col)
        {
            int temp_random_value = rand() % max_random_value;
            if(temp_random_value > threshold)
                board[row][col] = 0;
            else
                board[row][col] = 1;
        }
    }
    return board;
}

vector<vector<int>> next_board_state(vector<vector<int>> board)
{
    auto new_board = dead_state(board[0].size()-2, board.size()-2);
    for(int row = 1; row < board.size()-1; ++row)
    {
        for(int col = 1; col < board[0].size()-1; ++col)
        {
            int top = vector_count_llu(vector_slice_llu(board[row-1], col-1, col+2), 1);
            int middle = vector_count_llu(vector_slice_llu(board[row], col-1, col+2), 1);
            int bottom = vector_count_llu(vector_slice_llu(board[row+1], col-1, col+2), 1);
            if(board[row][col] == 0)
            {
                int total = top + middle + bottom;
                if(total == 3)
                    new_board[row][col] = 1;
                else
                    new_board[row][col] = 0;
            }
            else
            {
                int total = (top + middle + bottom) - 1;
                if(total <= 1 || total > 3)
                    new_board[row][col] = 0;
                else
                    new_board[row][col] = 1;
            }
        }
    }
    return new_board;
}
