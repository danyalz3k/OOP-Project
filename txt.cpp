/*
develop an opject oreinted program in which a user can populate a pond with koi fish, feed them, run a viral attack simulation on the pond an then see the results. the specification are given below.

    1. use vector container provided by cpp standard library

Koi(class)

This is the basic Koi class(there are two further types ahead that inherit from this).
    2. enter koi will have an id assigned to it in the constructor (generated using a static counter)
    3. Each koi will have health points, but donot initialize here
    4. include a pure virtual function to display the koi on screen, named display
    5. include a pure virtual function to handle viral attack, named viralAttack()
    6. include a feed function that increases koi health by 1 point, named feed()


KoiBiColor (class)
this will inherit from Koi class

    7. each vicolor koi will start with 10 health points
    8. a bicolor will be displayed using the following two charecters alternatively: * and ^
        a. so a bicolor wiht health 10 will display as *^*^*^*^*^
        b. if health is 0 or below, only display xx to show that koi is dead
    9. when a bicolor is attacked by virus it loses 2 points

KoiTriColor (class)
this will inherit from Koi class

    10. each vicolor koi will start with 8 health points
    11. a bicolor will be displayed using the following three charecters alternatively: ~ and ! and #
        a. so a bicolor wiht health 10 will display as ~!#~!#~!
        b. if health is 0 or below, only display xx to show that koi is dead
    12. when a bicolor is attacked by virus it loses 1 points

13. create a pond using a single vector contaier koi pointers
14. as the user to enter koi fish in their pond as per their preference(B for bicolor, T for tricolor, E for exit)
15. populate the pond by creating and inserting the desired number of koi fish.
16. display the pond.
17. in a loop, keep asking the user if they wan to feed the fish or stop feeding, each time user chooses to feed, each fish in the pond should be fed once.

18. display the pond(pond after feeding)

19. simulate a viral attack on the pond by creating a loop that will run a random number of times, and will call the  viralAttack function on random koi in the pond(note that two random decision need to be made , first wheteher a specific koi wil be attacked, and second, how many times it will be attacked.). The ranges of these random attacks should be decided on your own that you end up with good sample runs

20. display the pond(pond after viral attack)



write a cpp code in single file 
*/