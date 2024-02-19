#include <gtest/gtest.h>
#include <Search_tree/Search_tree.h>
#include <time.h> 

using namespace std;

TEST(Search_tree, Methods1) {
	Set<int> Tree;
	for (size_t i = 0; i < 10; ++i) {
		Tree.insert(lcg());
	}
	Set<int> SecondTree(Tree);
	Set<int> ThirdTree;
	ThirdTree = Tree;
	Tree.print();
	SecondTree.print();
	ThirdTree.print();
}

TEST(Search_tree, Methods2) {
	Set<int> Tree;
	size_t tmp;
	for (size_t i = 0; i < 10; ++i) {
		if (i == 6) {
			tmp = lcg();
			Tree.insert(tmp);
		}
		else
			Tree.insert(lcg());
	}
	EXPECT_TRUE(Tree.contains(tmp));
}

TEST(Search_tree, Methods3) {
	Set<int> Tree;
	size_t tmp;
	for (size_t i = 0; i < 10; ++i) {
		if (i == 6) {
			tmp = lcg();
			Tree.insert(tmp);
		}
		else
			Tree.insert(lcg());
	}
	Tree.erase(tmp);
	Tree.print();
	EXPECT_FALSE(Tree.contains(tmp));
}

TEST(Search_tree, TaskVariant4) {
	vector<int> vec;
	//for (size_t i = 0; i < 90; ++i)
	//	lcg();
	for (size_t i = 0; i < 30; ++i) {
		vec.push_back(lcg() % 20);
	}
	vec = without_repetitions<int>(vec);
	size_t size = vec.size();
	cout << "The size was 30, but it became " << size << endl;
	cout << "It's elements:";
	for (int i = 0; i < size; ++i)
		cout << vec[i] << ", ";
}

