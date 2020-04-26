# Final Project

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Ankitha Damisetty - [`ankithad@illinois.edu`](mailto:ankithad@illinois.edu)

### Overview
I will create a dynamic game that takes the user through challenges of increasing difficulty. The goal of each challenge is for a small ball that begins at the top of the screen, to get to a specific point on the bottom of the screen. The player can draw lines on the screen with their cursor to create solid surfaces for the ball to move through. There will be a time limit that the player has to prepare their path before the ball is dropped from the top of the screen to the bottom. This game is inspired by two games that I enjoyed playing when I was young.

### Libraries
I will be using the [Box2D](https://github.com/sansumbrella/suBox2D) library to manage the motion of my ball. It will react differently based on how fast it hits a surface and at what angle that force is felt on the ball. 

### Timeline
For the first week, I will aim to create my ball object and more importantly I will implement code for how the player can interact with the screen. They should be able to click and drag to create solid surfaces. 
For the second week, I will work on moving the ball naturally. It should react differently for different forces it feels and based on what speed it is currently moving at. I will also work on setting the time limit on my game.
For the third week I will work on having the game run together and implementing multiple levels. The first level will be a simple blank screen, but the harder levels will include solid obstacles.
If I have extra time, I will focus on allowing an array of obstacles in different levels. For example, there could be a teleportation tool, that allows the ball to enter in on one side and come out on the other side. 
