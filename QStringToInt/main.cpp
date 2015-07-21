#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    string str = "23.45.666.4.3";
    std::string::size_type sz;
    str.erase(std::remove(str.begin(), str.end(), '.'), str.end());

    int i_decimal = std::stoi (str,&sz);

    cout << "dec : " << i_decimal << endl;

    return 0;
}

