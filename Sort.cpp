#include "include/Sort.h"
#include <iostream>
#include <list>
void Sort::sortByIncreasingPerimeter(std::list<Shape *> * shapeList)
{
	int length = shapeList->size();
    	auto it2 = shapeList->begin();
    	auto it1 = shapeList->begin();
	for(int i = 0; i < length-1; i++){
		for(int j = 0; j < length-1-i; j++){
			std::advance(it1, j);
			std::advance(it2, j+1);
			//std::cout<<j<<std::endl;
			//std::cout<<(*it1)->perimeter()<<std::endl;
			//std::cout<<(*it2)->perimeter()<<std::endl;
			//std::cout<<std::endl;
			if ((*it1)->perimeter() > (*it2)->perimeter()){
				std::swap(*it1, *it2);
			}
			it1 = shapeList->begin();
			it2 = shapeList->begin();

		}
	}
}
void Sort::sortByDecreasingPerimeter(std::list<Shape *> * shapeList)
{
	int length = shapeList->size();
	auto it2 = shapeList->begin();    
	auto it1 = shapeList->begin();
	for(int i = 0; i < length-1; i++){
		for(int j = 0; j < length-1-i; j++){
			std::advance(it1, j);
			std::advance(it2, j+1);
			//std::cout<<j<<std::endl;
			//std::cout<<(*it1)->perimeter()<<std::endl;
			//std::cout<<(*it2)->perimeter()<<std::endl;
			//std::cout<<std::endl;
			if ((*it1)->perimeter() < (*it2)->perimeter()){
				std::swap(*it1, *it2);
			}
			it1 = shapeList->begin();
			it2 = shapeList->begin();

		}
	}
}
void Sort::sortByIncreasingArea(std::list<Shape *> * shapeList)
{
    int length = shapeList->size();
    Shape *temp;
    auto it2 = shapeList->begin();
    auto it1 = shapeList->begin();
    //std::advance(it2, 0);
	//std::cout << (*it1)->area() << std::endl;
	//std::cout << (*it2)->area() << std::endl;
	for(int i = 0; i < length-1; i++){
		for(int j = 0; j < length-1-i; j++){
			std::advance(it1, j);
			std::advance(it2, j+1);
			//std::cout<<j<<std::endl;
			//std::cout<<(*it1)->area()<<std::endl;
			//std::cout<<(*it2)->area()<<std::endl;
			//std::cout<<std::endl;
			if ((*it1)->area() > (*it2)->area()){
				std::swap(*it1, *it2);
			}
			it1 = shapeList->begin();
			it2 = shapeList->begin();

		}
	}
}
void Sort::sortByDecreasingArea(std::list<Shape *> * shapeList)
{
	int length = shapeList->size();
	auto it2 = shapeList->begin();
	auto it1 = shapeList->begin();
	for(int i = 0; i < length-1; i++){
		for(int j = 0; j < length-1-i; j++){
			std::advance(it1, j);
			std::advance(it2, j+1);
			//std::cout<<j<<std::endl;
			//std::cout<<(*it1)->area()<<std::endl;
			//std::cout<<(*it2)->area()<<std::endl;
			//std::cout<<std::endl;
			if ((*it1)->area() < (*it2)->area()){
				std::swap(*it1, *it2);
			}
			it1 = shapeList->begin();
			it2 = shapeList->begin();

		}
	}
}
void Sort::sortByIncreasingCompactness(std::list<Shape *> * shapeList)
{
// Compactness = area/perimeter
    	int length = shapeList->size();
    	auto it2 = shapeList->begin();
    	auto it1 = shapeList->begin();
	for(int i = 0; i < length-1; i++){
		for(int j = 0; j < length-1-i; j++){
			std::advance(it1, j);
			std::advance(it2, j+1);
			//std::cout<<j<<std::endl;
			//std::cout<<(*it1)->perimeter()<<std::endl;
			//std::cout<<(*it2)->perimeter()<<std::endl;
			//std::cout<<std::endl;
			if (((*it1)->area()/(*it1)->perimeter()) > ((*it2)->area()/(*it2)->perimeter())){
				std::swap(*it1, *it2);
			}
			it1 = shapeList->begin();
			it2 = shapeList->begin();

		}
	}
}
