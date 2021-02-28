#include "sightings.h"

//Lucius Bossio
//Client code for bird watching club

//friend function
ostream& operator << (ostream& out, const Sightings* object)
{
	out << "Clube Name: " << object->clubName << endl << endl;
	return out;
}

int main()
{
	Sightings* ptr = new Sightings("SLC Bird Watchers");
	assert(ptr);

	//friend function
	cout << ptr;

	ptr->insertSightings();
	ptr->insertSightings();
	ptr->insertSightings();
	ptr->insertSightings();
	ptr->insertSightings();
	ptr->showBirds(cout);

	ptr->removeSightings("", "");
	ptr->showBirds(cout);
	ptr->removeSightings("a", "area");
	ptr->showBirds(cout);
	ptr->removeSightings("c", "area3");
	ptr->showBirds(cout);
	ptr->removeSightings("b", "area2");
	ptr->showBirds(cout);
	ptr->removeSightings("d", "area4");
	ptr->showBirds(cout);

	delete(ptr);
	
	cout << endl << endl << "Program completed successfully." << endl;
	system("pause");
}

/*Output
Enter bird type:
Invalid entry. Enter a bird type: d

Enter bird quantity: d
Invalid entry. Enter a quantity between 0 and 100: 1

Enter bird Area:
Invalid entry. Enter the area: area4

Enter bird type: d

Enter bird quantity: 1

Enter bird Area: area4

d entry already exists in area4. 1 sighting(s) added to existing record.

Enter bird type: c

Enter bird quantity: 1

Enter bird Area: area3

Enter bird type: b

Enter bird quantity: 1

Enter bird Area: area2

Enter bird type: a

Enter bird quantity: 1

Enter bird Area: area


Club Name: SLC Bird Watchers
Bird Type       # of Sightings          Area of Sighting

a                            1          area
b                            1          area2
c                            1          area3
d                            2          area4

There are 4 sightings


DEFAULT in DEFAULT not found.


Club Name: SLC Bird Watchers
Bird Type       # of Sightings          Area of Sighting

a                            1          area
b                            1          area2
c                            1          area3
d                            2          area4

There are 4 sightings


a in area found and successfully removed.


Club Name: SLC Bird Watchers
Bird Type       # of Sightings          Area of Sighting

b                            1          area2
c                            1          area3
d                            2          area4

There are 3 sightings


c in area3 found and successfully removed.


Club Name: SLC Bird Watchers
Bird Type       # of Sightings          Area of Sighting

b                            1          area2
d                            2          area4

There are 2 sightings


b in area2 found and successfully removed.


Club Name: SLC Bird Watchers
Bird Type       # of Sightings          Area of Sighting

d                            2          area4

There are 1 sightings


d in area4 found and successfully removed.


No birds to display.


Program completed successfully.
Press any key to continue . . .
*/