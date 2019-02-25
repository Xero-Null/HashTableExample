#pragma once

#include <string>
#include <list>
#include<iostream>
#include <iomanip>
#include <functional>

using namespace std;

struct People
{
	string
		name,
		hair;

	People(string n, string h) { this->name = n; this->hair = h; }
};

class Hash
{
	int tableSize;
	list<People*> *hashTable;

public:
	Hash(int tSize);

	int GetHash(string name)
	{
		int sum = 0, index = 0;
		for (string::size_type i = 0; i < name.length(); i++)
		{
			sum += name[i];
		}
		index = sum % tableSize;
		return index;
	}

	void Insert(string name, People *person);
	void Remove(int key, People *person);
	void DisplayHashContents();

	People* GetPerson(People *person);
	People* GetPersonByNameAndHair(string name, string hair);
};