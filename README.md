## Algorithm Design Course
* Teacher : Dr. Omid Sojoodi
* Student : Ramtin Kosari

### Abstract
This Repository Contains Collection of Implementations and Usages of CLRS Book Algorithms Visualized by OpenCV C++ Library

## Algorithms
Supported Algorithms :
1. Sorts
   - [x] Insertion Sort
   - [x] Selection Sort
   - [x] Bubble Sort
   - [x] Quick Sort
   - [x] Merge Sort
   - [ ] Heap Sort
2. Search
   - [ ] Linear Search
   - [ ] Binary Search
3. Min Max
   - [ ] Min Max of Array
4. Large Numbers Operations
   - [ ] Multiplication of Large Numbers
   - [ ] Subtraction of Large Numbers
   - [ ] Addition of Large Numbers
   - [ ] Division of Large Numbers
5. Matrix Operations
   - [ ] Strassen Matrix Multiplication
   - [ ] Matrix Chain Multiplication
   - [ ] Block Matrix Multiplication
   - [ ] Floyd Warshall Algorithm
   - [ ] Inverse of Matrix
6. Travelling Salesman Problem
   - [ ] TSP Dynamic Programming
   - [ ] TSP Genetic Algorithm
   - [ ] TSP Branch and Bound
   - [ ] TSP Brute Force
7. Knapsack Problem
   - [ ] Fractional Knapsack Problem
   - [ ] 0/1 Knapsack Problem
   - [ ] 0/1 Knapsack Branch and Bound Problem
8. Moving on a Grid
   - [ ] Moving on a Grid
9. Minimum Spanning Tree
   - [ ] Kruskal's Algorithm
   - [ ] Prim's Algorithm
10. Shortest Path
   - [ ] Floyd Warshall Algorithm
   - [ ] Bellman Ford Algorithm
   - [ ] Dijkstra's Algorithm
11. Huffman Coding
   - [ ] Huffman Coding
12. N Queens Problem
   - [x] N Queens Problem
13. Convex Hull
   - [ ] Jarvis March
   - [ ] Graham Scan
14. Graph
   - [ ] Breadth First Search
   - [ ] Depth First Search

## Algoritms Images
### Sorts
#### Sort by Theta
Here are Graphical Views of Sorting Algorithms on Random Generated Points, Final Result Shows Points that have been Sorted by Theta from Point in Middle
<p align="center">
  <img src="./assets/images/sorts/1.png" alt="Sort Points" width="49%"/>
  <img src="./assets/images/sorts/5.png" alt="Sort Final" width="49%"/>
</p>

<p align="center">
  <img src="./assets/images/sorts/2.png" alt="Sorting 1" width="30%"/>
  <img src="./assets/images/sorts/3.png" alt="Sorting 2" width="30%"/>
  <img src="./assets/images/sorts/4.png" alt="Sorting 3" width="30%"/>
</p>

#### Sort by X-Axis (Left to Right)
<p align="center">
  <img src="./assets/images/sorts/8.png" alt="Sort Final" width="55%"/>
</p>

<p align="center">
  <img src="./assets/images/sorts/6.png" alt="Sorting 1" width="40%"/>
  <img src="./assets/images/sorts/7.png" alt="Sorting 2" width="40%"/>
</p>

### N-Queens Algorithm
Here are Graphical Views of N-Queens Problem
<p align="center">
  <img src="./assets/images/nqueens/1.png" alt="N Queens Chess Board" width="29%"/>
  <img src="./assets/images/nqueens/5.png" alt="Finding Positions" width="40%"/>
  <img src="./assets/images/nqueens/2.png" alt="Final Positions" width="29%"/>
</p>

<p align="center">
  <img src="./assets/images/nqueens/3.png" alt="Another Position" width="30%"/>
  <img src="./assets/images/nqueens/6.png" alt="Showing Positions in Termnial" width="30%"/>
  <img src="./assets/images/nqueens/4.png" alt="Another Position" width="30%"/>
</p>

## How to Run ?
First You Must Clone [RKACPB](https://github.com/RamtinKosari/RKACPB) Repository which is My Automatic C++ Project Builder by :
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

## Prerequisites
Before You Begin, Ensure You have Met the Following Requirements:
- Installed ```OpenCV``` 4.x
- ```Linux``` or ```MacOS```
- ```CMake``` and ```GCC``` Compiler
