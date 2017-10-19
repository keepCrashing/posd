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
    
