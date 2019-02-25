#include "Hash.h"

Hash::Hash(int tSize)
{
	this->tableSize = tSize;
	hashTable = new list<People*>[tableSize];
}

void Hash::Insert(string name, People *person)
{
	int index = GetHash(name);
	hashTable[index].push_back(person);
}

void Hash::Remove(int key, People *person)
{
	int index = GetHash(person->name);
	list <People*> ::iterator i;
	for (i = hashTable[index].begin(); i != hashTable[index].end(); i++)
	{
		if (((*i)->name == person->name) && ((*i)->hair == person->hair))
		{
			break;
		}
	}

	if (i != hashTable[index].end())
	{
		hashTable[index].erase(i);
	}
}

void Hash::DisplayHashContents()
{
	for (int i = 0; i < tableSize; i++)
	{
		for (People *x : hashTable[i])
		{
			cout << "Array[" << i << "] has " << x->name << " with " << x->hair << " hair" << endl;
		}
	}
}

People* Hash::GetPerson(People *person)
{
	int index = GetHash(person->name);
	list <People*> ::iterator i;
	for (i = hashTable[index].begin(); i != hashTable[index].end(); i++)
	{
		cout << "Searching Array[" << index << "] for " << person->name << " with " << person->hair << " hair" << endl;
		if (((*i)->name == person->name) && ((*i)->hair == person->hair))
		{
			cout << "Found " << person->name << "!" << endl;
			return *i;
		}
		else
		{
			cout << "Current person is not " << person->name << "!" << endl;
		}
	}
	return NULL;
}

People* Hash::GetPersonByNameAndHair(string name, string hair)
{
	int index = GetHash(name);
	list <People*> ::iterator i;
	for (i = hashTable[index].begin(); i != hashTable[index].end(); i++)
	{
		cout << "Searching Array[" << index << "] for " << name << " with " << hair << " hair" << endl;
		if (((*i)->name == name) && ((*i)->hair == hair))
		{
			cout << "Found " << (*i)->name << "!" << endl;
			return *i;
		}
		else
		{
			cout << "Current person is not " << name << "!" << endl;
		}
	}
	return NULL;
}