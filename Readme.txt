We have used the "maze.txt" file to read the maze. Follow the following steps:

1. Save "maze.txt" file on the computer and keep track of the path of the file.
2. Edit the file path in the main function : Ln 112 - {maze.open("//Enter path of the file here");}
3. Execution of the code -
	a. Using CodeLite IDE:
		i. Open the .zip file, Extract files to a convenient path.
		ii. Open Codelite. Click on File --> Open --> Open workspace and select the path where the .zip file is extracted. Navigate to the "HW2" folder and select HW2.workspace.
		iii. Make the changes mentioned in 1. and 2. in the code.
		iv. Ctrl+F5 to run the program.

	b. Using text editor:
		i. Follow the same steps as a(i).
		ii. Right click the 'main.cpp' and open with Text Editor.
		iii. Save file.
		iv. Open terminal -> cd /"Enter path of the file here"
		v. Compile the code - sudo g++ main.cpp
		vi. Run the program -> ./a.out

NOTE: Ensure gcc compiler is installed on Ubuntu. If not, follow the following steps:
1. $ sudo apt-get install build-essential
2. $ gcc -v (//to check the version of gcc)

INSTRUCTIONS: When prompted for user input : the user must enter the x coordinate first followed by the y coordinate. For e.g., Enter the Start Postion ---> x,y : 29 1

4. Open "index.html" in html folder to open doxygen file.
