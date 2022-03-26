# Project Proposal

# AIM:
Given the road networks dataset of a region, our goal is to convert it into a graph and then generate a general search tool to perform various kinds of operations on it including- finding the shortest path from one node to another, finding shortest path between two nodes going through n other landmarks. Traverse the road network to search for a specific node or a feature. Also, we will try to find Strongly connected components of the graph to get connected landmarks.

# DATA ACQUISITION AND PROCESSING:
We’ll be using the California road network dataset from the following source https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm.

# Data Format:
The dataset clearly describes the format:
 Nodes (Node ID, longitude, latitude)
Edges (Edge ID, start Node ID, end Node ID, distance)gt
California's Points of Interest With Original Category Name (Category Name, Longitude, Latitude)
California's Points of Interest (Longitude, Latitude, Category ID)

# Data correction:
We’ll ensure that the start node ID and end node ID of edges are valid nodes
We’ll also ensure that all the columns are stored as an appropriate data type for example (longitude and latitude should be stored as a data type that supports negative values) while node ID should only be positive.

# GRAPH ALGORITHMS:
Function Input: We will input the data set by a CSV file for nodes, edges, points of interest, and merged points of interest. We only need to convert these inputs into a map/graph.
Function Output: We will store the data set as a graph with locations/landmarks as nodes, route/path as edges, and points of interest as locations/landmarks as those nodes. A BFS traversal is required to print out and display the map/graph. The Dijkstra’s algorithm will also be applied to calculate the minimum path between start and destination.

# Function Efficiency: 
Dijkstra’s algorithm will take a run time of O(nlogn + m). BFS Traversal of the entire map/graph will take a runtime of O(V + E ) O(V + E) O(V+E). V being number of vertices and E being number of edges. It will take O(V+E) memory.

# TIMELINE: 
	Week of 28th March: Organize the dataset and load it so that it is ready for use.
	Week of 4th April and 11th April: Start making the graphs with the organized data 
	Week of 18th April: Apply above mentioned algorithms to find the shortest path.
	Week of 25th April: Implement the shortest path through n landmarks.
	Week of 2nd May: Complete final optimizations, analyze time complexities,  and    prepare the documents to be submitted
