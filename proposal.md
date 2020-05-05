# Falling Fun

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

**Author**: Ankitha Damisetty - [`ankithad@illinois.edu`](mailto:ankithad@illinois.edu)

### Overview
I am creating a dynamic game that allows the user to draw solid surfaces around 
the screen, to lead small balls from the top of the screen to a bottom target. 
The player can draw lines on the screen with their cursor to create solid 
surfaces for the ball to move through. There will be a time limit that the 
player has to prepare their path before the ball is dropped from the top of the 
screen to the bottom. This game is inspired by two games that I enjoyed playing 
when I was young.

### Libraries
I will be using the [Box2D](https://github.com/sansumbrella/suBox2D) library to 
manage the motion of my small balls. It will react differently based on how fast
 it hits a surface and at what angle that force is felt on the ball. 

### Timeline
For the first week, I will attempt to understand my library: create a basic ball
shape and a world object as needed by box2d. 

For the second week, I will implement solid surfaces around the border of the
screen and work on getting user input to draw surfaces. 

For the third week, I will make sure the user drawn solid surfaces are working
as expected and allowing score to be calculated. If I have time, I will add a 
color scheme to my game. 
