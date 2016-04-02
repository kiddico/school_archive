// Nick Chirico
// 3/18/16

// implementation basic hashmap (unordered container)
// Mikhail Nesterenko: mostly lifted from Proc C++
// 4/15/2014

#include <vector>
#include <list>
#include <stdexcept>
#include <functional>

using std::string;
using std::vector;
using std::list;
using std::pair;
using std::make_pair;

//////////////////////////////////////////
// hash function implemented as a class
//////////////////////////////////////////


const size_t defaultNumBuckets = 101; // default number of buckets in the hash

// any Hash Class must provide 
// two methods: hash() and numBuckets().
template <typename T>
class DefaultHash {
public:
	DefaultHash(size_t numBuckets = defaultNumBuckets);
	size_t hash(const T& key) const;
	size_t numBuckets() const { return numBuckets_; }
	void setNumBuckets(size_t n);
protected:
	size_t numBuckets_;
};

template <typename T>
void DefaultHash<T>::setNumBuckets(size_t n){
	numBuckets_=n;
}

template <typename T>
DefaultHash<T>::DefaultHash(size_t numBuckets) {
	// if incorrect num of buckets, make default
	if (numBuckets <= 0) 
		numBuckets = defaultNumBuckets;
	numBuckets_ = numBuckets;
}

// Uses the division method for hashing.
// Treats the key as a sequence of bytes, sums the ASCII
// values of the bytes, and mods the total by the number
// of buckets.
template <typename T>
size_t DefaultHash<T>::hash(const T& key) const {
	size_t bytes = sizeof(key);
	size_t res = 0;
	for (size_t i = 0; i < bytes; ++i) {
		unsigned char b = *((unsigned char*)&key + i);
		res += b;
	}
	return res % numBuckets_;
}

////////////////////////////////////////////////
// container class
////////////////////////////////////////////////

template <typename Key, typename Value, 
			 typename Compare = std::equal_to<Key>,
			 typename Hash = DefaultHash<Key> >
class hashmap{

public:
	typedef Key key_type;
	typedef pair<const Key, Value> element_type;

	// constructor
	// number of buckets.
	hashmap(const Compare& comp = Compare(), 
		const Hash& hash = Hash());

	// destructor, copy constructor, move constructor,
	// copy assignment operator and move assignment operator
	~hashmap();
	hashmap(const hashmap<Key, Value, Compare, Hash>& src);
	hashmap(hashmap<Key, Value, Compare, Hash>&& src);			 // C++11

	hashmap<Key, Value, Compare, Hash>& operator=(const hashmap<
						Key, Value, Compare, Hash> rhs);
	hashmap<Key, Value, Compare, Hash>& operator=(hashmap<
						Key, Value, Compare, Hash>&& rhs); 
														 // C++11
	// swap with usual semantics
	void swap(hashmap<Key, Value, Compare, Hash> &rhs);

	// inserts the key/value pair x
	//void insert(const element_type& x);
	std::pair< typename hashmap<Key,Value, Compare,Hash>::element_type*, bool> insert(const element_type& x);

	// removes the element with key x, if it exists
	typename hashmap<Key,Value, Compare,Hash>::element_type* erase(const key_type& x);

	// find returns a pointer to the element with key x.
	// Returns nullptr if no element with that key exists.
	element_type* find(const key_type& x);

	// operator[] finds the element with key x or inserts an
	// element with that key if none exists yet. Returns a reference to
	// the value corresponding to that key.
	Value& operator[] (const key_type& x);

	void rehash(size_t n);
protected:

	// helper function for various searches
	typename list<pair<const Key, Value> >::iterator
		  findElement(const key_type& x, 
			 const size_t bucket) const;
	size_t size_;
	Compare comp_;
	Hash hash_;


	typedef list<element_type> ListType;

	// pointer to a vector is used to swap() 
	// can be implemented
	// in constant time
	vector<ListType>* elems_;

};


//
// constructors/destructors
//

// Construct elems_ with the number of buckets.
template <typename Key, typename Value, typename Compare, typename Hash>
	hashmap<Key, Value, Compare, Hash>::hashmap(
	const Compare& comp, const Hash& hash):
	size_(0), comp_(comp), hash_(hash) {
		elems_ = new vector<ListType>(hash_.numBuckets());
}

template <typename Key, typename Value, typename Compare, typename Hash>
		hashmap<Key, Value, Compare, Hash>::~hashmap() {
	delete elems_;
	elems_ = nullptr;
	size_ = 0;
}

template <typename Key, typename Value, typename Compare, typename Hash>
	hashmap<Key, Value, Compare, Hash>::
	hashmap(const hashmap< Key, Value, Compare, Hash>& src) :
	size_(src.size_), comp_(src.comp_), hash_(src.hash_) {
		// Don't need to bother checking if numBuckets is positive, because
		// we know src checked.

		// Use the vector copy constructor
		elems_ = new vector<ListType>(*(src.elems_));
	}


// swap function
template <typename Key, typename Value, typename Compare, typename Hash>
	void hashmap<Key, Value, Compare, Hash>::swap(hashmap<Key, Value, Compare, Hash> &rhs){
	std::swap(elems_, rhs.elems_);
	std::swap(size_, rhs.size_);
	std::swap(comp_, rhs.comp_);
	std::swap(hash_, rhs.hash_);
}


