/**
* @file main.cpp
* @author Nalin Das <nalindas@umd.edu>, Aditya Khopkar <akhopkar@umd.edu>, Raghav Nandwani <raghav15@terpmail.edu>, Kushagra Agrawal <kagrawal@umd.edu>, Nidhi Bhojak <nbhojak@terpmail.edu>, Balasankula Sai Chaitanya  <saibala@terpmail.umd.edu>
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* Problem

 * • A robot is asked to navigate a maze. It starts at a specific position in the maze (the starting position)
	and is asked to try to reach another position in the maze (the goal position).

 * • Positions in the maze will either be open or blocked with an obstacle.

 * • Positions are identified by (x, y) coordinates.
 * 
*/


#include <iostream>
#include <fstream>
#include <ios>  
#include <limits>  

int no_of_rows{30};
int start_position[2], goal_position[2];
char maze_array[31][46];
bool check_for_goal=false;

bool OutOfBounds(int a, int b);    //Function Prototypes
bool FindPath(int a, int b);


/**
 * @brief
	1. Reading Maze textfile.
	2. Prompting user to enter the start and goal position
	3. Checking if the entered points are valid or not
	4. Calling FindPath function with start point coordinates as arguments
	5. Printing the maze with the solution path
	6. If solution not found the print out "Path not found"
 * */

int main()
{
	std::string x = " "; 
	std::ifstream maze;
	maze.open("/home/aditya/Downloads/maze.txt"); // Extract .txt file

	while (getline(maze, x))
	{

		for (int i=0; i<=45; i++){
			maze_array[no_of_rows][i] = x[i]; // Extracting and storing the txt file in 2D array 
		}
		no_of_rows--;
	}
	
while(1){
	
	start:
	std::cout << "Enter the Start Position --> x,y" << std::endl;
	std::cin >> start_position[0] >> start_position[1];
	if(std::cin.fail()){
		std::cout<< "Start position not an integer."<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
		goto start;
	}
	std::cout << "Enter the Goal Position --> x,y" << std::endl;
	std::cin >> goal_position[0] >> goal_position[1];
	if(std::cin.fail()){
		std::cout<< "Goal position not an integer."<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		goto start;
	}



	if (start_position[0]==goal_position[0] && start_position[1]==goal_position[1]){
		std::cout<< "Start and Goal positions are same"<<std::endl;

	}
	else if(OutOfBounds(start_position[0],start_position[1])){
		std::cout<< "Start position is out of the maze"<<std::endl;

	}
	else if(OutOfBounds(goal_position[0],goal_position[1])){
		std::cout<< "Goal position is out of the maze"<<std::endl;

	}
	else if(maze_array[start_position[1]][start_position[0]]=='#'){
		std::cout<< "Start position is in obstacle"<<std::endl;

	}
	else if(maze_array[goal_position[1]][goal_position[0]]=='#'){
		std::cout<< "Goal position is in obstacle"<<std::endl;

	}
	else
		break;
}
FindPath(start_position[0], start_position[1]);
maze_array[start_position[1]][start_position[0]] = 'S';
maze_array[goal_position[1]][goal_position[0]] = 'E';
 
 for(int l = 30; l>=0; l--){
 for (int k = 0; k <= 45; k++){
	if (maze_array[l][k] == '*')
	maze_array[l][k] = ' ';
	std::cout << maze_array[l][k];
 }
 std::cout << std::endl;
 }
if (check_for_goal==false){
	std::cout<<"Path not found"<<std::endl;
}
return 0;
}


/**
* @brief A function that checks if the point is outside the maze or not.
* @param x X Coordinate
* @param y Y Coordinate
* @return if out of maze return True else return False
*/

bool OutOfBounds(int x, int y){
	if (x < 0 || x > 45 || y < 0 || y > 30)
		return true;
	else
		return false;
}


/**
* @brief A recursive function that starts from a start position and moves in all four directions. From the new position it will further move in the four directions, untill it finds the path to the end goal.
* @param x X Coordinate
* @param y Y Coordinate
* @return If end goal found then True, else False.
*/
	
bool FindPath(int x, int y){

	if (OutOfBounds(x,y))
		return false;
	if (x == goal_position[0] && y == goal_position[1]){
		check_for_goal = true;
	return true;
	}
		
	if (maze_array[y][x] == '#' || maze_array[y][x] == '*' || maze_array[y][x] == '+')
		return false;

	maze_array[y][x] = '*';

	if (FindPath(x, y+1)) // north coordinates of (x,y)
	{
		maze_array[y][x] = '+';
		return true;
	}
	if (FindPath(x+1, y)) // east coordinates of (x,y)
	{
		maze_array[y][x] = '+';
		return true;
	}
	if (FindPath(x, y-1)) // south coordinates of (x,y)
	{
		maze_array[y][x] = '+';
		return true;
	}
	if (FindPath(x-1, y)) // west coordinates of (x,y)
	{
		maze_array[y][x] = '+';
		return true;
	}

		maze_array[y][x] = '*';
	return false;
	}
