# Leetcode-3203.-Find-Minimum-Diameter-After-Merging-Two-Trees
# 🌳 Minimum Diameter After Merging Two Trees

This project implements an elegant and optimized solution to **find the minimum possible diameter** after connecting two unrooted trees. It's based on **Breadth-First Search (BFS)** and key graph insights about tree diameters.

---

## 🔍 Problem Overview

Given two trees represented by edge lists, the goal is to merge them by adding **just one edge**, such that the **diameter** of the resulting tree is minimized.

> The **diameter** of a tree is the longest shortest-path between any two nodes.

---

## 💡 Intuition & Approach

1. **Compute individual tree diameters** using BFS.
2. **Identify centers** of both trees (midpoints of their diameters).
3. **Connect their centers** to get the optimal merge point.
4. The new diameter is:
ceil(d1 / 2) + ceil(d2 / 2) + 1
where `d1` and `d2` are the original diameters.

---

## 📦 Features

- 🔁 **Efficient BFS** to compute diameter
- 🌲 **Tree center analysis**
- 📈 Supports large inputs due to optimal logic
- 🧪 Easy to test with custom edge lists

---

## 📌 Example

```cpp
vector<vector<int>> tree1 = {{0,1}, {1,2}};
vector<vector<int>> tree2 = {{0,1}, {1,2}, {2,3}};

Solution sol;
int result = sol.minimumDiameterAfterMerge(tree1, tree2);
cout << result << endl; // Output: 4
🚀 Getting Started
Prerequisites
C++ Compiler (e.g. g++, clang++)

Basic understanding of graphs and BFS

