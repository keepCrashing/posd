#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
using namespace std;
const double epsilon = 0.000001;
/*TEST (A,A){
	Rectangle rect1(0, 0, 7, 8);//30
	Rectangle rect2(0, 0, 1, 2);//6
	Rectangle rect3(0, 0, 3, 4);//14
	Rectangle rect4(0, 0, 5, 6);//22
	vector<Shape *> shapes;
  	shapes.push_back(&rect1);
  	shapes.push_back(&rect2);
  	shapes.push_back(&rect3);
	shapes.push_back(&rect4);
	/*sortByDecreasingPerimeter(shapes);
	ASSERT_NEAR(30, shapes[0]->perimeter(), epsilon);
	ASSERT_NEAR(22, shapes[1]->perimeter(), epsilon);
	ASSERT_NEAR(14, shapes[2]->perimeter(), epsilon);
	ASSERT_NEAR(6, shapes[3]->perimeter(), epsilon);
}
TEST (B,B){
	Rectangle rect(0, 0, 8, 9);
	ASSERT_NEAR(34, rect.perimeter(), epsilon);
}
TEST (C,C){
  Circle cir(2, 7, 11);
  Rectangle rect(3, 8, 12, 21);
  Triangle tri({1, 1}, {3, 1}, {3, 4});

  std::vector<Shape *> shapes;
  shapes.push_back(&cir);
  shapes.push_back(&rect);
  shapes.push_back(&tri);
  
  ASSERT_NEAR(143.7205896, sumOfPerimeter(shapes), epsilon);	
}*/
TEST (Sort, sortByIncreasingPerimeter) {
	Rectangle rect1(0, 0, 7, 8,"rect1");//30
	Rectangle rect2(0, 0, 1, 2,"rect2");//6
	Rectangle rect3(0, 0, 3, 4,"rect3");//14
	Rectangle rect4(0, 0, 5, 6,"rect4");//22
	Circle cir1(2, 7, 1,"cir1");//2*3.14 =6.28
	Triangle tri1({0, 0}, {8, 0}, {8, 6},"tri1");//24
	list<Shape *> listShapes;
  	listShapes.push_back(&rect1);
	listShapes.push_back(&rect2);
	listShapes.push_back(&rect3);
	listShapes.push_back(&rect4);
	listShapes.push_back(&cir1);
	listShapes.push_back(&tri1);
	Sort::sortByIncreasingPerimeter(&listShapes);
	auto it1 = listShapes.begin();
	ASSERT_EQ("rect2", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("cir1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect3", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect4", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("tri1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect1", (*it1)->getShapeName());
}

TEST (Sort, sortByDecreasingPerimeter) {
	Rectangle rect1(0, 0, 7, 8,"rect1");//30
	Rectangle rect2(0, 0, 1, 2,"rect2");//6
	Rectangle rect3(0, 0, 3, 4,"rect3");//14
	Rectangle rect4(0, 0, 5, 6,"rect4");//22
	Circle cir1(2, 7, 1,"cir1");//2*3.14
	Triangle tri1({0, 0}, {8, 0}, {8, 6},"tri1");//24
	list<Shape *> listShapes;
  	listShapes.push_back(&rect1);
	listShapes.push_back(&rect2);
	listShapes.push_back(&rect3);
	listShapes.push_back(&rect4);
	listShapes.push_back(&cir1);
	listShapes.push_back(&tri1);
	Sort::sortByDecreasingPerimeter(&listShapes);
	auto it1 = listShapes.begin();
	ASSERT_EQ("rect1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("tri1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect4", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect3", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("cir1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect2", (*it1)->getShapeName());
}

TEST (Sort, sortByIncreasingArea) {
	Rectangle rect1(0, 0, 7, 8,"rect1");//56
	Rectangle rect2(0, 0, 1, 2,"rect2");//2
	Rectangle rect3(0, 0, 3, 4,"rect3");//12
	Rectangle rect4(0, 0, 5, 6,"rect4");//30
	Circle cir1(2, 7, 1,"cir1");//1*3.14
	Triangle tri1({0, 0}, {8, 0}, {8, 6},"tri1");//24
	list<Shape *> listShapes;
  	listShapes.push_back(&rect1);
	listShapes.push_back(&rect2);
	listShapes.push_back(&rect3);
	listShapes.push_back(&rect4);
	listShapes.push_back(&cir1);
	listShapes.push_back(&tri1);
	Sort::sortByIncreasingArea(&listShapes);
	auto it1 = listShapes.begin();
	ASSERT_EQ("rect2", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("cir1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect3", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("tri1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect4", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect1", (*it1)->getShapeName());
}

TEST (Sort, sortByDecreasingArea) {
	Rectangle rect1(0, 0, 7, 8,"rect1");//56
	Rectangle rect2(0, 0, 1, 2,"rect2");//2
	Rectangle rect3(0, 0, 3, 4,"rect3");//12
	Rectangle rect4(0, 0, 5, 6,"rect4");//30
	Circle cir1(2, 7, 1,"cir1");//1*3.14
	Triangle tri1({0, 0}, {8, 0}, {8, 6},"tri1");//24
	list<Shape *> listShapes;
  	listShapes.push_back(&rect1);
	listShapes.push_back(&rect2);
	listShapes.push_back(&rect3);
	listShapes.push_back(&rect4);
	listShapes.push_back(&cir1);
	listShapes.push_back(&tri1);
	Sort::sortByDecreasingArea(&listShapes);
	auto it1 = listShapes.begin();
	ASSERT_EQ("rect1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect4", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("tri1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect3", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("cir1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect2", (*it1)->getShapeName());

}

TEST (Sort, sortByIncreasingCompactness) {
	Rectangle rect1(0, 0, 7, 8,"rect1");// 56/30=1.86666667
	Rectangle rect2(0, 0, 1, 2,"rect2");// 2/6=0.3333333333
	Rectangle rect3(0, 0, 3, 4,"rect3");// 12/14=0.8
	Rectangle rect4(0, 0, 5, 6,"rect4");// 30/22=1.36363636
	Circle cir1(2, 7, 1,"cir1");// 3.14/6.28
	Triangle tri1({0, 0}, {8, 0}, {8, 6},"tri1");// 24/24=1
	list<Shape *> listShapes;
  	listShapes.push_back(&rect1);
	listShapes.push_back(&rect2);
	listShapes.push_back(&rect3);
	listShapes.push_back(&rect4);
	listShapes.push_back(&cir1);
	listShapes.push_back(&tri1);
	Sort::sortByIncreasingCompactness(&listShapes);
	auto it1 = listShapes.begin();
	ASSERT_EQ("rect2", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("cir1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect3", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("tri1", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect4", (*it1)->getShapeName());
	it1++;
	ASSERT_EQ("rect1", (*it1)->getShapeName());
}

#endif
