#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
using namespace std;

//Lucius Bossio
//Specification file for Sightings class and Bird struct

struct Bird
{
	string birdType;
	int birdCount;
	string area;
	Bird* linkBird;
};

class Sightings
{
private:
	Bird* firstPtr;
	string clubName;
	int noSightings;
public:
	Sightings(string /*clubName*/);
	~Sightings();
	void showBirds(ostream& /*output or output file*/) const;
	void insertSightings();
	void removeSightings(string /*birdType*/, string /*area*/);
	int getNoSightings() const { return noSightings; }
	string getClubName() const { return clubName; }

	//friend function
	friend ostream& operator << (ostream&, const Sightings*);
};
