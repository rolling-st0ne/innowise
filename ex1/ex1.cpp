#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int BEES = 2023;

void print_pair_two_pointers(vector<int>& input)
{
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

int main()
{
    try
    {
        ifstream input_file("Input task1.txt");
        if (!input_file)
            throw invalid_argument("Wrong file name");
        vector<int> input_vector;
        string line;
        int numb;
        while (getline(input_file, line))
        {
            stringstream(line) >> numb;
            input_vector.push_back(numb);
        }

        sort(input_vector.begin(), input_vector.end());
        print_pair_two_pointers(input_vector); 
        input_file.close();
    }
    catch(exception const& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}