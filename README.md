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
  # POSD2017F Homework

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
  
  * Thu Nov 02 2017 17:30:46
  
    1. The date of each team has been changed because we skip the week of mid-exam.
    
    2. Some people cannot attend the activity on that week, so we adjust them to other week.
        \
        \
          **Team #2 (11/18)&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Team #3 (11/25)&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Team #1 (11/04)&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Team #9 (01/06)**
        \
        ![Imgur](https://i.imgur.com/nkO111j.png) ![Imgur](https://i.imgur.com/mLcnZIb.png) ![Imgur](https://i.imgur.com/ipW1Gvm.png) ![Imgur](https://i.imgur.com/vgN8huc.png)
        
    3. If you also cannot attend the activity on that week, please email to us before at least one week.
    
    4. ~~About the method: `arity()` and `args()`, sorry for vague explanation. Here is the detail of interface:~~
    
    
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
