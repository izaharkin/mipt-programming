// АЛГОРИТМЫ. БЫСТРАЯ СОРТИРОВКА ХОАРА
//#include <std_lib_facilities>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

bool is_sorted(const vector <int>& a)     // проверить на отсортированность
{
	int sz = a.size();
	for (size_t i = 0; i < sz-1; i++)
		if ( a[i] > a[i+1] )
			return false;
	return true;
}

double dt(clock_t start, clock_t finish)  // узнать время выполнения
{
	return (finish - start) / double(CLOCKS_PER_SEC);
}

void exec (const vector <int>& a, const string comment, 
		   void sort(vector <int>&))
{
	vector <int> cpy(a);
	clock_t start = clock();
	sort(cpy);
	clock_t finish = clock();
	
	cout.precision(4);
	cout.setf(ios:: fixed);
	cout << setw(10) << comment << ": " 
		 << setw(8)  << dt(start, finish) 
		 << " s [" << (is_sorted(cpy) ? "OK" : "FAILED") << "]\n";
}

void quick_sort(vector <int>& a, const int& p, const int& r)
{
	const int n = r - p;       // размеры куска массива который сортируем
	if ( n <= 1 ) return;      // если один элемент, то отсортировано
	
	int m = p + rand() % n;    // выбираем 
	swap(a[p], a[m]);          // делаем первым
	int last = p;              // указатель на поледний элемент, не больший m
	for (int i = p+1; i < r; i++)
		if ( a[i] < a[p] )
			swap(a[++last], a[i]);
	swap(a[p], a[last]);
	
	quick_sort(a, p, last);    // здесь last == r(буд), который указывает ЗА массив, то есть будет сортироваться именно часть, которая левее x
	quick_sort(a, last+1, r);  // здесь будет сортироваться именно часть, которая правее x
}

void quick_sort(vector <int>& a)
{
	return quick_sort(a, 0, a.size());
}

void sort(vector <int>& a)
{
	return sort(a.begin(), a.end());
}
// Простые сортировки

// Пузырёк
void bubble_sort(vector <int>& a)
{
	size_t n = a.size();
	for (size_t i = 0; i < n; i++)
		for (size_t j = n-2; j >= 0; j--)
			if ( a[j+1] < a[j] )
				swap(a[j+1], a[j]);
}

// Выбором
void select_sort(vector <int>& a)
{
	size_t n = a.size();
	for (size_t i = 0; i < n-1; i++)
	{
		int imin = i;
		for (int j = i+1; j < n; j++)
			a[j] < a[imin] && imin == (imin = j);
		swap(a[i], a[imin]);
	}	
}

// Вставками
void insert_sort(vector <int>& a)
{
	size_t n = a.size();
	for (size_t i = 1; i < n; i++)
		for (size_t j = i; j > 0 && a[j] < a[j-1]; j--)
			swap(a[j], a[j-1]);
}

int main()
{
	const int n = 1000;
	
	vector <string> files;
	files.push_back("const.in.txt");
	files.push_back("seq.in.txt");
	files.push_back("rseq.in.txt");
	files.push_back("rand.in.txt");
	files.push_back("rand_2.in.txt");
	
	vector <int> arr(n);
	
	for (size_t k = 0; k < files.size(); k++)
	{
		ifstream ifs(files[k].c_str());
		if ( !ifs ) 
		{
			cerr << "can't open file '" + files[k] + "'";
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			if ( !(ifs >> arr[i]) ) 
			{
				cerr << "Invalid data";
				return 0;
			}
		}
		ifs.close();
	
		cout << "Data file: '" << files[k] << "'\n";
		cout << "Number of samples: " << n << "\n";
		cout << "Is data sorted: " << (is_sorted(arr) ? "Yes" : "No") << "\n";
	}
	exec(arr, "std::sort", sort);
	//exec(arr, "std::qsort", qsort);
	exec(arr, "quick_sort", quick_sort);
	exec(arr, "bubble_sort", bubble_sort);
	
	return 0;
}
