#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

const int BEES = 2023;

// COMPILE IT WITH C++17

void print_pair_two_pointers(vector<int>& input)
{
    sort(input.begin(), input.end());
    int p1 = 0, p2 = input.size() - 1;

    while (p1 != p2)
    {
        if (input[p1] + input[p2] > BEES)
            p2--;
        else if (input[p1] + input[p2] < BEES)
            p1++;
        else
        {
            cout << input[p1] << endl << input[p2] << endl;
            return ;
        }
    }
    cout << "No appropriate pair." << endl;
    return ;
}

void print_pair_unordered_map(unordered_map<int, int>& input)
{
    for (auto& it: input)
    {
        if (input.find(BEES - it.first) != input.end())
        {
            cout << BEES - it.first << ' ' << it.first << endl;
            return ;
        }
    }
    cout << "No appropriate pair." << endl;
    return ;
}

int main()
{
    try
    {
        ifstream input_file("Input task1.txt");
        if (!input_file)
            throw invalid_argument("Wrong file name");
        unordered_map<int, int> input_arr;
        string line;
        int numb;
        while (getline(input_file, line))
        {
            stringstream(line) >> numb;
            input_arr.try_emplace(numb, 1);
        }
        // print_pair_two_pointers(input_vector); 
        print_pair_unordered_map(input_arr);
        input_file.close();
    }
    catch(exception const& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}