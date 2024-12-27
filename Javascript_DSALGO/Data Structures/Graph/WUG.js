// simple priority queue
class SPQ {
  constructor() {
    this.values = [];
  }

  enqueue(val, priority) {
    this.values.push({ val, priority });
    this.sort();
  }

  dequeue() {
    return this.values.shift();
  }

  sort() {
    this.values.sort((a, b) => a.priority - b.priority);
  }
}

class PQNode {
  constructor(val, priority) {
    this.val = val;
    this.priority = priority;
  }
}

class PQ {
  constructor() {
    this.values = [];
    this.size = this.values.length;
  }

  setSize() {
    this.size = this.values.length;
  }

  enqueue(val, priority) {
    let newNode = new PQNode(val, priority);
    this.values.push(newNode);
    this.size = this.values.length;

    this.bubbleUp();
  }

  bubbleUp() {
    // idx of the new element
    let idx = this.values.length - 1;
    // value of new element
    const el = this.values[idx];

    // loop
    while (idx > 0) {
      let parentIdx = Math.floor((idx - 1) / 2),
        parentEl = this.values[parentIdx];

      // if element is already less than or equal to parent, then no need to swap
      if (el.priority >= parentEl.priority) break;

      // else we swap the values
      this.values[parentIdx] = el;
      this.values[idx] = parentEl;

      // update the idx of the element after swap
      idx = parentIdx;
    }
  }

  dequeue() {
    // get the last idx element and max element to remove ie root
    let minEl = this.values[0];
    let lastEl = this.values.pop();

    if (this.values.length > 0) {
      // set root as the last el
      this.values[0] = lastEl;

      this.size = this.values.length;

      // BubbleDown Process to stablize the heap
      this.bubbleDown();
    }

    this.setSize();
    // return max El
    return minEl;
  }

  bubbleDown() {
    let idx = 0,
      el = this.values[0];

    while (true) {
      let leftChildIdx = 2 * idx + 1,
        rightChildIdx = 2 * idx + 2;
      let leftChild, rightChild;
      let swap = null;

      // compare left child with the element, if greator then el set swap to left child idx
      if (leftChildIdx < this.size) {
        leftChild = this.values[leftChildIdx];
        if (leftChild.priority < el.priority) swap = leftChildIdx;
      }
      // compare right Child with the element, if greator then el set swap to left child or if
      // both children are greator then element and right child is greator than left child, set
      // swap to right child idx
      if (rightChildIdx < this.size) {
        rightChild = this.values[rightChildIdx];
        if (
          (swap === null && rightChild.priority < el.priority) ||
          (swap !== null && rightChild.priority < leftChild.priority)
        ) {
          swap = rightChildIdx;
        }
      }
      if (swap === null) break;
      this.values[idx] = this.values[swap];
      this.values[swap] = el;

      idx = swap;
    }
  }

  getAscHeapSort() {
    var result = [];

    while (this.values.length > 0) {
      result.push(this.dequeue());
    }

    return result;
  }
}

// Weighted Undirected Graph
class WUG {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
  }

  addEdge(v1, v2, w) {
    this.adjacencyList[v1].push({ node: v2, weight: w });
    this.adjacencyList[v2].push({ node: v1, weight: w });
  }

  removeEdge(v1, v2) {
    this.adjacencyList[v1] = this.adjacencyList[v1].filter(
      (el) => el.node !== v2
    );
    this.adjacencyList[v2] = this.adjacencyList[v2].filter(
      (el) => el.node !== v1
    );
  }

  // Dijakstra's shortest path algorithm
  DSPA(start, end) {
    const distances = {};
    // const nodes = new SPQ()
    const nodes = new PQ();
    const prev = {};
    let smallest;
    let shortestPath = [];

    // init state

    // for every vertex set distance to infinity except the start
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

      // if we reach end, buld path
      if (smallest === end) {
        // build path
        // console.log(distances)
        // console.log(prev)

        while (prev[smallest]) {
          shortestPath.push(smallest);
          smallest = prev[smallest];
        }
        break;
      }

      if (smallest || distances[smallest] !== Infinity) {
        // for every neighbour
        for (let nieghbour in this.adjacencyList[smallest]) {
          let neighNode = this.adjacencyList[smallest][nieghbour];

          // calculate distances to neighbouring nodes
          let candidateDis = distances[smallest] + neighNode.weight;

          // if candidate distance is less than stored distance of neigh node
          let nextNeighNode = neighNode.node;
          if (candidateDis < distances[nextNeighNode]) {
            // update new smallest distance to reach the nextNeighNode
            distances[nextNeighNode] = candidateDis;
            // storing in prev the previous node we followed reach nextNeighNode,
            // to construct shortest path in end
            prev[nextNeighNode] = smallest;
            // enqueue the nextNeighNode in nodes PQ with new priority
            nodes.enqueue(nextNeighNode, candidateDis);
          }
        }
      }
    }
    return shortestPath.concat(smallest).reverse();
  }

  // sort
  topSort() {}
}

const graph = new WUG();

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

graph.DSPA("A", "E");
