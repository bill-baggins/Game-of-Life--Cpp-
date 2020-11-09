#include "gameoflife.hpp"

int main()
{
    // User-input for width.
    string str_width;
    int width = 0;
    cout << "Conway's Game of Life" << endl;
    while(1)
    {
        cout << "Enter in the width of your board:" << endl;
        getline(cin, str_width);
        try 
        { 
            width = stoi(str_width); 
        }
        catch(invalid_argument) 
        {
            system("CLS");
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        if(width == 0) continue;
        break;
    }

    // User-input for height.
    string str_height;
    int height = 0;
    while(1)
    {
        cout << "Enter in the height of the board:" << endl;
        getline(cin, str_height);
        try
        {
            height = stoi(str_height);
        }
        catch(invalid_argument)
        {
            system("CLS");
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        if(height == 0) continue;
        break;
    }
    system("CLS");

    auto initial_board = random_state(width, height, 33);
    auto new_board     = dead_state(width, height);
    auto old_board     = dead_state(width, height);
    int count = 0;
    while(1)
    {
        cout << "Conway's Game Of Life" << endl;
        cout << "Iteration " << count << endl;

        render(initial_board);
        new_board = next_board_state(initial_board);
        old_board = initial_board;
        initial_board = new_board;

        ++count;
        Sleep(750);
        system("CLS");
    }
}