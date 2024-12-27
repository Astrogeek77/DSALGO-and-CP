// unwieghted undirected graph

class UG {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
  }

  addEdge(v1, v2) {
    this.adjacencyList[v1].push(v2);
    this.adjacencyList[v2].push(v1);
  }

  removeEdge(v1, v2) {
    this.adjacencyList[v1] = this.adjacencyList[v1].filter((el) => el !== v2);
    this.adjacencyList[v2] = this.adjacencyList[v2].filter((el) => el !== v1);
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
}

var graph = new UG();

// graph.addVertex("Del")
// graph.addVertex("Hyd")
// graph.addVertex("Che")
// graph.addVertex("Kol")
// graph.addVertex("Noi")

// graph.addEdge("Del", "Hyd")
// graph.addEdge("Che", "Del")
// graph.addEdge("Del", "Noi")
// graph.addEdge("Del", "Kol")

graph.addVertex("A");
graph.addVertex("B");
graph.addVertex("C");
graph.addVertex("D");
graph.addVertex("E");
graph.addVertex("F");

graph.addEdge("A", "B");
graph.addEdge("A", "C");
graph.addEdge("B", "D");
graph.addEdge("C", "E");
graph.addEdge("D", "E");
graph.addEdge("D", "F");
graph.addEdge("E", "F");

// console.log(graph)

// graph.removeEdge("Del", "Kol")
// console.log(graph)

// graph.removeVertex("Del")
// console.log(graph)

console.log(graph.DFSRecursive("A"));

console.log(graph.DFSIterative("A"));

console.log(graph.BFS("A"));
