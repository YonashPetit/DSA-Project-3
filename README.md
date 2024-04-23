# DSA-Project-3
You should be able to run the program by downloading the zip file on Github and extracting it. Once you extract it, find the main.cpp file, open it, and then run it. If the program says "Error Opening File," it may be beacuse the "Electronic_Vehicle_Population_Data.csv" is not in the same directory as the "main.exe" file. But otherwise, the remaining directions to use the program are stated by the program's menu.

Report:

Administrative
The Models - Group 66

Team Members + Github user names:
Diksha Gupta
GitHub Username: @dikshaguptaa
Yonash Petit
GitHub Username: @YonashPetit

Link to GitHub repo
https://github.com/YonashPetit/DSA-Project-3/tree/main 

Link to Video demo (See below)
https://www.youtube.com/watch?v=RkteCoTuwLo 

Extended and Refined Proposal [Suggested 2 Pages]
Problem: What problem are we trying to solve?
We are trying to gain an understanding into the insights of the distribution of electric vehicle distance ranges within a given dataset. 

Motivation: Why is this a problem? 
This is a problem because currently, consumers have to generally shop around and create their own lists and/or keep track of their own information for factors such as range, mileage, age, color, and others about a car when looking to buy a new car that is just right for them. This project will allow for consumers to take a given dataset and find the highest and lowest range for the cars in the dataset. 

Features implemented:
The user can choose to find the “Highest Range Car Model”, “Lowest Range Car Model”, or to quit the program. 

Description of data:
The code processes data from a CSV file named "Electric_Vehicle_Population_Data.csv".  For each car, it extracts the make, model, and year along with the car's range. The code uses this mileage information for sorting purposes, enabling a user to identify the specific cars with the highest and lowest ranges within the dataset. However it is important to note that while for the purposes of this project, we are only extracting range data, much of the information in this dataset, including Base MSRP and 2020 Census Tract can all be extracted by changing the column being extracted in the code. 

Tools/Languages/APIs/Libraries used: 
CLion was used as the IDE in this project, using C++ as the language. All of the libraries used are part of the standard C++ Standard Library. The following libraries were used: iostream, fstream, string, vector, sstream, algorithm, random, and chrono. No API’s were used. 

Algorithms implemented
Two different sorting algorithms were used: QuickSort and MergeSort. 
The QuickSort algorithm is implemented with a partition function that is used to rearrange the array around a pivot that allows for placing the smaller ranges to the left and the larger ranges to the right. 
The MergeSort algorithm is implemented with a Merge function that is tasked with merging two of the sorted subarrays back into the one large, main array. The specific mergeSort function divides the array recursively until it reaches a subarray with the size of 1 (this is technically already sorted) and then merges to combine the results of the separate sorted arrays into one result. 

Additional Data Structures/Algorithms used
Data structures that were included are arrays, vectors, and structs. Some algorithm techniques that are present aside from the sorting algorithms are the use of File I/O which is the process of opening, reading lines from, and closing CSV files involving the basic file-handling algorithms. Another one is string parsing where the code utilizes string streams and tokenization by commas to break down each line of the CSV to extract the relevant car data which in this case is the range. Iterations are also used for several tasks including processing each line of the CSV file, implementing the iterative QuickSort, and curating the user menu. 

Distribution of Responsibility and Roles: 
Diksha Gupta: Diksha was responsible for delegating the tasks to each of the group members and writing the report. She also coded the MergeSort function. 
Yonash Petit: Curated the Menu and Coded QuickSort. He was also responsible for taking care of the technical problems that quickly arose during coding. 

Analysis [Suggested 1.5 Pages]
Any changes the group made after the proposal? The rationale behind the changes.
We had originally intended to make the project multifaceted in that the Base MSRP can also be sorted and extract information based on highest to lowest base MSRP. We also were considering adding more options for the user to play around with, including displaying the top 10 or bottom 10 cars in a certain category like range. However, the implementation of that was the responsibility of our former third team mate Sriya. Sriya, however, is no longer taking the class and we did not find out until Monday of the day the project was due as we had finished our parts and all that was left was multiplying the implementation to make it for more categories and display more information within the categories. So we were not able to code in those extra implementations in such a short amount of time. So those functionalities had to be scrapped. Other than that, everything else worked out exactly how it was designated to from the beginning of the project being curated. 
Big O worst case time complexity analysis of the major functions/features you implemented
The process of reading the car data from the CSV file takes time proportional to the number of cars (O(n)). The Quicksort implementation, in its worst-case scenario of an already sorted dataset, has a time complexity of O(n^2), making it slower than Merge Sort for large datasets.  In contrast, Merge Sort offers a guaranteed O(n log n) time complexity.  The core sorting processes dominate the overall complexity; however, once sorted, finding the highest and lowest range cars becomes very efficient, happening in constant (O(1)) time.

Reflection [Suggested 1-1.5 Page]
As a group, how was the overall experience for the project?
The experience was great as I got to work with people I did not know that well initially, so it was great making new friends in CS. In terms of coding, we all loved that we could do the parts that we were the best at which not only made the experience much more enjoyable, but we also got the work done in an efficient manner which was critical due to the exams and course load of the other classes we had to manage on top of this project. 
Did you have any challenges? If so, describe.

Our project faced a significant challenge when our third team member unexpectedly dropped the class without prior notice. This left us with an incomplete portion of the work that we had initially assigned to her.  Understanding that deadlines don't often adjust based on team dynamics, we quickly had to reassess our plan. Thankfully, we had each completed our core assigned tasks. This allowed us to shift focus, partially redistributing the remaining work and adapting our project scope slightly to ensure we could still submit a strong outcome within the given timeframe, especially since the project itself was working and just additional implementations needed to be taken care of. 
We also initially had trouble implementing QuickSort as it would take a lot of time to load so it was hard test it to see if it was working properly.

If you were to start once again as a group, any changes you would make to the project and/or workflow?
If we were to restart the project, a significant improvement would be the development of a web-based user interface (UI) that would make our tool accessible in real time via web browsers. This UI would be responsive and user-friendly, designed to function seamlessly across different devices such as smartphones, tablets, and desktop computers. Implementing dynamic filters in the UI would allow users to refine searches based on criteria like price, manufacturer, style, and year, enhancing user interaction. Additionally, integrating real-time data through APIs about car models, availability, and promotions would keep the content fresh and relevant, thereby increasing user engagement and reliance on the tool.
Further refining the project would involve incorporating interactive charts, graphs, and maps to visually represent data about car models, comparisons, and geographic information like charging station locations. Adopting agile development practices would ensure rapid prototyping and iterative progress through regular sprints and user feedback, enhancing the tool's functionality and user experience. Also, the use of version control and thorough documentation would facilitate smoother collaboration within a potentially distributed team, ensuring that the tool evolves continuously to meet the real-world needs of its users, making the searching experience more informative and enjoyable.


Comment on what each of the members learned through this process.
Diksha Gupta: She learned a lot more technical skills, especially due to Yonash bringing them up during the coding process. She also learned how to use GitHub effectively and use it in a collaborative setting. I also refined my sorting algorithm skills while coding Mergesort. 
Yonash Petit: Yonash also learned how to use GitHub in a collaborative setting. He also learned a lot more about implementing the sorting algorithms, especially quicksort. 

References 
GeeksforGeeks. (2024, April 8). Merge sort - data structure and algorithms tutorials. https://www.geeksforgeeks.org/merge-sort/ 
GeeksforGeeks. (2024b, April 9). Quicksort - data structure and algorithm tutorials. https://www.geeksforgeeks.org/quick-sort/ 


