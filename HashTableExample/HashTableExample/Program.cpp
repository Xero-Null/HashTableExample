#include "Hash.h"

using namespace std;

int main()
{
	People
		*person1 = new People("Fred", "Brown"),
		*person2 = new People("Fred", "Blond"),
		*person3 = new People("Sam", "Blond"),
		*person4 = new People("Ed", "Red"),
		*person5 = new People("Clark", "Pink"),
		*person6 = new People("Janet", "Blond"),
		*person7 = new People("Simon", "Blond"),
		*person8 = new People("Jessica", "Black"),
		*person9 = new People("Christina", "Blond"),
		*person10 = new People("Ashley", "Brown");

	People *people[10] = {
							person1,
							person2,
							person3,
							person4,
							person5,
							person6,
							person7,
							person8,
							person9,
							person10
						};

	Hash hashTable(sizeof(people));

	for (int i = 0; i < sizeof(hashTable); i++)
	{
		hashTable.Insert(people[i]->name, people[i]);
	}

	hashTable.DisplayHashContents();

	cout << endl << "-- Get person from pointer test --" << endl;
	hashTable.GetPerson(person4);

	cout << endl << "-- Get person from name/hair test --" << endl;
	hashTable.GetPersonByNameAndHair("Fred", "Blond"); // person2

	cin.ignore();
}