TEST(Search_tree, Experement1Set) {
	double sum = 0;
	for (size_t i = 0; i < 100; ++i) {
		Set<size_t> Tree;
		clock_t t = clock();
		for (size_t j = 0; j < 1000; ++j)
			Tree.insert(lcg());
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Set's the average filling time is 1000 numbers:" << sum / 100 << endl;


	sum = 0;
	for (size_t i = 0; i < 100; ++i) {
		Set<size_t> Tree;
		clock_t t = clock();
		for (size_t j = 0; j < 10000; ++j)
			Tree.insert(lcg());
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Set's the average filling time is 10000 numbers:" << sum / 100 << endl;


	sum = 0;
	for (size_t i = 0; i < 100; ++i) {
		Set<size_t> Tree;
		clock_t t = clock();
		for (size_t j = 0; j < 100000; ++j)
			Tree.insert(lcg());
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Set's the average filling time is 100000 numbers:" << sum / 100 << endl;
}

TEST(Search_tree, Experement1Vector) {
	double sum = 0;
	for (size_t i = 0; i < 100; ++i) {
		vector<size_t> vec;
		clock_t t = clock();
		for (size_t j = 0; j < 1000; ++j)
			vec.push_back(lcg());
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Vector's the average filling time is 1000 numbers:" << sum / 100 << endl;


	sum = 0;
	for (size_t i = 0; i < 100; ++i) {
		vector<size_t> vec;
		clock_t t = clock();
		for (size_t j = 0; j < 10000; ++j)
			vec.push_back(lcg());
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Vector's the average filling time is 10000 numbers:" << sum / 100 << endl;


	sum = 0;
	for (size_t i = 0; i < 100; ++i) {
		vector<size_t> vec;
		clock_t t = clock();
		for (size_t j = 0; j < 100000; ++j)
			vec.push_back(lcg());
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Vector's the average filling time is 100000 numbers:" << sum / 100 << endl;
}


TEST(Search_tree, Experement2Set) {
	size_t rand_i, rand_elem;
	
	double sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		Set<size_t> Tree;
		rand_i = lcg() % 1000;
		for (size_t j = 0; j < 1000; ++j) {
			if (j == rand_i) {
				rand_elem = lcg();
				Tree.insert(rand_elem);
			}
			else
				Tree.insert(lcg());
		}
		clock_t t = clock();
		Tree.contains(rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Set's time to search for an element (1000):" << sum / 1000 << endl;


	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		Set<size_t> Tree;
		rand_i = lcg() % 10000;
		for (size_t j = 0; j < 10000; ++j) {
			if (j == rand_i) {
				rand_elem = lcg();
				Tree.insert(rand_elem);
			}
			else
				Tree.insert(lcg());
		}
		clock_t t = clock();
		Tree.contains(rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Set's time to search for an element (10000):" << sum / 1000 << endl;


	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		Set<size_t> Tree;
		rand_i = lcg() % 100000;
		for (size_t j = 0; j < 100000; ++j) {
			if (j == rand_i) {
				rand_elem = lcg();
				Tree.insert(rand_elem);
			}
			else
				Tree.insert(lcg());
		}
		clock_t t = clock();
		Tree.contains(rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Set's time to search for an element (100000):" << sum / 1000 << endl;
}

TEST(Search_tree, Experement2Vector) {
	size_t rand_i, rand_elem;
	double sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		vector<size_t> vec;
		rand_i = lcg() % 1000;
		for (size_t j = 0; j < 1000; ++j) {
			if (j == rand_i) {
				rand_elem = lcg();
				vec.push_back(rand_elem);
			}
			else
				vec.push_back(lcg());
		}
		clock_t t = clock();
		find(vec.begin(), vec.end(), rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Vector's time to search for an element (1000):" << sum / 1000 << endl;


	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		vector<size_t> vec;
		rand_i = lcg() % 10000;
		for (size_t j = 0; j < 10000; ++j) {
			if (j == rand_i) {
				rand_elem = lcg();
				vec.push_back(rand_elem);
			}
			else
				vec.push_back(lcg());
		}
		clock_t t = clock();
		find(vec.begin(), vec.end(), rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Vector's time to search for an element (100000):" << sum / 1000 << endl;


	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		vector<size_t> vec;
		rand_i = lcg() % 100000;
		for (size_t j = 0; j < 100000; ++j) {
			if (j == rand_i) {
				rand_elem = lcg();
				vec.push_back(rand_elem);
			}
			else
				vec.push_back(lcg());
		}
		clock_t t = clock();
		find(vec.begin(), vec.end(), rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Vector's time to search for an element (100000):" << sum / 1000 << endl;
}

TEST(Search_tree, Experement3Set) {
	size_t rand_i, rand_elem;
	double sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		Set<int> Tree;
		rand_i = lcg() % 1000;
		for (size_t j = 0; j < 1000; ++j) {
			Tree.insert(lcg());
		}
		rand_elem = lcg();
		clock_t t = clock();
		Tree.insert(rand_elem);
		Tree.erase(rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Set's time to insert and delete an element:" << endl;
	cout << "for 1000 elements:" << sum / 1000 << endl;

	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		Set<int> Tree;
		rand_i = lcg() % 10000;
		for (size_t j = 0; j < 10000; ++j) {
			Tree.insert(lcg());
		}
		rand_elem = lcg();
		clock_t t = clock();
		Tree.insert(rand_elem);
		Tree.erase(rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "for 10000 elements:" << sum / 10000 << endl;

	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		Set<int> Tree;
		rand_i = lcg() % 100000;
		for (size_t j = 0; j < 100000; ++j) {
			Tree.insert(lcg());
		}
		rand_elem = lcg();
		clock_t t = clock();
		Tree.insert(rand_elem);
		Tree.erase(rand_elem);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "for 100000 elements:" << sum / 100000 << endl;
}

TEST(Search_tree, Experement3Vector) {
	size_t rand_i, rand_elem;
	double sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		vector<int> vec;
		rand_i = lcg() % 1000;
		for (size_t j = 0; j < 1000; ++j) {
			vec.push_back(lcg());
		}
		rand_elem = lcg();
		clock_t t = clock();
		vec.insert(vec.begin() + rand_i, rand_elem);
		vec.erase(vec.begin() + rand_i);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "Vector's time to insert and delete an element:" << endl;
	cout << "for 1000 elements:" << sum / 1000 << endl;

	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		vector<int> vec;
		rand_i = lcg() % 10000;
		for (size_t j = 0; j < 10000; ++j) {
			vec.push_back(lcg());
		}
		rand_elem = lcg();
		clock_t t = clock();
		vec.insert(vec.begin() + rand_i, rand_elem);
		vec.erase(vec.begin() + rand_i);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "for 10000 elements:" << sum / 10000 << endl;

	sum = 0;
	for (size_t i = 0; i < 1000; ++i) {
		vector<int> vec;
		rand_i = lcg() % 100000;
		for (size_t j = 0; j < 100000; ++j) {
			vec.push_back(lcg());
		}
		rand_elem = lcg();
		clock_t t = clock();
		vec.insert(vec.begin() + rand_i, rand_elem);
		vec.erase(vec.begin() + rand_i);
		sum += (float)(clock() - t) / CLOCKS_PER_SEC;
	}
	cout << "for 100000 elements:" << sum / 100000 << endl;
}

