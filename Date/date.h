enum class Month{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date{
	public:
		class Invalid{};
		
		Date(int y, Month m, int d);
		Date();
		
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		void printLongForm();
		
		bool isvalid();
		bool isLeapYear();
		
		int day() const{return d;}
		int month() const{return int(m);}
		int year() const{return y;}
		
		friend istream& operator >> (istream& is, Date& d);
		
	private:
		int y, d;
		Month m;
		Vector<int> max_days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		Vector<int> max_days_leap{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

ostream& operator << (ostream& os, const Date& d);
bool operator==(const Date& left, const Date& right);
bool operator!=(const Date& left, const Date& right);
