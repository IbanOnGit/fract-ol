Introduction :

Small Projects from the 42 school. This project is about "drawing" fracatls (an ancient concept from math haha) which are basically points that are in the Complex plane. 
Basically we have real numbers that we all know such as 2 for example. 2 is a real number and it's imaginary part is 0 so we ignore it but all numbers have an imaginary part that
can be exploited. 

Explanation :

Here we have points on a 2d plane that we have created, now take on this plane a very precise point. We're going to take (-1.264, 2.981) on the X and Y axis we will call it n1.
Now we create a complex number that has for real part -1.264 and for imaginary part 2.981. Now it's very simple, we just put n1 into a mathematical formula.
This formula is quite easy, we apply the formula and get a new number (n2), from n2 we calculate n3 and so on always applying the same formula.
We stop the sequence whenever we want to if it hasn't already gone to infinity or minus infinity. The maximum number of iteration (In my code I called this variable max_iteration) 
is useful to get more depth in the fractal (more iteration equals more numbers and possibility). With one iteration it's quite sad, we don't ahev time to know if the value gets somewhere
or if it just goes crazy !
Eventually, this sequence converges (will get to an exact value) or diverges (infinity either way, no limits) we take a circle with a radius 4,
so we'll consider that any point not between -2 and 2 could be part of the fractal.
We don't really care what it does but depending on these two outcomes, we color the points for wich the formula converges in black ! 
Very important to precise that only the black points inside the circle (in this project are part of the fractal). For the points that aren't black inside the circle,
we just color them depending on the number of iteration and the red, green, blue, values that all take a integer between 0 and 255. It doesn't really matter what you chose to do in
order to get nice colors, just be creative !
After that, we repeat the exact same process for all the points on the screen and voilà ! We now have a fractal, bravo !

Controls :

- Up, Down, Left, Right arrows : to move the fractal on the screeen.
- 1, 2, 3 : Three differents fractals (so 3 different formulas).
- mousewheel or i and o : To zoom in (i) or out (o) the fractal.
- Spacebar : reset fractal to factory mode.
- Escape to quit the programm.
- q and w (on MacOS), + and - (On Linux) : To increase (w or +) or decrease (q or -) the maximum number of iteration.
- y and x (on MacOS), a and z (On Linux) : To modify to Constant's value inside the formula z_{n+1} = z_{n}^{2} + c (<- this constant c).
- r, g, b : To change each of the red, green and blue values from 0 to 255.

Conclusion :

I had a lot of fun coding this project, it seemed really dark at first sight because of the mathematical part which I took some time to learn, but in the end this project was totally
woth it. If you want to play with it, have fun ! If you want to modify it, inspire yourself !

Don't copy, Learn :)
