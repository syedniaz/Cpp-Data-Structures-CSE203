#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int>  vec;
	
	if (!vec.empty()) cout <<  "list not empty" << endl;
	else cout <<  "list empty" << endl;
	
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	
	cout << vec.size() << endl;
	
	if (!vec.empty()) cout <<  "list not empty" << endl;
	else cout <<  "list empty" << endl;
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i)<< endl; // cout << vec[i]<< endl; <- array style
	}
	
	return 0;
}