# SoftwareArch_FinalProject

TASK 3
------
Make the Observer functionality be more generic.  The Observer functionality was prototype and placed in a way that makes it hard to extend, as well as will lead to circular dependencies or callbacks being needed.
The Observer Code needs to be genericized, in such a way we can add in other types of observers.  We will also need to move the PartObservers to be in a better library location.  Additionally we will probably need a TopLevel Session class instead of relying upon CoreSession (Have a Session class inherit from CoreSession).  And then have that top level Session class have observers from the various needs.  i.e. it contains a list of PartObservers.  And the other type of Observers needed (say a Drawing Observer).

REQUIREMENTS: 
-------------
Requirement No            Description
--------------            -----------
Requirement 1 (REQUIRED)  All core Observer services should be in libcore
Requirement 2 (REQUIRED)  Application specific portions of Observer should be in appropriate libraries (i.e. not libcore)
Requirement 3 (REQUIRED)  Need to have a High level Session object. So application specific observers are not registered on CoreSession.
Requirement 4 (REQUIRED)  Implement a second use case for observers to show that core functionality is isolated, but can be extensible.


ESTIMATION:
-----------
Requirement No            Description                                                                                                    Hours
--------------            -----------                                                                                                    ----------
Requirement 1 (REQUIRED)  All core Observer services should be in libcore.                                                               5
Requirement 2 (REQUIRED)  Application specific portions of Observer should be in appropriate libraries (i.e. not libcore).               6
Requirement 3 (REQUIRED)  Need to have a High level Session object. So application specific observers are not registered on CoreSession. 6
Requirement 4 (REQUIRED)  Implement a second use case for observers to show that core functionality is isolated, but can be extensible.  8
                                                                                                                                  Total: 25


Task 3 would take 25 estimated hours in total to accomplish the given requirements and make the observer functionality more generic.

For better view we have attached an image which is properly formatted:
<img width="880" alt="Screen Shot 2022-04-10 at 2 46 22 PM" src="https://user-images.githubusercontent.com/97926077/162634834-523c837c-4913-4377-94bc-7caab357f250.png">


