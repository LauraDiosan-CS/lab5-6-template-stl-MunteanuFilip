#pragma once

#include <iostream>
#include<iterator>
#include <set>
using namespace std;

template <class T>
class Repo {
private:
	set<T> elem;
public:
	Repo<T>();
	Repo(const Repo<T>& repo);
	void addProdus(const T& el);
	void removeProdus(const T& el);
	void updateProdus(const T& el, const T& elNou);

	int find(const T& el);
	int getSize();

	set<T> getAll();
};

template<class T>
int Repo<T>::find(const T& el)
{
	return elem.find(el) != elem.end();
}

template<class T>
int Repo<T>::getSize()
{
	return elem.size();
}


template <class T> Repo<T>::Repo()
{
}

template<class T>
void Repo<T>::addProdus(const T& e)
{
	elem.insert(e);
}

template<class T>
void Repo<T>::removeProdus(const T& el)
{
	elem.erase(el);
}

template<class T>
void Repo<T>::updateProdus(const T& el, const T& elNou)
{
	elem.erase(el);
	elem.insert(elNou);
}



template<class T>
set<T> Repo<T>::getAll()
{
	return elem;
}

/*
template<class T>
int Repo<T>::find(const T &e)
{
	list<T>::iterator;
	iterator= find(elem.begin(), elem.end(), e);
	if (iterator != elem.end()) return distance(elem.begin(), iterator);
	return -1;
}
*/



template<class T>
Repo<T>::Repo(const Repo<T>& repo)
{
	elem = repo.elem;
}