class WDG {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
  }

  addEdge(v1, v2, w) {
    this.adjacencyList[v1].push({ node: v2, weight: w });
  }

  removeEdge(v1, v2) {
    this.adjacencyList[v1] = this.adjacencyList[v1].filter(
      (el) => el.node !== v2
    );
  }

  // Dijakstra's shortest path algorithm
  DSPA(start, end) {
    const distances = {};
    const nodes = new PQ();
    const prev = {};
    let smallest;
    let shortestPath = [];

    // init state
    for (let v in this.adjacencyList) {
      if (v === start) {
        distances[v] = 0;
        nodes.enqueue(v, 0);
      } else {
        distances[v] = Infinity;
        nodes.enqueue(v, Infinity);
      }
      prev[v] = null;
    }

    // visit every node
    while (nodes.values.length) {
      smallest = nodes.dequeue().val;

      if (smallest === end) {
        while (prev[smallest]) {
          shortestPath.push(smallest);
          smallest = prev[smallest];
        }
        break;
      }

      if (smallest || distances[smallest] !== Infinity) {
        for (let neighbour in this.adjacencyList[smallest]) {
          let neighNode = this.adjacencyList[smallest][neighbour];

          let candidateDis = distances[smallest] + neighNode.weight;
          let nextNeighNode = neighNode.node;
          if (candidateDis < distances[nextNeighNode]) {
            distances[nextNeighNode] = candidateDis;
            prev[nextNeighNode] = smallest;
            nodes.enqueue(nextNeighNode, candidateDis);
          }
        }
      }
    }
    console.log("Minimum total cost: " + distances[end]);
    return shortestPath.concat(smallest).reverse();
  }

  // Topological sort using BFS (Kahn's algorithm)
  topologicalSortBFS() {
    const inDegree = {};
    const queue = [];
    const result = [];

    // Initialize in-degree
    for (let vertex in this.adjacencyList) {
      inDegree[vertex] = 0;
    }

    // Calculate in-degree
    for (let vertex in this.adjacencyList) {
      for (let neighbor of this.adjacencyList[vertex]) {
        inDegree[neighbor.node] = (inDegree[neighbor.node] || 0) + 1;
      }
    }

    // Collect all nodes with in-degree 0
    for (let vertex in inDegree) {
      if (inDegree[vertex] === 0) {
        queue.push(vertex);
      }
    }

    // Process the queue
    while (queue.length) {
      let vertex = queue.shift();
      result.push(vertex);

      for (let neighbor of this.adjacencyList[vertex]) {
        inDegree[neighbor.node]--;
        if (inDegree[neighbor.node] === 0) {
          queue.push(neighbor.node);
        }
      }
    }

    if (result.length === Object.keys(this.adjacencyList).length) {
      return result;
    } else {
      throw new Error("Graph has a cycle!");
    }
  }

  // Topological sort using DFS
  topologicalSortDFS() {
    const visited = {};
    const stack = [];

    const dfs = (vertex) => {
      visited[vertex] = true;
      for (let neighbor of this.adjacencyList[vertex]) {
        if (!visited[neighbor.node]) {
          dfs(neighbor.node);
        }
      }
      stack.push(vertex);
    };

    for (let vertex in this.adjacencyList) {
      if (!visited[vertex]) {
        dfs(vertex);
      }
    }

    return stack.reverse();
  }
}

// Example usage
const graph = new WDG();

graph.addVertex("A");
graph.addVertex("B");
graph.addVertex("C");
graph.addVertex("D");
graph.addVertex("E");
graph.addVertex("F");

graph.addEdge("A", "B", 4);
graph.addEdge("A", "C", 2);
graph.addEdge("B", "E", 3);
graph.addEdge("C", "D", 2);
graph.addEdge("C", "F", 4);
graph.addEdge("D", "E", 3);
graph.addEdge("D", "F", 1);
graph.addEdge("E", "F", 1);

console.log("Topological Sort (BFS): ", graph.topologicalSortBFS());
console.log("Topological Sort (DFS): ", graph.topologicalSortDFS());
