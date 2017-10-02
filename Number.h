#ifndef NUMBER_H
#define NUMBER_H
class Atom;
class Variable;
class Number{
public:
	Number(int d);
	string symbol();
	string value();
	bool match(Number num);
	bool match(Atom atom);
	bool match(Var &vari);
private:
	string _value;
	string _symbol;
};

#endif
