#ifndef PLURALITY_CPP
#define PLURALITY_CPP

#include<iostream>
#include<list>
using namespace std;

class Plurality
{
public:
	Plurality() {
		int a = 0;
		cout << "Please input numbers in plurarity. Press -1 to exit" << endl;
		cout << "You can input same numbers but they will delete from plurarity" << endl;
		cout << "Input in sequential order" << endl;
		while (a != -1) {
			cin >> a;
			plurality.push_back(a);
		}
		plurality.sort();
		plurality.unique();
		plurality.pop_front();
	};

	Plurality(int* arr, int cnt) {
		for (int i = 0; i < cnt; i++) {
			plurality.push_back(arr[i]);
		}
		plurality.unique();
		plurality.sort();
	}

	Plurality(Plurality& obj) {
		for (int i = 0; i < obj.getSize(); i++) {
			plurality.push_back(obj.getIntFromPluralityByIndex(i));
		}
	}

	~Plurality() { plurality.clear(); };

	void show() {
		for (int var : plurality)
		{
			cout << var << " ";
		}
		cout << endl;
	}


	int setIntInPlurality(int store) {
		plurality.push_back(store);
	}

	int getIntFromPluralityByIndex(int index) {
		list<int>::iterator iter = plurality.begin();
		while (index != 0) { index--; ++iter; }
		return *iter;
	}

	int getSize() {
		return plurality.size();
	}

	list<int> getList() {
		return plurality;
	}

	void resizeList(int n) {
		plurality.resize(n);
	}

private:
	list<int> plurality;
};
#endif