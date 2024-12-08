class MaxBinaryHeap {
  constructor() {
    this.values = [41, 39, 33, 18, 27, 12];
    this.size = this.values.length;
  }

  setSize() {
    this.size = this.values.length;
  }

  insert(val) {
    this.values.push(val);
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
      if (el <= parentEl) break;

      // else we swap the values
      this.values[parentIdx] = el;
      this.values[idx] = parentEl;

      // update the idx of the element after swap
      idx = parentIdx;
    }
  }

  extractMax() {
    // get the last idx element and max element to remove ie root
    let maxEl = this.values[0];
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
    return maxEl;
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
        if (leftChild > el) swap = leftChildIdx;
      }
      // compare right Child with the element, if greator then el set swap to left child or if
      // both children are greator then element and right child is greator than left child, set
      // swap to right child idx
      if (rightChildIdx < this.size) {
        rightChild = this.values[rightChildIdx];
        if (
          (swap === null && rightChild > el) ||
          (swap !== null && rightChild > leftChild)
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
    
    getDescHeapSort() {
        var result = []

        while (this.values.length > 0) {
            result.push(this.extractMax())
        }

        return result
    }
}

var heap = new MaxBinaryHeap();

heap.insert(55);
// console.log(heap);

// console.log(heap.extractMax());
// console.log(heap);

// console.log(heap.extractMax());
// console.log(heap);

// console.log(heap.extractMax());
// console.log(heap);

// console.log(heap.extractMax());
// console.log(heap);

// console.log(heap.extractMax());
// console.log(heap);

// console.log(heap.extractMax());
// console.log(heap);

// console.log(heap.extractMax());
// console.log(heap);

console.log(heap.getDescHeapSort())
