# Development

---
Currently, my game, Falling Fun, works to create a set number of small balls. These small balls drop to the ground with the force of gravity, and bounce against eachother if they interact with eachother. 

I create a central engine class which communicates with my_app.cc (which contains the cinder aspect). The engine class connects with a class containing the small balls and a class containing the solid edges, which is just the ground right now. 

Now, the game creates small balls in a range. Additionally, it creates a border around the Cinder screen (comprising of a right wall and a left wall), used so that the balls do not go out of range of the screen. 

Additionally, there is much improved class heirarchy. Now the app creates and engine class which passes in the box2d world object. From the engine, the small balls and all the walls are created. 
