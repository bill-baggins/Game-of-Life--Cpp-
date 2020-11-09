#include "gameoflife.hpp"

int main()
{
    int count = 0;
    int width;
    // User-input for width.
    while(1)
    {
        cout << "Conway's Game of Life" << endl;
        cout << "Enter in the width of your board:" << endl;
        cin >> width;
        if(width == 0)
        {
            cout << "Invalid input. Setting default width to 10." << endl;
            width = 10;
        }
        break;
    }
    // User-input for height.
    int height;
    while(1)
    {
        cout << "Enter in the height of the board:" << endl;
        cin >> height;
        if(height == 0)
        {
            cout << "Invalid input. Setting default height to 10." << endl;
            height = 10;
        }
        break;
    }
    system("CLS");

    auto initial_board = random_state(width, height, 35);
    auto new_board     = dead_state(width, height);
    auto old_board     = dead_state(width, height);
    while(1)
    {
        cout << "Conway's Game Of Life" << endl;
        cout << "Iteration " << count << endl;
        render(initial_board);
        new_board = next_board_state(initial_board);
        old_board = initial_board;
        initial_board = new_board;
        count++;
        Sleep(750);
        system("CLS");
    }
}