#include "Plurality.cpp"
#include<String>
#include <iostream>

class Group
{

private:
	Plurality plur;
	int* first, * second;

public:
	Group() { intializeArrays(); gameLoop(); };
	Group(Plurality pl) :plur(pl) {
		intializeArrays();
		gameLoop();
	};



	~Group() {
		deleteArr(first);
		deleteArr(second);
	};

	void show(int* arr) {
		for (int i = 0; i < plur.getSize(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void deleteArr(int* arr) { delete[] arr; }

	void intializeArrays() {
		first = new int[plur.getSize()];
		second = new int[plur.getSize()];

		for (int i = 0; i < plur.getSize(); i++) {
			first[i] = plur.getIntFromPluralityByIndex(i);
			second[i] = plur.getIntFromPluralityByIndex(i);
		}
	}

	void swap(int* arr, int firstIndex, int secondIndex) {
		int buf = 0;
		try {
			if ((firstIndex >= 0 && firstIndex < plur.getSize()) && (secondIndex >= 0 && secondIndex < plur.getSize())) {
				buf = arr[firstIndex];
				arr[firstIndex] = arr[secondIndex];
				arr[secondIndex] = buf;
				return;
			}
			throw "One of the index out of range of array";
		}
		catch (char* ex) {
			cout << ex << endl;
			return;
		}
	}

	int* Transposition(int* fi, int* se, bool isPartial) {
		int* arr = new int[plur.getSize()];
		for (int i = 0; i < plur.getSize(); i++) {
			arr[i] = fi[se[i] - 1];
		}

		if (!isPartial) {
			show(arr);
			deleteArr(arr);
			return nullptr;
		}

		return arr;
	}


	void inverse(int* arr, int* invar) {
		for (int i = 0; i < plur.getSize(); i++) {
			invar[arr[i] - 1] = i + 1;
		}
	}

	bool isAssociatively(int* fi, int* se) {
		for (int i = 0; i < plur.getSize(); i++) {
			if (fi[i] != se[i]) {
				deleteArr(fi);
				deleteArr(se);
				return false;
			}
		}
		deleteArr(fi);
		deleteArr(se);
		return true;
	}


	void gameLoop() {
		int chooser = 0, choose = 0;
		int* arr;
		cout << "To create permutation you need swap at least two elements in arrays from 0 to " << plur.getSize() - 1 << endl;
		cout << "Use 1 to swap " << endl << "Use -1 to exit" << endl << "Use -2 to show array sequence now" << endl;
		cout << endl << "First array" << endl;
		looper(first);
		cout << endl << "Second array" << endl;
		looper(second);

		cout << "1 - Transposition permutations" << endl << "2 - Is asscoiatively" << endl << "3 - Transposition with e plurality" << endl << "4 - Take inversion permutation" << endl << "-1 - To exit from programm";

		while (chooser != -1) {
			cin >> chooser;

			switch (chooser)
			{
			case 1:


				cout << endl << "Choose beetween " << endl << "1 - (First o Second)" << endl << "2 - (Second o First)" << endl;
				cin >> choose;

				switch (choose)
				{
				case 1:
					cout << "(First o Second)" << endl;
					Transposition(first, second, false);
					break;
				case 2:
					cout << "(Second o First)" << endl;
					Transposition(second, first, false);
					break;
				default:
					break;
				}
				choose = 0;
				break;

			case 2:

				arr = new int[plur.getSize()];
				for (int i = 0; i < plur.getSize(); i++) { arr[i] = plur.getIntFromPluralityByIndex(i); }

				swap(arr, 0, plur.getSize() - 1);
				cout << "First o (Second o Third) = (First o Second) o Third" << endl;

				if (isAssociatively(Transposition(first, Transposition(second, arr, true), true), Transposition(Transposition(first, second, true), arr, true)) == true) {
					cout << "True" << endl;
				}
				else { cout << "False" << endl; }

				deleteArr(arr);
				break;

			case 3:
				cout << endl << "Choose beetween " << endl << "1 - (First o e)" << endl << "2 - (e o First)" << endl << "3 - (Second o e)" << endl << "4 - (e o Second)" << endl;

				arr = new int[plur.getSize()];

				for (int i = 0; i < plur.getSize(); i++) { arr[i] = plur.getIntFromPluralityByIndex(i); }
				cin >> choose;

				switch (choose)
				{
				case 1:
					cout << "(First o e)" << endl;
					Transposition(first, arr, false);
					break;
				case 2:
					cout << "(e o First)" << endl;
					Transposition(arr, first, false);
					break;
				case 3:
					cout << "(Second o e)" << endl;
					Transposition(second, arr, false);
					break;
				case 4:
					cout << "(e o Second)" << endl;
					Transposition(arr, second, false);
					break;
				default:
					break;
				}

				choose = 0;

				deleteArr(arr);
				break;
			case 4:
				cout << "Choose beetween " << endl << "1 - (First^(-1) o First)" << endl << "2 - (Second^(-1) o Second)" << endl;
				cin >> choose;
				arr = new int[plur.getSize()];

				switch (choose)
				{
				case 1:
					inverse(first, arr);
					cout << "First^(-1)" << endl;

					show(arr);

					cout << "First^(-1) o First" << endl;
					Transposition(arr, first, false);

					break;
				case 2:
					inverse(second, arr);
					cout << "Second^(-1)" << endl;

					show(arr);

					cout << "Second^(-1) o Second" << endl;
					Transposition(arr, second, false);

					break;
				default:
					break;
				}
				choose = 0;
				deleteArr(arr);

				break;

			default:
				break;
			}
		}

	}

	void looper(int* arr) {
		int buferOne = 0, buferTwo = 0, chooser = 0;
		while (chooser != -1) {
			cout << endl << "Chooser" << endl;
			cin >> chooser;

			switch (chooser)
			{
			case -1:
				break;
			case -2:
				show(arr);
				break;
			case 1:
				cout << "First and Second index" << endl;
				cin >> buferOne;
				cin >> buferTwo;
				swap(arr, buferOne, buferTwo);
				break;
			default:
				break;
			}
		}
	}


	int* getFrist() { return first; }
	int* getSecond() { return second; }
};
