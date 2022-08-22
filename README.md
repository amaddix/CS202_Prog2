# CS202_Prog2/ Programming Systems /Winter 2018
*** Make sure to read the Background Information first!  
It applies to all programming assignments this term***



**THIS IS NO DESIGN WRITEUP and NO UML DIAGRAM for Program #2 ** 
Program #2 – Purpose 
In our first programming assignment, we experimented with the notion of OOP and  breaking the problem down into multiple classes building a relatively large system for a  delivery program. The purpose of that assignment was to get to know how we can create  classes that have different relationships. In program #2 our focus shifts to getting  experience developing a hierarchy that can be used with dynamic binding – so that the  application program can use one line of code to call one of many functions. To get the full  benefit of dynamic binding, we will look at a smaller problem with a predefined design. 
Program #2 – General Information 
My daughter got married this June and with it came many out of town visitors that stayed  with us. We had a variety of age groups from kids, young adults, and their parents. Finding  activities that everyone wanted to participate in and that were successful was a challenge.  At one point we divided up because it just didn’t work for the entire gang to do the same  activity. It was either boring or too challenging for one set of people. I felt bad when I took  the young adult to the rose garden and sat around like an 80 year old. Although it was  beautiful, she was far more interested in voodoo donuts! I wish I had a program that would  have helped me select the right activity based on the person’s age, interests, and skill level. 
Program #2 – Building a Hierarchy using Dynamic Binding 
For your second program, you will be creating a C++ OOP solution to support at least three different types of activities. Create a base class for the general form of activity. This should  be an abstract base class since we would never a general activity without knowing the  specifics.  
Then, create three different types of specific types of activities that will be derived from  the general one. Implement the following two choices and then ADD ONE OTHER of your  own choice. Make your type of activity similar to the other two but yet different!  
• Athletic Activity: This requires athletic skills, driving to a location and possibly  equipment needed. Examples could be wind surfing, jet skiing, hiking, kayaking, etc. some of these might have age or athletic requirements. 
• Site Seeing Activity. This would require the ability to get to a location, we would  need to know the hours of operation and a description of what we would be seeing. 
CS202 Summer 2018 Program #2 
If parking is a problem (like the Rose Garden) it should recommend taking Uber.  And, if any athletics are involved it should indicate the difficulty (e.g., Washington  Park requires considerable walking and walking shoes). For someplace like  voodoo, it requires indicating dietary constraints (e.g., my guest thought you could  eat lunch there!). 
The purpose of this assignment is to use and experience dynamic binding. The requirement  for this application is to have at least three DIFFERENT types of classes, derived from  a common abstract base class! To use dynamic binding, there needs to be a self-similar  interface among the derived class methods. In this case, for all types of activities, the user  would like to add a new activity, remove an activity, display all possible activities, mark  an activity as being done, and rate an activity about how well it met your expectations. In  the real world, there will be some differences as well, although there shouldn’t be too many.  Make sure to find at least one method that is different so that you can experience how  to resolve such differences. 
Program #2 – Data Structure Requirements 
With program #2, we need a Circular Linked List of base class pointers. Then using upcasting, each node can point to the appropriate type of activity. Implementation of the  required data structure(s) requires full support of insert, removal, display, retrieval, and  remove-all. This CLL allows a client to build a list for a variety of activities that they are  considering doing with their guests. The CLL should always continue with where they left  off performing activities (we don’t always want to start at the same place each time)! 
ALL repetitive algorithms should be implemented recursively  to prepare for our midterm proficiency demos! DO NOT break  the CLL. It is a CLL not a LLL!! 
Program #2 – Important C++ Syntax 
Remember to support the following constructs as necessary: 
1. Every class should have a default constructor 
2. Every class that manages dynamic memory must have a destructor 3. Every class that manages dynamic memory must have a copy constructor 4. If a derived class has a copy constructor, then it MUST have an initialization list  to cause the base class copy constructor to be invoked 
5. Make sure to specify the abstract base class’ destructor as virtual 
IMPORTANT: OOP and dynamic binding are THE PRIMARY GOALS of this  assignment!
