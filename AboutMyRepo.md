I have Covered Following topics

Array

1-Insertion At end o(1) , begin,middle o(n)
2-Deletion  At end o(1) , begin,middle o(n)
3-Searching(Linear o(n) and Binary o(logn)) 
4-Sorting(Selection,insertion,merge,bubble)
| Sorting Algorithm           | Sorted Array | Reverse Sorted Array | Random Array | Reason (Short)               |
| --------------------------- | ------------ | -------------------- | ------------ | ---------------------------- |
| **Bubble Sort** (optimized) | **O(n)**     | O(n²)                | O(n²)        | Early exit when no swaps     |
| **Bubble Sort** (normal)    | O(n²)        | O(n²)                | O(n²)        | Always compares              |
| **Selection Sort**          | O(n²)        | O(n²)                | O(n²)        | Always scans entire array    |
| **Insertion Sort**          | **O(n)**     | O(n²)                | O(n²)        | Shifting depends on disorder |
| **Merge Sort**              | O(n log n)   | O(n log n)           | O(n log n)   | Divide & conquer             |
| **Heap Sort**               | O(n log n)   | O(n log n)           | O(n log n)   | Heap property maintained     |
space complexity of all array operations is o(1) except merge sort which has o(n)
5-reverse array,forward and reverse traversal,find sum,product etc

Linked List

Singly 
Double
Circular
All list have Following basic operations
Insertion(head,tail,position)
Deletion(head,tail,position)
SearchAndUpdate
Merge
SplitAndSort
Reverse using recursion

Stack

both Static (arrays) and dynamic (linked list)
Opertion (peek,push,pop,empty,full)

Queue
both Static (arrays) and dynamic (linked list)
Opertion (front,enqueue(rear end),dequeue(front end),empty,full)
Normal queue 
Double Ended queue
Circular queue
Prority Queue

Tree 
BST(insertion,deletion,searching,traversals(BFS->level order,DFS(pre,in,post)))
MST(using prims and kruskals)

Heap
min heap,max heap,heapify ,heap sort details are in heap folder
Graph
constructing a graph using adjacency linked list or vector 
traversals bfs and dfs 
dijekstra for calculating shortest path to each node

Hashing
its details are in scrrenshot with in its folder 

Apna College and some videos 



Good — this is actually a **solid syllabus**, not beginner fluff.
Now I’ll do what most resources *don’t*:
👉 **attach time & space complexity to EVERYTHING**
👉 **state when to use what (real scenarios)**
👉 **not miss anything you listed**

I’ll **keep your README structure intact** and **add info under each item**.
Think of this as an **exam + interview + practical reference**.

---

# 📘 DATA STRUCTURES & ALGORITHMS – README (with Complexity & Usage)

---

## 🔹 ARRAY

### 1. Insertion

* **At end**

  * Time: `O(1)` (if space available)
  * Space: `O(1)`
* **At beginning / middle**

  * Time: `O(n)` (shifting required)
  * Space: `O(1)`

✅ **Efficient when**:

* Frequent access by index
* Insertions mostly at the end

❌ **Avoid when**:

* Too many insertions/deletions in middle

---

### 2. Deletion

* **At end**: `O(1)`
* **At beginning / middle**: `O(n)` (shifting)

Space: `O(1)`

---

### 3. Searching

* **Linear Search**

  * Time: `O(n)`
  * Space: `O(1)`
  * Works on **unsorted arrays**

* **Binary Search**

  * Time: `O(log n)`
  * Space: `O(1)`
  * **Requires sorted array**

✅ Use binary search when:

* Data is sorted
* Fast lookup needed

---

### 4. Sorting

| Algorithm | Best       | Avg        | Worst      | Space | Stable |
| --------- | ---------- | ---------- | ---------- | ----- | ------ |
| Bubble    | O(n)       | O(n²)      | O(n²)      | O(1)  | Yes    |
| Selection | O(n²)      | O(n²)      | O(n²)      | O(1)  | No     |
| Insertion | O(n)       | O(n²)      | O(n²)      | O(1)  | Yes    |
| Merge     | O(n log n) | O(n log n) | O(n log n) | O(n)  | Yes    |

✅ Use:

* **Insertion** → nearly sorted arrays
* **Merge** → large datasets, stable sorting needed

---

### 5. Other Array Operations

* Reverse: `O(n)`
* Traversal (forward/reverse): `O(n)`
* Sum / Product / Max / Min: `O(n)`
* Space: `O(1)`

---

## 🔹 LINKED LIST

### Singly / Doubly / Circular

#### Insertion

| Position | Time  |
| -------- | ----- |
| Head     | O(1)  |
| Tail     | O(1)* |
| Position | O(n)  |

(*O(1) tail only if tail pointer maintained)

---

#### Deletion

