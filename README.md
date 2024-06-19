## Algorithm Design Course
* Teacher : Dr. Omid Sojoodi
* Student : Ramtin Kosari

### Abstract
This Repository Contains Collection of Implementations and Usages of CLRS Book Algorithms Visualized by OpenCV C++ Library

## Algoritms Images
### Sorts
#### Sort by Theta
Here are Graphical Views of Sorting Algorithms on Random Generated Points, Final Result Shows Points that have been Sorted by Theta from Point in Middle
<p align="center">
  <img src="./assets/images/sorts/1.png" alt="Sort Sample" width="49%"/>
  <img src="./assets/images/sorts/5.png" alt="Sort Sample" width="49%"/>
</p>

<p align="center">
  <img src="./assets/images/sorts/2.png" alt="Image 2" width="30%"/>
  <img src="./assets/images/sorts/3.png" alt="Image 3" width="30%"/>
  <img src="./assets/images/sorts/4.png" alt="Image 3" width="30%"/>
</p>

#### Sort by X-Axis (Left to Right)
<p align="center">
  <img src="./assets/images/sorts/8.png" alt="Sort Sample" width="70%"/>
</p>

<p align="center">
  <img src="./assets/images/sorts/6.png" alt="Image 2" width="49%"/>
  <img src="./assets/images/sorts/7.png" alt="Image 3" width="49%"/>
</p>

### N-Queens Algorithm

## Algorithms
Supported Algorithms :
1. Sorts
   * Insertion Sort                                        ```IMPLEMENTED```
   * Selection Sort                                        ```IMPLEMENTED```
   * Bubble Sort                                           ```IMPLEMENTED```
   * Quick Sort                                            ```IMPLEMENTED```
   * Merge Sort                                            ```IMPLEMENTED```
   * Heap Sort                                             
2. Search
   * Linear Search                                         
   * Binary Search                                         
3. Min Max
   * Min Max of Array                                      
4. Large Numbers Operations
   * Multiplication of Large Numbers                       
   * Subtraction of Large Numbers                          
   * Addition of Large Numbers                             
   * Division of Large Numbers                             
5. Matrix Operations
   * Strassen Matrix Multiplication                        
   * Matrix Chain Multiplication                           
   * Block Matrix Multiplication                           
   * Floyd Warshall Algorithm                              
   * Inverse of Matrix                                     
6. Travelling Salesman Problem
   * TSP Dynamic Programming                               
   * TSP Genetic Algorithm                                 
   * TSP Branch and Bound                                  
   * TSP Brute Force                                       
7. Knapsack Problem
   * Fractional Knapsack Problem                           
   * 0/1 Knapsack Problem                                  
   * 0/1 Knapsack Branch and Bound Problem                 
8. Moving on a Grid
   * Moving on a Grid                                      
9. Minimum Spanning Tree
   * Kruskal's Algorithm                                   
   * Prim's Algorithm                                      
10. Shortest Path
   * Floyd Warshall Algorithm                             
   * Bellman Ford Algorithm                               
   * Dijkstra's Algorithm                                 
11. Huffman Coding
   * Huffman Coding                                       
12. N Queens Problem
   * N Queens Problem                                     ```IMPLEMENTED```
13. Convex Hull
   * Jarvis March                                         
   * Graham Scan                                          
14. Graph
   * Breadth First Search                                 
   * Depth First Search                                   

## How to Run ?
First You Must Clone ```RKACPB``` Repository which is My Automatic C++ Project Builder by :
```bash
git clone https://github.com/RamtinKosari/RKACPB.git
```
Then, Go to RKACPB by ```cd RKACPB``` and Do this Command
```bash
./build.sh --packages "OpenCV;X11"
```
This will Automatically Build the Project, then You have to Go to the ```build``` Directory Created in Base Directory and Do this Command :
```bash
./run
```