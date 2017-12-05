#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "number.h"
#include "iterator.h"
TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    // StructIterator it(&s);
    Iterator *itStruct = s.createIterator();
    // Iterator& itStruct = it;
    // ASSERT_EQ(it.first()->symbol());
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, nested_iterator) {
  Number one(1);
  Variable X("X");
  Variable Y("Y");
  Number two(2);
  Struct t(Atom("t"), { &X, &two });
  Struct s(Atom("s"), { &one, &t, &Y });
  Iterator *it = s.createIterator();
  it->first();
  it->next();
  Struct *s2 = dynamic_cast<Struct *>(it->currentItem());

  //StructIterator it2(s2);
  Iterator *it2 = s2->createIterator();

  it2->first();
  ASSERT_EQ("X", it2->currentItem()->symbol());
  ASSERT_FALSE(it2->isDone());
  it2->next();
  ASSERT_EQ("2", it2->currentItem()->symbol());
  ASSERT_FALSE(it2->isDone());
  it2->next();
  ASSERT_TRUE(it2->isDone());
}

TEST(iterator, firstList) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    ListIterator it(&l);
    Iterator* itList = &it;
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, NullIterator){
  Number one(1);
  NullIterator nullIterator(&one);
  nullIterator.first();
  ASSERT_TRUE(nullIterator.isDone());
  Iterator * it = one.createIterator();
  it->first();
  ASSERT_TRUE(it->isDone());
}
TEST(iterator, DFSIterator_Struct) {
    Variable X("X");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Iterator *itDFS = t.createDFSIterator();
    itDFS->first();
    ASSERT_EQ("X", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("2", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_TRUE(itDFS->isDone());
}
TEST(iterator, DFSIterator_Struct_nested) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator *itDFS = s.createDFSIterator();
    itDFS->first();
    ASSERT_EQ("1", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("t(X, 2)", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("X", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("2", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("Y", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_TRUE(itDFS->isDone());
}
TEST(iterator, DFSIterator_Struct_nested2) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Variable Z("Z");
    Number two(2);
    Number three(3);
    Struct u(Atom("u"),{&three, &Z});
    Struct t(Atom("t"), { &X, &two, &u});
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator *itDFS = s.createDFSIterator();
    itDFS->first();
    ASSERT_EQ("1", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("t(X, 2, u(3, Z))", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("X", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("2", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("u(3, Z)", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("3", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("Z", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("Y", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_TRUE(itDFS->isDone());
}
TEST(iterator, DFSIterator_List) {
    Variable X("X");
    Number two(2);
    List l({&X, &two});
    Iterator *itDFS = l.createDFSIterator();
    itDFS->first();
    ASSERT_EQ("X", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("2", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_TRUE(itDFS->isDone());
}
TEST(iterator, DFSIterator_List_nested) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator *itDFS = l.createDFSIterator();
    itDFS->first();
    ASSERT_EQ("1", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("t(X, 2)", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("X", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("2", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_EQ("Y", itDFS->currentItem()->symbol());
    ASSERT_FALSE(itDFS->isDone());
    itDFS->next();
    ASSERT_TRUE(itDFS->isDone());
}
TEST(iterator, BFSIterator_Struct) {
    Variable X("X");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Iterator *itBFS = t.createBFSIterator();
    itBFS->first();
    ASSERT_EQ("X", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("2", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_TRUE(itBFS->isDone());
}

TEST(iterator, BFSIterator_Struct_nested) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator *itBFS = s.createBFSIterator();
    itBFS->first();
    ASSERT_EQ("1", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("t(X, 2)", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("Y", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("X", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("2", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_TRUE(itBFS->isDone());
}
TEST(iterator, BFSIterator_Struct_nested2) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Variable Z("Z");
    Number two(2);
    Number three(3);
    Struct u(Atom("u"),{&three, &Z});
    Struct t(Atom("t"), { &X, &two, &u});
    Struct s(Atom("s"), { &one, &t, &Y });
    Iterator *itBFS = s.createBFSIterator();
    itBFS->first();
    ASSERT_EQ("1", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("t(X, 2, u(3, Z))", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("Y", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("X", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("2", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("u(3, Z)", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("3", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("Z", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_TRUE(itBFS->isDone());
}
TEST(iterator, BFSIterator_List) {
    Variable X("X");
    Number two(2);
    List l({&X, &two});
    Iterator *itBFS = l.createDFSIterator();
    itBFS->first();
    ASSERT_EQ("X", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("2", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_TRUE(itBFS->isDone());
}
TEST(iterator, BFSIterator_List_nested) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    List l({ &one, &t, &Y });
    Iterator *itBFS = l.createBFSIterator();
    itBFS->first();
    ASSERT_EQ("1", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("t(X, 2)", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("Y", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("X", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_EQ("2", itBFS->currentItem()->symbol());
    ASSERT_FALSE(itBFS->isDone());
    itBFS->next();
    ASSERT_TRUE(itBFS->isDone());
}
#endif
