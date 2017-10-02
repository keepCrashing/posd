#ifndef NUMBER_H
#define NUMBER_H
class Atom;
class Number{
public:
	Number(int d);
	string symbol();
	string value();
	bool match(Number num);
	bool match(Atom atom);
private:
	string _value;
	string _symbol;
};

#endif
