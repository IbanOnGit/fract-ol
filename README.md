How to use :

Type these commands in order in a terminal (should always work if not have fun debugging) :

1. git clone https://github.com/IbanOnGit/fract-ol.git

2. cd fract-ol_MAC or cd fract-ol_LINUX (depending on your Operating System)

3. make

4. ./fractol 1

Controls:

- Up, Down, Left, Right arrows: to move the fractal on the screen.
- 1, 2, 3: Three different fractals (so 3 different formulas).
- Mouse wheel or i and o: To zoom in (i) or out (o) the fractal.
- Spacebar: reset fractal to default mode.
- Escape to quit the program.
- q and w (on MacOS), + and - (On Linux): To increase (w or +) or decrease (q or -) the maximum number of iterations.
- y and x (on MacOS), a and z (On Linux): To increase (y or z) or decrease (x or a) the Constant's REAL part inside the formula.
- c and v (on MacOS), m and n (On Linux): To increase (c or v) or decrease (m or n) the Constant's IMAGINARY part inside the formula.
- r, g, b: To change each of the red, green, and blue values from 0 to 255.


Introduction:

Small Projects from the 42 school. This project is about "drawing" fractals (an ancient concept from math, haha) which are basically a visualization points that are in the Complex plane.
Basically, we have real numbers that we all know, such as 2, for example. 2 is a real number and its imaginary part is 0, so we ignore it, but all numbers have an imaginary part that
can be exploited. The number (2 + 0i) and the number (2 + 4i) are very different, just keep that in mind.

Explanation:

Here we have points on a 2D plane that we have created. Now take on this plane a very precise point. We're going to take (-1.2, 1.9) on the X and Y axis. We will call it (n1).
Now we create a complex number that has a real part of -1.2 and an imaginary part of 1.9. Now it's very simple, we just put (n1) into a mathematical formula.
This formula is quite easy, we put (n1) in the formula and get a new number (n2). From (n2), we get (n3) and so on, always applying the same formula.
We stop the sequence whenever we want to if it hasn't already gone to infinity or minus infinity. The maximum number of iterations (In my code I called this variable max_iteration)
is useful to get more depth in the fractal (more iterations equal more numbers and possibilities). With one iteration, it's boring, we don't have time to know if the point through the formula gets somewhere or if it just goes crazy !

I should mention that we take a circle with a radius of 4 and center 0, so we'll consider that any point not between -2 and 2 could be part of the fractal.
Eventually, this sequence converges (will get to an exact value) or diverges (+ or - infinity).
We don't really care what it does, but depending on these two outcomes (converges or diverges), we color the points for which the formula converges in black and the rest with whatever color we want !
Very important to precise that only the black points inside the circle (in this project) are part of the fractal. For the points that aren't black inside the circle,
we just color them depending on the number of iteratios and the red, green, blue values, all taking an integer between 0 and 255. It doesn't really matter what you choose to do in
order to get nice colors; just be creative!
After that, we repeat the exact same process for all the points on the screen and voilà! We now have a fractal, bravo!

Conclusion:

I had a lot of fun coding this project. It seemed really dark at first sight because of the mathematical part, which took some time to learn, but in the end, this project was totally
worth it. If you want to play with it, have fun! If you want to modify it, inspire yourself!

Don't copy, Learn :)
