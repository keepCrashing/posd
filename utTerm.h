#ifndef UTTERM_H
#define UTTERM_H
#include "include/Atom.h"
#include "include/Number.h"
#include "include/Variable.h"
//#include "include/Variable.h"
//test Number.value()
TEST (Number,ctor) {
	Number _100(100);
	ASSERT_EQ("100",_100.value());
	//Number _100_4444(100.4445);
	//ASSERT_EQ("100.444",_100_4444.value());
}
//test Number.symbol()
TEST (Number, symbol) {
	Number _10000(10000);
	ASSERT_EQ("10000",_10000.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Number num1(25);
	Number num2(25);
	ASSERT_TRUE(num1.match(num2));

}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number num1(25);
	Number num2(0);
	ASSERT_FALSE(num1.match(num2));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Atom tom("tom");
	Number num1(25);
	ASSERT_FALSE(num1.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
  	Number num1(25);
  	Variable X("X");
  	ASSERT_TRUE(X.match(num1));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {


}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {

}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {

}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {

}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){

}
#endif
