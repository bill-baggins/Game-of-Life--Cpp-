#include <vector>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#ifndef gameoflife_HPP
#define gameoflife_HPP

#define llu unsigned long long

using namespace std;

int vector_count_llu(vector<int> vec, int value);

vector<int> vector_slice_llu(vector<int> vec, int start, int end, int stride);

void render(vector<vector<int>> board);

vector<vector<int>> dead_state(int width, int height);

vector<vector<int>> random_state(int width, int height, int threshold);

vector<vector<int>> next_board_state(vector<vector<int>> board);

#endif