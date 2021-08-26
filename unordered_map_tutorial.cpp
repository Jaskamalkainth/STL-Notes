#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


struct myHashFunc
{
	int operator()(const pair<int, int>& p1) const
	{
		return p1.first  ^ (p1.second << 1);
	}
};

struct myHashFuncPairString
{
	bool operator()(const pair<string, string>& p1) const
	{
		size_t v1 = hash<string>{}(p1.first);
		size_t v2 = hash<string>{}(p1.second);
		return v1 ^ (v2 << 1);
	}
};
// https://en.cppreference.com/w/cpp/utility/hash

int main()
{
	cout << hash<string>{}("Swc session by Jaskamal kainth") << endl;

	unordered_map<int, int> ump; // hash table of key value 

	// Optimisation
	ump.reserve(1 << 15);
	ump.max_load_factor(0.25f);

	cout << ump.size() << endl;

	ump.insert({ 1,2 });
	ump[2] = 3;

	if (ump[1] != 0) // not a good practise?
	{

	}
	if (ump.find(1) != ump.end())
	{
		cout << "key = 1 present and it's value = " << ump[1] << endl;
	}

	cout << ump.size() << endl;

	for (auto& it : ump)
		cout << it.first << " " << it.second << endl;

	unordered_map<int, int> ump2 = { {1,2}, {2,3} }; // rvalue references are used for perfect forwarding

	for (auto& it : ump2)
		cout << it.first << " " << it.second << endl;

	unordered_map<int, int> ump3(ump2);

	// -------------------- int -> vector/list mapping
	unordered_map<int, vector<int>> ump4;
	ump4[1] = { 2,3,4 };
	ump4[2] = { 3,4,5 };

	ump4[3].push_back(6);
	
	for (auto& it : ump4)
	{
		cout << it.first << " : ";
		vector<int>& vec = it.second;
		for (auto& n : vec)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	unordered_map<int, list<int>> ump5;
	ump5[1] = { 2,3,4 };
	ump5[2] = { 3,4,5 };

	for (auto& it : ump5)
	{
		cout << it.first << " : ";
		list<int>& vec = it.second;
		for (auto& n : vec)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	/////////// - unordered map with pair

	unordered_map < pair<int,int>, int, myHashFunc> umpPairInt;
	
	umpPairInt[{1, 2}] = 1;
	umpPairInt[{2, 3}] = 2;

	if (umpPairInt.find({ 1,2 }) != umpPairInt.end())
		cout << "{1,2} found\n";
	if (umpPairInt.find({ 2,3 }) != umpPairInt.end())
		cout << "{2,3} found\n";
	if (umpPairInt.find({ 2,4 }) == umpPairInt.end())
		cout << "{2,4} not found\n";

	/////////////////

	// workaround for pair of int

	unordered_map<string, int> umpPairWorkAround;
	auto getHashString = [&](pair<int, int> p1)
	{
		return p1.first + "|" + p1.second; //{1, 2} -> "1&2"
	};
	umpPairWorkAround[getHashString({ 1, 2 })] = 1;
	umpPairWorkAround[getHashString({ 2, 3 })] = 1;
	
	if (umpPairWorkAround.find(getHashString({ 1, 2 })) != umpPairWorkAround.end())
		cout << "{1,2} found\n";
	if (umpPairWorkAround.find(getHashString({ 2, 3 })) != umpPairWorkAround.end())
		cout << "{2,3} found\n";
	if (umpPairWorkAround.find(getHashString({ 2, 4 })) == umpPairWorkAround.end())
		cout << "{2,4} not found\n";

	// 

    //unordered_map<pair<int,int>, int> data;
    unordered_map<int,unordered_map<int,int>> trick; // could be slow
	// insert {1,2} -> 5
	// trick[1][2] = 5;

	cin.get();
	return 0;
}
