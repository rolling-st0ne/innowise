#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2)
{
	vector<int> merged_arr(arr1.size() + arr2.size());

	size_t index_arr_one = 0, index_arr_two = 0, index_merged = 0;
	while (index_arr_one < arr1.size()
           && index_arr_two < arr2.size()) {
        if (arr1[index_arr_one]
            <= arr2[index_arr_two]) {
            merged_arr[index_merged]
                = arr1[index_arr_one];
            index_arr_one++;
        }
        else {
            merged_arr[index_merged]
                = arr2[index_arr_two];
            index_arr_two++;
        }
        index_merged++;
    }

	while (index_arr_one < arr1.size()) {
        merged_arr[index_merged]
            = arr1[index_arr_one];
        index_arr_one++;
        index_merged++;
    }
   
    while (index_arr_two < arr2.size()) {
        merged_arr[index_merged]
            = arr2[index_arr_two];
        index_arr_two++;
        index_merged++;
    }

	return merged_arr;
}

void read_int_arr(ifstream& input_file, vector<int> &arr)
{
	int numb;
	string line;
	getline(input_file, line);
	istringstream iss(line);
	while (iss >> numb)
		arr.push_back(numb);
}

void print_vector(vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << endl;
}

int	main(int argc, char *argv[])
{
    try
    {	vector<int> merged_arr;
		vector<int> arr1, arr2;
        ifstream input_file(argv[1]);
        if (!input_file)
            throw invalid_argument("Wrong file name. Pass the input file name as command line argument.");
		read_int_arr(input_file, arr1);
		read_int_arr(input_file, arr2);
		input_file.close();
		merged_arr = merge(arr1, arr2);
		print_vector(merged_arr);
    }
    catch(exception const& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}