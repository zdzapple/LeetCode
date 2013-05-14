#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T> 
bool compare_small(const T& left, const T& right)
{
     if (left < right)
        return true;
     else 
         return false;
}

template <class T>
class Heap
{
private:
	vector<T> data;
	typedef bool (*COMP_FUNC) (const T&, const T&);
	COMP_FUNC comp;

public:
	Heap(vector<T> numbers, COMP_FUNC compare_function = NULL) : comp(compare_function)
	{
		typename vector<T>::iterator it ;
        for (it = numbers.begin(); it != numbers.end(); ++ it)
			data.push_back(*it);
		if (NULL == comp)
            make_heap(data.begin(), data.end()); 
		else
			make_heap(data.begin(), data.end(), comp);
	}
	
	void add(const T& item)
	{
		data.push_back(item);
		if (NULL == comp)
            push_heap(data.begin(), data.end()); 
		else
			push_heap(data.begin(), data.end(), comp);
	}
	
	T extract()
	{
		if (comp == NULL)
			pop_heap(data.begin(), data.end());
		else
			pop_heap(data.begin(), data.end(), comp);
		T removed = data.back();
		data.pop_back();
		return removed;
	}
	
	bool isEmpty() const
	{
		return data.empty();
	}
	
	void clear()
	{
		data.clear();
	}
};

template <class T>
class MyHeap
{
private:
	vector<T> data;
	typedef bool (*COMP_FUNC) (const T&, const T&);
	COMP_FUNC comp;
    
    // note: the index begin at 0, so left()/right()/parent() is different from CRLS 
	int left(int i) { return ((i + 1) << 1) - 1;} // note: brackets
	int right(int i) { return (i + 1) << 1;}
	int parent(int i) { if (i > 0) return (i - 1) >> 1; else return 0;}
	
    void makeHeap(int i)
	{
		// leftTree and rightTree are heap
		int l = left(i);
		int r = right(i);
		int largest;
		if (l <= data.size() - 1 && comp(data[l], data[i]))
			largest = l;
		else
			largest = i;
		if (r <= data.size() - 1 && comp(data[r], data[largest]))
			largest = r;
	//	cout << largest << endl;
		if (largest != i) {
			T temp = data[i];
			data[i] = data[largest];
			data[largest] = temp;
			makeHeap(largest);
		}
	}
     

public:
	MyHeap(vector<T> numbers, COMP_FUNC compare_function = NULL) : comp(compare_function)
	{
		typename vector<T>::iterator it ;
        for (it = numbers.begin(); it != numbers.end(); ++ it)
			data.push_back(*it);
	    if (data.size() != 0)
    		for (int i = (data.size()) / 2; i >= 0; i --)
    			makeHeap(i);
    //  for (it = data.begin(); it != data.end(); ++ it)
//            cout << (*it) << endl;
		
	}
	
	void add(const T& item)
	{
		data.push_back(item);
		int i = data.size() - 1;
		while (i > 0 && !comp(data[parent(i)], data[i])) {
			T temp = data[parent(i)];
			data[parent(i)] = data[i];
			data[i] = temp; 
			i = parent(i);
		}
	}
	
	T extract()
	{
		T removed = data.front();
		data[0] = data.back();
		data.pop_back();
		makeHeap(0);
		return removed;
	}
	
	bool isEmpty() const
	{
		return data.empty();
	}
	
	void clear()
	{
		data.clear();
	}
};

int main()
{
	vector<int> vec;
	//vec.push_back(34);
//	vec.push_back(3);
//	vec.push_back(13);
//	vec.push_back(9);
//	vec.push_back(27);
//    vec.push_back(0);    
//	MyHeap<int> iMaxHeap(vec, compare_small<int>); 

    MyHeap<int> iMaxHeap(vec, compare_small<int>);
    iMaxHeap.add(34);
    iMaxHeap.add(3);
    iMaxHeap.add(13);
    iMaxHeap.add(9);
    iMaxHeap.add(27);
     iMaxHeap.add(0);

	while(!iMaxHeap.isEmpty())
	{
		cout << "extract >> " << iMaxHeap.extract() << endl;
	}


	
	cout << endl << endl;
	system("pause");
}
