#include "sightings.h"

//Lucius Bossio
//Implementation file for the Sightings class

Sightings::Sightings(string newClubName)
{
	clubName = (newClubName.length() == 0) ? "DEFAULT" : newClubName;
	noSightings = 0;
	firstPtr = NULL;
}

Sightings::~Sightings()
{
	Bird* walker = firstPtr;
	while (walker != NULL)
	{
		walker = walker->linkBird;
		delete firstPtr;
		firstPtr = walker;
	}
}

void Sightings::showBirds(ostream& out) const
{
	Bird* walker = firstPtr;
	if (firstPtr == NULL)
	{
		out << endl << "No birds to display." << endl;
	}
	else
	{
		out << endl << "Club Name: " << getClubName() << endl;

		out << left << setw(15) << "Bird Type" << right << setw(15) << "# of Sightings" << "\t\t" << left << setw(20) << "Area of Sighting" << endl << endl;
		while (walker != NULL)
		{
			out << left << setw(15) << walker->birdType << right << setw(15) << walker->birdCount << "\t\t" << left << setw(20) << walker->area << endl;
			walker = walker->linkBird;
		}

		out << endl << "There are " << getNoSightings() << " sightings" << endl << endl;
	}
}

void Sightings::insertSightings()
{
	Bird* builder = new Bird;
	assert(builder);
	
	cout << "Enter bird type: ";
	getline(cin, builder->birdType);
	while (builder->birdType.length() == 0)
	{
		cout << "Invalid entry. Enter a bird type: ";
		getline(cin, builder->birdType);
	}

	cout << endl << "Enter bird quantity: ";
	cin >> builder->birdCount;
	while (builder->birdCount < 0 || builder->birdCount > 100 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Invalid entry. Enter a quantity between 0 and 100: ";
		cin >> builder->birdCount;
	}
	
	cout << endl << "Enter bird Area: ";
	cin.ignore(80, '\n');
	getline(cin, builder->area);
	while (builder->area.length() == 0)
	{
		cout << "Invalid entry. Enter the area: ";
		getline(cin, builder->area);
	}
	cout << endl;
	
	Bird* walker = firstPtr;
	Bird* stalker = NULL;
	while (walker != NULL)
	{
		if (walker->birdType >= builder->birdType)
		{
			break;
		}
		stalker = walker;
		walker = walker->linkBird;
	}
		
	if (walker != NULL && builder->birdType == walker->birdType && builder->area == walker->area)
	{
		walker->birdCount += builder->birdCount;
		cout << builder-> birdType << " entry already exists in " << builder->area << ". " << builder->birdCount << " sighting(s) added to existing record." << endl << endl;
	}
	else
	{
		builder->linkBird = walker;
		if (walker == firstPtr)
		{
			firstPtr = builder;
		}
		else
		{
			stalker->linkBird = builder;
		}
		noSightings++;
	}
}

void Sightings::removeSightings(string removeBirdType, string removeArea)
{
	removeBirdType = (removeBirdType.length() == 0) ? "DEFAULT" : removeBirdType;
	removeArea = (removeArea.length() == 0) ? "DEFAULT" : removeArea;

	Bird* walker = firstPtr;
	Bird* stalker = NULL;
	if (firstPtr != NULL)
	{
		while (walker != NULL)
		{
			if (walker->birdType == removeBirdType && walker->area == removeArea)
			{
				break;
			}
			stalker = walker;
			walker = walker->linkBird;
		}
		if (walker == NULL)
		{
			cout << endl << removeBirdType << " in " << removeArea << " not found." << endl << endl;
		}
		else
		{
			if (firstPtr == walker)
			{
				firstPtr = walker->linkBird;
			}
			else
			{
				stalker->linkBird = walker->linkBird;
			}
			delete walker;
			noSightings--;
			cout << endl << removeBirdType << " in " << removeArea << " found and successfully removed." << endl << endl;
		}
	}
}