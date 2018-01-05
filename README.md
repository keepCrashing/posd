# [POSD2017F Homework](http://www.cc.ntut.edu.tw/~yccheng/posd2017f/posd.htm)

## Homework assignment 1

Make the unit tests given (Sort.h, utSort.h) to you pass.

#### Assignment requirement

 1. Implement Sort.h.
 2. According to #1, write five unit tests in utSort.h.
 3. Write the corresponding makefile to generate executable file which named `hw1`.

#### Marks

Each test is 10 points, total is 50 points.

## Homework assignment 2

#### Assignment requirement
 1. Need to create a header file by youself naming `Number.h`.
   In this header, there will be three method you should define: `symbol()`, `value()` and `match()`. As you define the Atom
   and implement it, the `symbol` and `value` method should return value with string type. And for `match`, in this homework,
   please use the method way to define instead of operator.

 2. Also re-define and re-implement the `match()` in Atom via method way instead of operator.

 3. Implement all tests in utTerm.h. There are prompts in each test, follow the prompt to complete tests.

 4. Write the corresponding makefile to generate executable file which named `hw2`.

 5. Make sure your CI jobs are both passed before deadline.

#### Marks

On your own tests, each test has 2 points, total is 30 points.
On TA's tests, each test has 4 points, total is 60 points.
The sum of this homework marks is 90.

## Homework assignment 3

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

