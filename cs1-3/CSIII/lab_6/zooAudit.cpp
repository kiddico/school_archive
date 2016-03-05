//Nick Chirico
// Mikhail Nesterenko
// 10/2/2015

#include <algorithm>
#include <functional>
#include <map>
using std::map;

#include <list>
using std::list;

#include <iostream> 
using std::cout; using std::endl;

#include <utility>
using std::pair;

#include <string>  
using std::string;

#include <set>
using std::set;


// this is same as typedef
using EnclosurePair = pair<const string, list<string>>;
using ZooMap = map<string, list<string>>;


// removes duplicate and sick animals form ZooMap
void auditEnclosures(ZooMap& animalsByEnclosure, const list<string>& sickAnimals);

// returns a list of duplicate animals
std::multimap<string,string> getDuplicates(const ZooMap& animalsByEnclosure);


int main() {
	// initialize map 
	ZooMap animals = {
	{ "Orange", { "aardvark", "lion", "buffalo", "wildcat", "lion", "eagle" } },
	{ "Green", { "elephant", "zebra", "aardvark", "bear"} },
	{ "Yellow", { "goose", "alligator", "flamingo" } },
	{ "Blue", { "shark", "dolphin", "alligator", "turtle", "eagle", "penguin"} },
	{ "Red",  { "deer", "duck", "wildcat", "lion" } }
	};

	list<string> sickAnimals = { "buffalo", "wildcat", "eagle"};

	list<string> extraAnimals = {"penguin", "bear"}; // this list is presently unused

	// local lambda expression to print a enclosure
	auto printEnclosure = [](const EnclosurePair& enclosure) {
	cout << enclosure.first << ":";
	for (auto& str : enclosure.second) {
	cout << ' ' << str;
	}
		cout << endl;
	};

	//getDuplicates(animals);
	
	cout << "Before audit:" << endl;
	for_each(animals.cbegin(), animals.cend(), printEnclosure);
	cout << endl;

	auditEnclosures(animals, sickAnimals);
	
	cout << "After audit:" << endl;
	for_each(animals.cbegin(), animals.cend(), printEnclosure);
	cout << endl;
	
}


void auditEnclosures(ZooMap& animalsByEnclosure, const list<string>& sickAnimals) {
	// get all the duplicate names
	std::multimap<string,string> toRemove = getDuplicates(animalsByEnclosure);

	// Remove all animals from the sick list
	for_each( animalsByEnclosure.begin(),animalsByEnclosure.end(),
				[&sickAnimals](EnclosurePair& enclosure){
					auto iter = remove_if( enclosure.second.begin(),enclosure.second.end(),
						[&sickAnimals]( const string& input ){
							return ( std::find( sickAnimals.begin(),sickAnimals.end(),input) != sickAnimals.end() );
						}
					);
					enclosure.second.erase(iter,enclosure.second.end());
				}
			);
	// Remove duplicate animals
	for_each( toRemove.begin(),toRemove.end(),
		[&animalsByEnclosure](std::pair<string,string> input){
			auto correct_enclosure = animalsByEnclosure.find(input.second);
			if( correct_enclosure != animalsByEnclosure.end() )
				correct_enclosure->second.remove( input.first );
		}
	);
}

// So I'm going to invert the map, so its <animal names, enclosure they're in>
// Once I have that I'll remove the first occurence of any animal, so we've still got one of each.
// then auditEnclosures can do with it as it pleases.
std::multimap<string,string> getDuplicates(const ZooMap& animalsByEnclosure) {
	list<string> animal_list;
	std::multimap<string,string> to_remove;

	// I'm going to add each animal to a list (which I'll later make unique)
	// And each animal / enclosure combo will be added to the mMap.
	for(auto& enclosure:animalsByEnclosure){
		for(auto& animal:enclosure.second){
			to_remove.insert(std::make_pair(string(animal),string(enclosure.first)));
			animal_list.push_back(string(animal));
		}
	}
	// Didn't know you needed to sort a list before you can make it unique
	animal_list.sort();
	animal_list.unique();

	// Now to remove one of each animal
	for( auto animal_name:animal_list ){
		to_remove.erase(to_remove.find(animal_name));
	}

	return to_remove;
}

