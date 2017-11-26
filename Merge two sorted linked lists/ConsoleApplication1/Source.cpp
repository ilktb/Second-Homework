#include<iostream>

using namespace std;

template<typename T>
struct node
{
	T inf;
	node<T>* link;
};

template<typename T>
class LList
{
private:
	node<T>* start;
	node<T>* end;
	node<T>* cur;

	void DeleteLList();
	void CopyLList(LList const &);

public:
	LList();
	LList(LList const &);
	LList& operator=(LList const &);
	~LList();

	void IterStart(node<T>* p = NULL);
	node<T>* Iter();

	void InsertAfter(node<T>*, T const &);
	void InsertBefore(node<T>*, T const &);
	bool DeleteAfter(node<T>*, T &);
	void DeleteElem(node<T>*, T &);
	bool DeleteBefore(node<T>*, T &);
	void ToEnd(T const &);
	int length();
	void concat(LList<T> const&);
	void sortConcat();
	void print();
};

template <typename T>
LList<T>::LList() {
	start = NULL;
	end = NULL;
}

template <typename T>
LList<T>::LList(LList const & list) {
	CopyLList(list);
}

template <typename T>
LList<T>& LList<T>::operator=(LList const & list) {
	if (this != &list) 	{
		DeleteLList();
		CopyLList(list);
	}
	return *this;
}

template <typename T>
LList<T>::~LList() {
	DeleteLList();
}


template <typename T>
void LList<T>::DeleteLList() {
	node<T>* p;
	while (start) {
		p = start;
		start = start->link;
		delete p;
	}
	end = NULL;
}

template <typename T>
void LList<T>::CopyLList(LList const & list) {
	start = end = NULL;
	if (list.start) {
		node<T> *p = list.start;
		while (p)  	{
			ToEnd(p->inf);
			p = p->link;
		}
	}
}

template <typename T>
node<T>* LList<T>::Iter() {
	node<T> *p = cur;
	if (cur) cur = cur->link;
	return p;
}

template <typename T>
void LList<T>::IterStart(node<T> *p) {
	if (p) cur = p;
	else cur = start;
}

template <typename T>
void LList<T>::InsertAfter(node<T> *p, T const & x) {
	node<T> *q = new node<T>;
	q->inf = x;
	q->link = p->link;
	if (p == end) end = q;
	p->link = q;
}

template <typename T>
void LList<T>::InsertBefore(node<T> *p, T const & x) {
	node<T> *q = new node<T>;
	*q = *p;
	if (p == end) end = q;
	p->inf = x;
	p->link = q;
}

template <typename T>
bool LList<T>::DeleteAfter(node<T> *p, T & x) {
	if (p->link)
	{
		node<T> *q = p->link;
		x = q->inf;
		p->link = q->link;
		if (q == end) end = p;
		delete q;
		return 1;
	}
	return 0;
}

template <typename T>
void LList<T>::DeleteElem(node<T> *p, T & x) {
	if (p == start) {
		x = p->inf;
		if (start == end) 	{
			start = end = NULL;
		}
		else start = start->link;
		delete p;
	}
	else {
		node<T> *q = start;
		while (q->link != p) q = q->link;
		DeleteAfter(q, x);
	}
}

template <typename T>
bool LList<T>::DeleteBefore(node<T> *p, T & x) {
	if (p != start)	{
		node<T> *q = start;
		while (q->link != p) q = q->link;
		DeleteElem(q, x);
		return 1;
	}
	return 0;
}

template <typename T>
void LList<T>::ToEnd(T const & x) {
	cur = end;
	end = new node<T>;
	end->inf = x;
	end->link = NULL;
	if (cur) cur->link = end;
	else start = end;
}

template <typename T>
void LList<T>::print() {
	node<T>* p = start;
	while (p) {
		cout << p->inf << " ";
		p = p->link;
	}
	cout << endl;
}

template <typename T>
int LList<T>::length() {
	int n = 0;
	IterStart();
	node<T> *p = Iter();
	while (p) {
		n++;
		p = Iter();
	}
	return n;
}

template <typename T>
void LList<T>::concat(LList<T> const & list) {
	node<T> *p = list.start;
	while (p) {
		ToEnd(p->inf);
		p = p->link;
	}
}

template <typename T>
void LList<T>::sortConcat() {
	node<T> *minPtr = nullptr, *cur, *next = nullptr;
	T minValue;
	IterStart();
	cur = Iter();

	while (cur->link) {
		minValue = cur->inf;
		minPtr = cur;
		next = cur->link;
		
		while (next) {
			if (next->inf < minValue) {
				minPtr = next;
				minValue = next->inf;
			}
			next = next->link;
		}

		if (minPtr != cur)	{
			minPtr->inf = cur->inf;
			cur->inf = minValue;
		}

		cur = cur->link;
	}
}

int main()
{
	
	return 0;
}