// C++11 move constructor
template <typename Key, typename Value, typename Compare, typename Hash>
	 hashmap<Key, Value, Compare, Hash>::hashmap(hashmap<Key, Value, Compare, Hash>&& src) {
	elems_ = src.elems_; src.elems_ = nullptr;
	size_ = src.size_; src.size_ =0;
	comp_ = src.comp_; 
	hash_ = src.hash_;
}

// overloaded assingment, copy-and-swap implementation
template <typename Key, typename Value, typename Compare, typename Hash>
	hashmap<Key, Value, Compare, Hash>& hashmap<Key, Value, Compare, Hash>::operator=(
	hashmap<Key, Value, Compare, Hash> rhs) {
	swap(rhs);
	return *this;
}

// C++11 move assignment operator
template <typename Key, typename Value, typename Compare, typename Hash>
	hashmap<Key, Value, Compare, Hash>& hashmap<Key, Value, Compare, Hash>::operator=(
	  hashmap<Key, Value, Compare, Hash>&& rhs) {
		// check for self-assignment
		if (this != &rhs) {
	 delete elems_;

	 // move ownership
	 elems_ = rhs.elems_;
	 rhs.elems_ = nullptr;
	 size_ = rhs.size_;
	 rhs.size_ = 0;
	 comp_ = rhs.comp_;
	 hash_ = rhs.hash_;
		}
		return *this;
	}


//
// rest of container member functions
// 

// helper function
template <typename Key, typename Value, 
			 typename Compare, typename Hash>
	typename list<pair<const Key, Value> >::iterator

	hashmap<Key, Value, Compare, Hash>::findElement(const key_type& x, const size_t bucket) const {

	// look for the key in the bucket
	for (auto it =  (*elems_)[bucket].begin();
		  it != (*elems_)[bucket].end(); ++it)
		if (comp_(it->first, x)){
	 return it;
		}

	return (*elems_)[bucket].end(); // element not found
}


template <typename Key, typename Value, typename Compare, typename Hash>
	 typename hashmap<Key, Value, Compare, Hash>::element_type*
	 hashmap<Key, Value, Compare, Hash>::find(const key_type& x) {

	size_t bucket = hash_.hash(x);
	auto it=findElement(x, bucket);	  // Use the findElement() helper	

	if (it == (*elems_)[bucket].end())
		// we didn't find the element -- return nullptr
		return nullptr;

	// We found the element. Return a pointer to it.
	return &(*it);
}


template <typename Key, typename Value, typename Compare, typename Hash>
	std::pair< typename hashmap<Key,Value, Compare,Hash>::element_type*, bool>
	hashmap<Key, Value, Compare, Hash>::insert(const element_type& x) {

	size_t bucket = hash_.hash(x.first);	
	auto it = findElement(x.first, bucket);	 // Try to find the element

	if (it != (*elems_)[bucket].end()) {
		// The element already exists
		return std::make_pair(&(*it),false);
	} else {
		// We didn't find the element, so insert a new one.
		size_++;
		(*elems_)[bucket].insert((*elems_)[bucket].end(), x);
		return std::make_pair(&(*((*elems_)[bucket].end())),true);
	}
}


template <typename Key, typename Value, typename Compare, typename Hash>
	Value& hashmap<Key, Value, Compare, Hash>::operator[] (const key_type& x) {
	// Try to find the element. If it doesn't exist, add a new element.
	element_type* found = find(x);
	if (found == nullptr) {
		insert(make_pair(x, Value()));
		found = find(x);
	}
	return found->second;
}

template <typename Key, typename Value, typename Compare, typename Hash>
	typename hashmap<Key,Value, Compare,Hash>::element_type* hashmap<Key, Value, Compare, Hash>::erase(const key_type& x) {


	size_t bucket = hash_.hash(x);
	auto it = findElement(x, bucket);	  // First, try to find the element

	if (it != (*elems_)[bucket].end()) {
	 // The element exists -- erase it
	 size_--;
	it=(*elems_)[bucket].erase(it);
	if (it == (*elems_)[bucket].end()) {
		if( (*elems_)[++bucket].size() == 0 )
			while( (*elems_)[++bucket].size() == 0 && bucket != hash_.numBuckets() ){};
		if( bucket != hash_.numBuckets() ){
			auto it2 = (*elems_)[bucket].begin();
			return &(*it2);
		}
		//return nullptr;
		// not sure what to do if there's no object in the lists after the one we remove.
		for(int i = 0; i < hash_.hash(x); ++i ){
			if( (*elems_)[i].size()!=0 ){
				auto it2 = (*elems_)[i].begin();
				return &(*it2);
			}
		}
	}
	else
		return &(*it);
	}
	return nullptr;
}


template <typename Key, typename Value, typename Compare, typename Hash>
void hashmap<Key, Value, Compare, Hash>::rehash(size_t n ){
	// make a new hashmap, and set it's bucket count
	auto new_guy = hashmap<Key,Value,Compare,Hash>();
	new_guy.hash_.setNumBuckets(n);
	// insert each element into the new guy
	for( auto element: *elems_)
		for( auto element_pair: element )
			new_guy.insert(element_pair);

	swap(new_guy); // swap with old stuff, and go home
}
