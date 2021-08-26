#include <map>
#include <iostream>

using namespace std;

int main()
{
	map<int, int> mp = { {1,2}, {3,4} };

	for (auto& it : mp)
		cout << it.first << " " << it.second << endl;
	cout << endl;

	if (mp.find(1) != mp.end()) // logn
		cout << "1 is present in the map with value = " << mp[1] << endl;
	if (mp.find(5) == mp.end())
		cout << "Key 5 is not present in the map\n";

	mp.insert({ 4,5 }); // move and emplace (perfect forwarding)
	mp.emplace(6, 7);  // emplace (perfect forwarding)

	mp[5] = 23;
	mp.operator[](3) = 23;
	
	for (auto& it : mp)
		cout << it.first << " " << it.second << endl;
	cout << endl;

	map<int, int> mp2, mp3;
	mp3 = mp2 = mp;
	
	for (auto& it : mp3)
		cout << it.first << " " << it.second << endl;
	cout << endl;


	map<int, int, greater<int>> mp5(mp3.begin(), mp3.end());
	map<int, int, greater<int>> mp6(mp5);

	for (auto& it : mp5)
		cout << it.first << " " << it.second << endl;
	cout << endl;

	mp5.erase(5);

	for (auto& it : mp5)
		cout << it.first << " " << it.second << endl;
	cout << endl;


	cin.get();
	return 0;
}
