#ifndef WORDOCCURENCE
#define WORDOCCURENCE

#include <string>
class WordOccurrence {
	public:
	    WordOccurrence(const std::string& word="", int num=0):word_(word),num_(num){};
		// returns true if word matches stored
		bool matchWord(const std::string &); 
		// increments number of occurrences
		void increment(); 
		std::string getWord() const; 
		int getNum() const;
		bool operator==(const WordOccurrence &);
		void swapValues(WordOccurrence &);

	private:
		std::string word_;
		int num_;
};

#endif
