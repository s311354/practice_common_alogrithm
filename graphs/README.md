## Overview of Graph ##

#### The concept of Directed Graph ####
In mathematics, and more specifically in graph theory, a directed graph is the graph that is made up a set of vertices connected by directed edges often called arcs, i.e., a set of objects (called vertices or nodes) that are connected together, where all the edges are directed from one vertex to another. A directed graph is sometimes called a digraph or a directed network. In contrast, a graph where the edges are bidirectional is called an undirected graph.

In this simple program, I recapped and practiced how to implement the directed graph with C++. The code initially extracted from [Practice Directed Graph][directedgraph] and then reworked. The basic functions for the directed graph are a follows:
- BFS (Breadth-first search): use queue and traverse all the connected nodes
- DFS (Depth-first search): use stack and traverse all the connected nodes
- Detect Cycle in a Directed Graph: check whether the graph contains a cycle or not
- Iterate in a Directed Graph:  pointing to all of vertices in the directed graph

The corresponding result:
<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">DFS: 0 5 8 1 2 6 4 1 2 3 4 5 6 7 8
BFS: 0 1 5 2 8 4 6 1 2 3 4 5 6 7 8 </span></code></pre></div>

#### Reference ####
[1] [Directed graph](https://en.wikipedia.org/wiki/Directed_graph)

[2] [An Introduction to Graph Theory and Network Analysis (with Python codes)](https://www.analyticsvidhya.com/blog/2018/04/introduction-to-graph-theory-network-analysis-python-codes/)

[directedgraph]:https://github.com/jwasham/practice-cpp/tree/master/graphs "https://github.com/jwasham/practice-cpp/tree/master/graphs"
