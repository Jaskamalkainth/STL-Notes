#include <vector>
#include <list>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


// https://en.cppreference.com/w/cpp/container/vector/emplace_back
// https://stackoverflow.com/questions/28828159/usage-of-stdforward-vs-stdmove

void func(vector<vector<int>>& graph) 
{

}

struct myComp
{
	bool operator()(const int& a, const int& b) 
	{
		return a > b;
	}
};

int main()
{
	////// vec of ints
	vector<int> vecInts = { 1,2,3 };
	vecInts.push_back(4);

	vector<string> vecStrs = { "s1", "s2" };
	vecStrs.push_back("s3"); //ammortized O(1)
	vecStrs.emplace_back("s4");
	string s5 = "s5";
	vecStrs.emplace_back(s5);
	vecStrs.push_back(s5);

	vecStrs.pop_back();
	string backStr = vecStrs.back();
	string frontStr = vecStrs.front();
	cout << "front Str = " << frontStr << endl;
	cout << "backStr = " << backStr << endl;

	for (auto& str : vecStrs)
		cout << str << " ";
	cout << endl;

	for (int i = 0; i < vecStrs.size(); ++i)
		cout << vecStrs[i] << " ";
	cout << endl;

	for (auto it = vecStrs.begin(); it != vecStrs.end(); ++it)
		cout << *it << " ";
	cout << endl;

	vector<int> vecResInt;
	vecResInt.reserve(1 << 10);
	/*
	Vectors can grow or shrink as required. Vectors are assigned memory in blocks of contiguous locations. When the memory allocated for the vector falls short of 
	storing new elements, a new memory block is allocated to vector and all elements are copied from the old location to the new location. 
	This reallocation of elements helps vectors to grow when required. However, it is a costly operation and time complexity is involved in this step is linear.
	https://www.geeksforgeeks.org/using-stdvectorreserve-whenever-possible/
	*/

	///// vec of pairs 
	vector<pair<int, int>> vecPairs;
	vecPairs.push_back({ 1,2 }); // mostly
	vecPairs.push_back(make_pair( 1,2 ));
	vecPairs.push_back(pair<int,int>( 1,2 ));

	for (auto& it : vecPairs)
	{
		cout << it.first << " " << it.second << endl;
	}
	vecPairs.emplace_back(1, 2); // multiple arguments

	//// vec of vectors

	int n = 10;
	vector<vector<int>> graph(n, vector<int>(n));  // int graph[10][10];

	func(graph);


	vector<int> sortedVec = { 3,2,4,5,2,3,2};


	for (int n : sortedVec)
		cout << n << " ";
	cout << endl;
	//sort(sortedVec.begin(), sortedVec.end(), myComp());
	sort(sortedVec.begin(), sortedVec.end(), [](const int& a, const int& b)
		{
			return a > b;
		});

	cout << "After sorting\n";

	for (int n : sortedVec)
		cout << n << " ";
	cout << endl;

	///////////////////// list

	list<int> listInt = { 1, 2, 3 }; // bidirectional linked list
	listInt.push_back(4);
	listInt.push_front(0);

	listInt.emplace_front(-1);
	listInt.emplace_back(5);

	

	auto it1 = listInt.insert(listInt.begin(), -2); // iterator for the value -2
	listInt.emplace_front(-3);
	listInt.emplace_front(-4);

	for (auto& it : listInt)
		cout << it << " ";
	cout << endl;

	// I want to remove -2 from the list 

	listInt.erase(it1); // imp O(1)
	listInt.remove(2); // O(n)
	 /*
	ump[2] = list_it; // O(1)
	listInt.erase(list_it); // //O(1)
	*/

	for (auto& it : listInt)
		cout << it << " ";
	cout << endl;
	
	cin.get();
	return 0;
}
