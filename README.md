# Montecarlo
A program that finds aproximations of pi following a method that used random numbers. The method used is called Montecarlo and it's very known for its simplicity.

**It all starts with this dartboard:** 

![](https://raw.githubusercontent.com/pabloasenjo3/Montecarlo/master/.edit/dartboard.png)

The area of the circle is defined by 

![](https://raw.githubusercontent.com/pabloasenjo3/Montecarlo/master/.edit/circle.png)

Whereas the area of the whole square square is defined by

![](https://raw.githubusercontent.com/pabloasenjo3/Montecarlo/master/.edit/square.png)

Thus, doing some basic math we get to

![](https://raw.githubusercontent.com/pabloasenjo3/Montecarlo/master/.edit/formula.png)

Now the problem lies in our way to measure the whole square and the circle. That's when random numbers (darts) come to play. It's possible to consider the number of random darts on a surface a measure of its area.

![](https://raw.githubusercontent.com/pabloasenjo3/Montecarlo/master/.edit/1.png)
![](https://raw.githubusercontent.com/pabloasenjo3/Montecarlo/master/.edit/2.png)

**Generating random numbers:**

The way this program, at least until beta version, generates random numbers, is using the C `<cstdlib>` library. The PRNG (pseudo random number generator) is seeded at the start of the program (when an instance of the class `Dartboard` is created) based on the machine time, using the `<ctime>` library.

```c++
    //Sets inital seed for srand function based on machine time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //The function bellow returns a random integer between 0 and 2^15 -1 (32767)
    std::rand();
```

The program does not calculate darts coordinates like this at all, it does it in a slightly different way wich is explained inside the code. This piece of code just shows the functions wich are used.
