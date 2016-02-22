

class String {
	public:
		String();
		String(const String&);
		~String();
		String operator= (String);
	private:
		char *ptr;
};
