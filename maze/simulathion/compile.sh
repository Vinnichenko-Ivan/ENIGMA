#!/bin/bash
echo "start Game"
rm labyrinth
rm main.o 
g++ -c main.cpp 
g++ main.o -o labyrinth
./labyrinth
rm labyrinth
rm main.o 
echo "Game end"