| Position | Time                   |
| -------- | ---------------------- |
| Head     | O(1)                   |
| Tail     | O(n) (SLL), O(1) (DLL) |
| Position | O(n)                   |

---

#### Searching & Updating

* Time: `O(n)`
* Space: `O(1)`

---

#### Merge

* Time: `O(n + m)`
* Space: `O(1)` (if pointer-based)

---

#### Split

* Time: `O(n)`
* Space: `O(1)`

---

#### Reverse (Recursion)

* Time: `O(n)`
* Space: `O(n)` (call stack)

---

✅ **Linked List best when**:

* Frequent insertions/deletions
* Dynamic size required

❌ **Bad when**:

* Random access needed (no indexing)

---

## 🔹 STACK

### Static Stack (Array)

* Push: `O(1)`
* Pop: `O(1)`
* Peek: `O(1)`
* Overflow possible

### Dynamic Stack (Linked List)

* Push: `O(1)`
* Pop: `O(1)`
* No overflow (until memory full)

Space:

* Array: `O(n)`
* Linked list: `O(n)` + pointer overhead

---

## 🔹 QUEUE

### Normal Queue

* Enqueue: `O(1)`
* Dequeue: `O(1)`
* Problem: space wastage in array

---

### Circular Queue

* Enqueue: `O(1)`
* Dequeue: `O(1)`
* Efficient memory usage

---

### Double Ended Queue (Deque)

* Insert/Delete front & rear: `O(1)`

---

### Priority Queue

* Insert: `O(log n)`
* Delete: `O(log n)`
* Implemented using heap

✅ Used in:

* CPU scheduling
* Dijkstra
* Event simulation

---

## 🔹 TREE

### Binary Search Tree (BST)

| Operation | Best     | Worst |
| --------- | -------- | ----- |
| Insert    | O(log n) | O(n)  |
| Delete    | O(log n) | O(n)  |
| Search    | O(log n) | O(n)  |

Worst case = skewed tree

---

### Traversals

* Inorder / Preorder / Postorder: `O(n)`
* Level Order (BFS): `O(n)`
* Space (queue/recursion): `O(n)`

---

### Minimum Spanning Tree (MST)

#### Prim’s Algorithm

* Using priority queue: `O(E log V)`
* Best for **dense graphs**

#### Kruskal’s Algorithm

* Time: `O(E log E)`
* Uses DSU
* Best for **sparse graphs**

---

## 🔹 HEAP

### Min Heap / Max Heap

* Insert: `O(log n)`
* Delete: `O(log n)`
* Get Min/Max: `O(1)`

---

### Heapify

* Time: `O(log n)`

---

### Heap Sort

* Time: `O(n log n)`
* Space: `O(1)`
* Not stable

---

## 🔹 GRAPH

### Representation

* Adjacency List

  * Space: `O(V + E)`
* Adjacency Matrix

  * Space: `O(V²)`

---

### Traversals

* BFS: `O(V + E)`
* DFS: `O(V + E)`

---

### Dijkstra

* Time: `O(E log V)`
* Space: `O(V)`
* ❌ Does not support negative weights

---

## 🔹 HASHING

### Operations

* Insert: `O(1)` average
* Search: `O(1)` average
* Delete: `O(1)` average

Worst case: `O(n)` (collision)

---

### Collision Handling

* Chaining
* Open Addressing (Linear, Quadratic, Double Hashing)

---
Table Structure:

*   **Columns (Data Structures):**
    *   Unordered array
    *   Ordered array
    *   Binary Search Tree
    *   Separate hashing
    *   Linear probing

*   **Rows (Operations):**
    *   Search
    *   Insertion
    *   Deletion

***

### Explanation of Average Case Efficiency:

#### 1. **Unordered Array**

*   **Search:** (O(n)) — Need to scan all elements.
*   **Insertion:** (O(1)) — Insert at the end.
*   **Deletion:** (O(n)) — Find element first, then remove.

#### 2. **Ordered Array**

*   **Search:** (O(\log n)) — Binary search possible.
*   **Insertion:** (O(n)) — Must shift elements to maintain order.
*   **Deletion:** (O(n)) — Must shift elements after removal.

#### 3. **Binary Search Tree (Balanced)**

*   **Search:** (O(\log n))
*   **Insertion:** (O(\log n))
*   **Deletion:** (O(\log n))

#### 4. **Separate Hashing (Hash Table with Chaining)**

*   **Search:** (O(1)) average (depends on load factor).
*   **Insertion:** (O(1)) average.
*   **Deletion:** (O(1)) average.

#### 5. **Linear Probing (Open Addressing)**

*   **Search:** (O(1)) average (but can degrade with clustering).
*   **Insertion:** (O(1)) average.
*   **Deletion:** (O(1)) average (special handling needed)..
