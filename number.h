#ifndef NUMBER_H
#define NUMBER_H
class Atom;
class Variable;
class Number:public Term{
public:
	Number(double d);
	string symbol()const;
	//bool match(Term &term);
	//string value();
	//bool match(Number num);
	//bool match(Atom atom);
	//bool match(Variable &vari);
private:
	string _value;
	string _symbol;
};

#endif