~~And unfortunately, the theft of plagiarism occurred again and again, in order to protect the rights and interests of students, we decided to ask you to move your repository from Github to [Gitlab](https://gitlab.com). Please follow [the steps](https://github.com/posd2017f/homework#setup-gitlab-repository) below to change your repository host.~~

:zap: After we discussed with Professor, we decided to remain github host. So if you already created a new gitlab repository, sorry for that.

#### Assignment requirement

  1. Need `number.h` and its class implementation `Number`, you can use the previous one(hw2). And the interface of `Number` should follow the code block below:

      ```c++
      Number(double value);
      std::string symbol();
      std::string value();
      ```

  2. Implement all tests in `utStrcut.h` and `utVariable.h`. The describe of test have been written on each test.

  4. Write the corresponding makefile to generate executable file which named `hw3`. Note that it is the executable name, not the test file name.

  5. Make sure your CI jobs are both passed before deadline.

#### Marks

  You totally have 15 tests in your own, each one is 2 points.
  And TA's tests totally have 20 tests, each one is 3 points.
  The sum of this homework is 90 points.

#### Deadline

  Thus Oct 19 2017 23:59:59
    
  ## Homework assignment 4

  Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

  :zap: Some people will place header files into `include` folder, and it may cause the building of .ut job to fail. If so, just email to us and we will change the configuation for you.

  #### Update

   * Mon Oct 23 2017 09:54:36

     * Please check your ut job, if it's passed but there is no test report comes out (besides first time building), it means your progarm actually is crash. We are discussing about this cas and think about how to fix it or is there other solution.

     * And about test case X = [496, X, terence_tao]. In this weekend, we replied one student that this decision was a sample judgment that we made and it can be corrected if it's wrong truly. But it sounds pretty irresponsible(sorry for Mr. X), so we re-discuss this case today.\
        \
        About this metter, we need to check the definition of matching. In the section 2.2 *Matching* of the book: PROLOG Programming for Artificial Intelligence (third version, Ivan Bratko, 0-201-40375-7), said if two terms match, it must: (1)They are identical, or (2) the variables in both terms can be instantiated to objects in such a way that after the substitution of variables by these objects the terms become identical. Rule (1) is easy to understand, but what is rule (2)? Rule (2) means that if it can get the any value which can make the equation holds, we said it match. For our case, if variable X could be instantiated by any value that make the equation holds, the #match() should return true, otherwise returns false. **But it couldn't be, and also not yet.**\
        \
        We can't set true or false on this case utill the variable X can be instantiated. In SWI-Prolog you will get the string "X = [496, X, terence_tao]" as the result instead of false, but it doesn't mean that this matching actually returns true or false(in program). So, for this one, **we just decided to make it not score. You can get the points but you still need to write the test, we don't care about the true or false it returns.**
    
  #### Assignment requirement

    1.  Implement `List` according to the `list.h`, and also all tests in `utList.h`.

    2. Write the corresponding makefile to generate executable file which named `hw4`. Note that it is the executable name, not the test file name.

    3. Make sure your CI jobs are both passed before deadline.

  #### Marks
    You totally have 19 tests in your own, each one is 2 points.
    And TA's test also have 19 tests, each one is 3 points.
    The sum of this homework is 95 points.
  #### Deadline
    Friday Oct 27 2017 23:59:59

  ## Homework assignment 5

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this assignment, you are required to implement the more complete parser through each test. It will use the interface written in the course. And then, there are few tests will need some new methods of different term class, please follow the description of test, implement each method.

And from this week, we start to run [Mob programming](https://www.google.com.tw/search?q=mob+programming). There will be one or two group in every week until the end of semester, they are required to show the demonstration which how they run the mob programming and how to solve the problem that in the assignment. It needs to do rehearse and prior planning with us. See below to get more detail.


#### Update

  * Fri Nov 03 2017 15:06:12

    The method `args()`, it should return `Term *`, not `Term &`. please correct it in your assignment.

    ```diff
    class Struct {
        public:
          int arity(); // return the number of args (terms)
    -     Term & args(int index); // according to index return the term
    +     Term * args(int index); // according to index return the term
      }
    ```

  * Fri Nov 03 2017 11:55:51
  
    The description of test `TEST_F(ParserTest, ListAsStruct)` is wrong, please correct it in your assignment.

    ```diff
    // Then it should return a Struct which contains two terms.
    // And #arity() of the Struct should be 2.
    // And #symbol() of Struct should return ".(1, [])".
    - // And the first term should be number: "1", the second term should be another Strcut: "[]".
    + // And the first term should be number: "1", the second term should be another List: "[]".
    TEST_F(ParserTest, ListAsStruct) {

    }
    ```
    
    
#### Assignment requirement

  1. Complete the parser with the description of each test

  2. Implement the new method `arity()`, `args()` in `Struct`.
  
  3. Write the corresponding makefile to generate executable file which named hw5. Note that it is the executable name, not the test file name.
  
  4. Make sure your CI jobs are both passed before deadline.

#### Marks

  You totally have 20 tests in your own, each one is 2 points.
  And TA's test also have 20 tests, each one is 3 points.
  The sum of this homework is 90 points.

#### Deadline

  Thur Nov 9 2017 23:59:59
## Homework assignment 6

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this assignment, you are required to implement the complete matching like `X=1.` through parser. And for test, you don't need to write the test by yourself, we will provide the test to you. Therefore on the CI server, you will only have one job. Please follow the test to implement the necessary class and its interface.

And for the coming Saturday(11/25), there will be two teams need to attend the mob programming. Some adjustment here, please check your name and time, reply to us if you cannot attend the activity on Saturday. And for the demonstration , there is a difference from the previous time, please check [the demonstration  part](https://github.com/posd2017f/homework#demonstration) to get the more information.

### Update

  * Fri Nov 24 2017 10:04:53
  
  1. [Remove the assertion for symtable](https://github.com/posd2017f/homework/commit/044104f7f0cde0602c5034c330aad790eb6233bb#diff-d6ccfd1db8c6193d6118db3625f88da7).
  2. [Add the description for the parser method](https://github.com/posd2017f/homework/blob/master/README.md#assignment-requirement).


#### Assignment requirement

  1. Complete the parser through the test. 
  
      There are some methods different from before, especially the `createTerms` is no longer public and we use `matchings` to make term and pares sentence instead of `createTerms`. Basically it is the difference concept between parsing the complete sentence and parsing a part within the sentence. The `createTerms` should be responsible for getting the arguments if there is a list or structure, therefore it should be named `getArgs` rather then `createTerms`.
      
      We create a new method called `matchings` to parse the whole sentence. It take the sentence as the input, and __generates all terms in the sentence and make the corresponding tree__ to ready to do the real matching. The matching will call the `createTerm` method in serval times, and if it meets a list or structure, it will call `createTerms`(getArgs) to get the arguments for that.

      After `matchings`, the client will get __the root node of the tree by `expressionTree`__, and __do the real matching through the `evaluate` method of the root node__. And after `evaluate` the whole tree, client will get the final status of the matching. E.g. `X=1.`, the X will be the number 1 after the process.

  2. Implement the new class `Node` and its interface. The `Node` class is used to create the expression tree, and the tree represents the structure of a sentence. Each node is an operator or an operand, so you need to visit the whole tree to do the real matching.
  ![tree](https://i.imgur.com/JYVvY2s.png)
  The class has the `two constructors` to generate an node or connect two child nodes, and the `evaluate` method is used to evaluate that when to do the matching.
  
  3. Write the corresponding makefile to generate executable file which named `hw6`. Note that it is the executable name, not the test file name.
  
  4. Make sure your CI job is passed before deadline.

#### Marks

  You totally have 11 tests, each one is 9 points.
  And for easier calculating, the sum score of assignment is 100 points.

#### Deadline

  Wed Nov 29 2017 23:59:59

#### Note

  * Try to read building information in console log and fix the hw problem by yourself as possible as you can.
## Homework assignment 7

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

In this time, you have to design your tests for the iterator of `Struct` and `List`. A structure contains several terms, it can be expanded into a tree structure like the picture below. We will make two kinds of way to traverse the structure, the first is [deep-first search](https://en.wikipedia.org/wiki/Depth-first_search), and the second is [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search). When traversing the structure, iterator gets each item in structure orderly.

You need to design the tests to test your iterator, the function signature of iterator and its usage must follow the way that defined on the course. There is also ours tests to test your program on the CI server (.ut job). 

For mob programming, there are some changes of schedule and its activity. We add a activity called `Retrospective` in last step, which is the same as the retrospective in [Scrum](http://teddy-chen-tw.blogspot.tw/2011/12/scrum-1.html). In retrospective, team will discuss about some issue related to team's development process, and it will help you to review the way when you write code and give you some feedback so you can improve to yourself.

### Update

 * Thu Dec 07 2017 14:31:36
 
   1. The deadline is extended to the next Monday(12/11 23:59:59)
   
   2. There is no mob on this weekend, team#6 #7 will be on the next Saturday(12/16).
   
   3. Few people got the *Segmentation Fault* on CI server but run test successfully on local. This is due to different compiler of different OS: mingw32-make, make. The problem cannot be addressed with a signle soluation, but it occurs on invoking the memory that cannot be accessed, e.g. use the nullptr or use the object that not initialized yet. So please check initialization before using, or delete object properly after test.

 * Sun Dec 03 2017 15:22:02

  first() in our example should return bigmac not combo1.

![Imgur](https://i.imgur.com/v1GyjBX.png)

#### Assignment requirement

  1. Redo the creation of iterator, use aggregate(e.g. `Struct`) to create iterator instead of client, and re-write the test of that.

  2.  As we can handle difference type on function through *template\<T>*, make the template on `Iterator` so it can handle the type other than `Term`.

  3. Design test for the iterator by yourself. The function signature and usage is not allow to change. 
     
     * Two kind of way for traversing: Deep-first search, Breadth-first search, so there will be two methods on the aggregate: `createBFSIterator`, `createDFSIterator`.

     * You need to design 2 test data for each type, `Struct` and `List`, and use BFS and DFS to traverse each test data. So it totally has 8 tests.
 
  4. Write the corresponding makefile to generate executable file which named `hw7`. Note that it is the executable name, not the test file name.

  5. Make sure your CI job is passed before deadline.

#### Marks

  You totally have 12 tests, include the test written on the course. Each one is 5 points.
  And we will have 8 tests, each one is also 5 points.
  The sum score of assignment is 100 points.

#### Deadline

  Fri Dec 8 2017 23:59:59

