// unwighted directed graph
class DG {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
  }

  addEdge(v1, v2) {
    // add edge v1 -> v2
    this.adjacencyList[v1].push(v2);
  }

  removeEdge(v1, v2) {
    // remove edge v1 -> v2
    this.adjacencyList[v1] = this.adjacencyList[v1].filter((el) => el !== v2);
  }

  removeVertex(v1) {
    let connections = this.adjacencyList[v1];

    for (let conn of connections) {
      this.removeEdge(v1, conn);
    }

    delete this.adjacencyList[v1];
  }

  DFSRecursive(start) {
    let res = [],
      vis = {};

    // function DFS(v)
    // {
    //     if(!v)
    //         return

    //     vis[v] = true
    //     res.push(v)

    //     for(let neighbours in this.adjacencyList[v])
    //     {
    //         if(!vis[neighbours])
    //             DFS(neighbours)
    //     }
    // }
    // DFS(start)

    let adjacencyList = this.adjacencyList;
    (function DFS(v) {
      if (!v) return null;
      vis[v] = true;
      res.push(v);

      adjacencyList[v].forEach((nieghbour) => {
        if (!vis[nieghbour]) {
          return DFS(nieghbour);
        }
      });
    })(start);

    return res;
  }

  DFSIterative(start) {
    let stack = [],
      res = [],
      vis = {};
    stack.push(start);

    while (stack.length > 0) {
      let v = stack.pop();
      if (!vis[v]) {
        res.push(v);
        vis[v] = true;

        this.adjacencyList[v].forEach((nieghbour) => {
          stack.push(nieghbour);
        });
      }
    }

    return res;
  }

  BFS(start) {
    let queue = [],
      res = [],
      vis = {};
    queue.push(start);

    while (queue.length > 0) {
      let v = queue.shift();
      if (!vis[v]) {
        res.push(v);
        vis[v] = true;

        this.adjacencyList[v].forEach((nieghbour) => {
          queue.push(nieghbour);
        });
      }
    }

    return res;
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

var dg = new DG();

// dg.addVertex("Del")
// dg.addVertex("Hyd")
// dg.addVertex("Che")
// dg.addVertex("Kol")
// dg.addVertex("Noi")

// dg.addEdge("Del", "Hyd")
// dg.addEdge("Che", "Del")
// dg.addEdge("Del", "Noi")
// dg.addEdge("Del", "Kol")

dg.addVertex("A");
dg.addVertex("B");
dg.addVertex("C");
dg.addVertex("D");
dg.addVertex("E");
dg.addVertex("F");

dg.addEdge("A", "B");
dg.addEdge("A", "C");
dg.addEdge("B", "C");
dg.addEdge("B", "D");
dg.addEdge("C", "E");
dg.addEdge("D", "E");
dg.addEdge("D", "F");
dg.addEdge("E", "F");

// console.log(dg)

// dg.removeEdge("Del", "Kol")
// console.log(dg)

// dg.removeVertex("Del")
// console.log(dg)

console.log(dg.DFSRecursive("A"));

console.log(dg.DFSIterative("A"));

console.log(dg.BFS("A"));

console.log("Topological Sort (BFS): ", dg.topologicalSortBFS());
console.log("Topological Sort (DFS): ", dg.topologicalSortDFS());
