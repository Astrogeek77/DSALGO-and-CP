class Node {
  constructor(val) {
    this.next = null;
    this.val = val;
  }
}

class Stack {
  constructor() {
    this.first = null;
    this.last = null;
    this.size = 0;
  }

  isEmpty() {
    return this.size === 0;
  }

  push(val) {
    let newNode = new Node(val);
    if (this.first == null) {
      this.first = newNode;
      this.last = newNode;
    } else {
      let curr = this.first;
      this.first = newNode;
      newNode.next = curr;
    }
    this.size++;
    return this.size;
  }

  pop() {
    let nodeToBeDeleted = this.first;
    if (this.size == 0) return null;
    else if (this.size == 1) {
      this.first = null;
      this.last = null;
    } else {
      let nextNode = nodeToBeDeleted.next;
      this.first = nextNode;
    }
    this.size--;
    return nodeToBeDeleted;
  }
}

const stack = new Stack();
stack.push(1);
stack.push(2);
stack.push(3);

// stack.pop()

// Stack using two Queue - 1

class Stack {
  constructor() {
    this.q1 = [];
    this.q2 = [];
  }
  push(val) {
    this.q2.push(val);

    while (this.q1.length > 0) {
      this.q2.push(this.q1[0]);
      this.q1.shift();
    }

    let q = this.q1;
    this.q1 = this.q2;
    this.q2 = q;

    return this;
  }
  pop() {
    if (this.q1.length == 0) return null;
    return this.q1.shift();
  }
}

// Stack using two Queues - 2

class Stack {
  constructor() {
    this.q1 = new Queue();
    this.q2 = new Queue();
  }
  push(val) {
    this.q2.enqueue(val);

    while (this.q1.size > 0) {
      this.q2.enqueue(this.q1.dequeue());
    }

    let q = this.q1;
    this.q1 = this.q2;
    this.q2 = q;

    return this;
  }
  pop() {
    if (this.q1.size == 0) return null;
    return this.q1.dequeue();
  }
}

// QUEUE AND NODE HAVE BEEN IMPLEMENTED FOR YOU

class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.first = null;
    this.last = null;
    this.size = 0;
  }
  enqueue(data) {
    var node = new Node(data);

    if (!this.first) {
      this.first = node;
      this.last = node;
    } else {
      this.last.next = node;
      this.last = node;
    }

    return ++this.size;
  }

  dequeue() {
    if (!this.first) return null;

    var temp = this.first;
    if (this.first == this.last) {
      this.last = null;
    }
    this.first = this.first.next;
    this.size--;
    return temp.value;
  }
}
