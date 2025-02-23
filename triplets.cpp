#include <bits/stdc++.h>
using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
    int count = 0;

    // Hash maps to track counts of possible values for the triplet
    unordered_map<int, int> count1, count2;

    // Traverse the array
    for (int j = 0; j < arr.size(); ++j) {
        // For each arr[j], check if there is a valid arr[i] and arr[k]
        // arr[j] can be the middle element of the triplet
        if (count2.find(arr[j]) != count2.end()) {
            count += count2[arr[j]]; // Add to the count of valid triplets
        }
        
        // Update count2: this means arr[j] could be the middle of a future triplet
        if (count1.find(arr[j]) != count1.end()) {
            count2[arr[j] + d] += count1[arr[j]]; // arr[j] + d could be the third element
        }

        // Update count1: this means arr[j] could be the first element of a future triplet
        count1[arr[j] + d] += 1;
    }

    return count;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    int d = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    int result = beautifulTriplets(d, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
