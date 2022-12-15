# CS210-Grocery
CS210 - Grocery

Summarize the project and what problem it was solving.

  This project was the Corner Grocer project.  In this project we were tasked with creating a program that would use both Python and C++ to read the provided
  list of items sold throughout the day and display the information in three possible outputs: 1. A list of all items and their total items sold. 2. A search
  for an item in the list and find the total value sold. 3. Produce a histogram based on the total items sold data.
  
What did you do particularly well?
  
  I feel that what I did particularly well was carry forward the different lessons learned during the previous projects and assignments to build the body of
  the menu.  I also implimented a lesson learned from the Module 6 assignment that would have caused an error and crash after displaying output in this project.
  
Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

  In order to enhance my code, I could go back through and break down my main menu function to be more modular, allowing for easier readability and troubleshooting.
  I would also opt to not have the histogram data be written to a file in Python to be read and formatted and output in C++.  I would use Python with one of 
  the various libraries that it has for data/science to establish the output.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

  The pieces of the code that I found most challenging to write was ensuring the proper formating of the histogram while incorporating the ASCII color code.
  When I was adding the code in it would throw off the spacing of the data lines.  In order to correct this issue I had to rethink where I would put the color
  code, as well as adjust values for setw().  It was a trial and error scenario.

What skills from this project will be particularly transferable to other projects or course work?

  The integrating different programming languages will be particularly transferable to other projects or course work in the future.  After seeing the growing
  applications of using multiple languages to either save compiling time, increase security, or provide better functionality during the readings and research
  for week 7 I know that it is something that I will come across needing to do again.
  
How did you make this program maintainable, readable, and adaptable?

  In order to make this program maintainable, readable, and adaptable I did the following:
    I ensured function names were easy to identify to their purpose.
    If a different command can complete the the same job as a loop, I would use that.  (Using a string command for histogram markers and not a loop)
    Made detailed comments for each section and line, unless otherwise a repeat in code.
    Using a switch function for the menu will allow for easier growth of menu choices in the future.
    Having all validation done in the main C++ file ensures that 
