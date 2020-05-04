#pragma once
#include"Repo.h"
#include <fstream>
#include <iostream>
#include <cstddef>


template <class T>
class RepoFile : public Repo<T>
{
private:
	char* filename;
public:
	RepoFile() : Repo<T>()
	{
		this->filename = NULL;
	};

	RepoFile(const char* filename)
	{
		this->filename = new char[strlen(filename) + 1];
		strcpy_s(this->filename, strlen(filename) + 1, filename);
		this->load_to_file();
	};

	~RepoFile()
	{
		delete[] this->filename;
	};

	RepoFile(const RepoFile& repo)
	{
		this->filename = new char[strlen(repo.filename) + 1];
		strcpy_s(this->filename, strlen(repo.filename) + 1, repo.filename);
		this->load_to_file();
	}

	int getSize()
	{
		return  Repo<T>::getSize();
	};

	void set_filename(const char* filename)
	{
		if (this->filename != NULL) {
			delete[] this->filename;
		}
		if (filename != NULL) {
			this->filename = new char[strlen(filename) + 1];
			strcpy_s(this->filename, strlen(filename) + 1, filename);
		}
		else
			this->filename = NULL;
	};

	void addProdus(T element) {
		Repo<T>::addProdus(element);
	};

	RepoFile<T>& operator=(const RepoFile<T>& repo)
	{
		this->set_filename(repo.filename);
		this->load_to_file();
		return *this;
	};

	void load_to_file()
	{
		if (this->filename != NULL)
		{
			ifstream f(this->filename);

			T elem;

			while (f >> elem)
			{
				Repo<T>::addProdus(elem);
			}

			f.close();
		}
		else
			Repo<T>::clear();
	};

	void save_to_file()
	{
		if (this->filename != NULL) {
			ofstream f(this->filename);
			int n = Repo<T>::getSize();
			for (int i = 0; i < n; i++)
				f << Repo<T>::getElement(i);
			f.close();
		}
	}


};