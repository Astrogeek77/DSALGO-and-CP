class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
    this.prev = null;
  }
}

class DoublyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  decLen() {
    this.length -= 1;
  }
  incLen() {
    this.length += 1;
  }
  zeroLen() {
    this.length = 0;
  }
  getLength() {
    return this.length;
  }
  isEmpty() {
    return this.length === 0;
  }

  printList(reverse = false) {
    if (!reverse) {
      let curr = this.head;
      let str = "";
      while (curr) {
        str += curr.val + "<->";
        curr = curr.next;
      }
      if (str == "") console.log("Empty Linked List");
      else console.log(str);
    } else {
      let curr = this.tail;
      let str = "";
      while (curr) {
        str += curr.val + "<->";
        curr = curr.prev;
      }
      if (str == "") console.log("Empty Linked List");
      else console.log(str);
    }
  }

  getPos(val) {
    let pos = 0,
      curr = this.head;
    while (curr) {
      if (curr.val === val) return pos;
      curr = curr.next;
      pos++;
    }
    return -1;
  }

  search(val) {
    let curr = this.head;
    while (curr) {
      if (curr.val == val) return curr;
      curr = curr.next;
    }
    return undefined;
  }

  push(val) {
    let newNode = new Node(val);
    if (this.head == null) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }

    this.incLen();
    return this;
  }

  pop() {
    if (this.length <= 0) return undefined;
    else if (this.length == 1) {
      let nodeToBeDeleted = this.head;
      this.head = null;
      this.tail = null;

      this.decLen();
      return nodeToBeDeleted;
    } else {
      let newTail = this.tail.prev,
        nodeToBeDeleted = this.tail;
      this.tail.prev = null;
      newTail.next = null;
      this.tail = newTail;

      this.decLen();
      return nodeToBeDeleted;
    }
  }

  unshift(val) {
    if (this.length == 0) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      let newNode = new Node(val);
      newNode.next = this.head;
      this.head.prev = newNode;
      this.head = newNode;
    }
    this.incLen();
    return this;
  }

  shift() {
    if (this.length == 1) {
      let nodeToBeDeleted = this.head;
      this.head = null;
      this.tail = null;
    } else {
      let curr = this.head.next;
      this.head.next = null;
      this.head = curr;
      curr.prev = null;
    }
    this.decLen();
    return this;
  }

  get(pos) {
    if (pos >= this.length || pos < 0) return undefined;

    if (pos <= this.length / 2) {
      let curr = this.head;
      while (pos--) curr = curr.next;
      return curr;
    } else {
      let idx = this.length - 1;
      let curr = this.tail;
      while (idx != pos) {
        curr = curr.prev;
        idx--;
      }
      return curr;
    }
  }

  set(pos, val) {
    let foundNode = this.get(pos);

    if (foundNode) {
      foundNode.val = val;
      return true;
    }
    return false;
  }

  insert(pos, val) {
    if (pos > this.length) return false;
    else if (pos == this.length) return !!this.push(val);
    else if (pos == 0) return !!this.unshift(val);
    else {
      let newNode = new Node(val);
      // let curr = this.head, prev = this.head

      // while(pos--){
      //   prev = curr
      //   curr = curr.next
      // }

      // prev.next = newNode
      // newNode.next = curr

      let curr = this.get(pos),
        prevNode = curr.prev;
      prevNode.next = newNode;
      newNode.next = curr;
      curr.prev = newNode;
      newNode.prev = prevNode;

      this.incLen();
      return true;
    }
  }

  remove(val) {
    // let targetNode = this.search(val)
    // if(!targetNode) return false

    // if(this.head.val == val) this.head = this.head.next
    // else {
    //   let curr = this.head
    //   while(curr){
    //     if(curr.next && curr.next.val == val) {
    //       curr.next = curr.next.next
    //       break
    //     }
    //     else curr = curr.next
    //   }

    // }
    // this.decLen()
    // return true

    let pos = this.getPos(val);
    if (pos == -1) return false;
    else {
      return this.removeAt(pos);
    }
  }

  removeAt(pos) {
    if (pos < 0 || pos >= this.length) {
      return false;
    } else if (pos == 0) {
      return !!this.shift();
    } else if (pos == this.length - 1) {
      return !!this.pop();
    } else {
      let curr = this.get(pos);
      let nextNode = curr.next;
      let prevNode = nextNode.prev;

      prevNode.next = nextNode;
      nextNode.prev = prevNode;

      curr.next = null;
      curr.prev = null;

      this.decLen();
      return true;
    }
  }

  reverse() {
    let prev = null,
      curr = this.head,
      next = null;

    while (curr) {
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }

    this.printList(prev);
    return prev;
  }

  rotate(num) {
    if (num > this.length) return;
    if (num < 0) num = this.length + num;

    let curr = this.head,
      prev = null;
    while (num--) {
      prev = curr;
      curr = curr.next;
    }
    let oldHead = this.head;
    this.head = curr;
    this.tail.next = oldHead;
    this.tail = prev;
    prev.next = null;
  }
}

let l = new DoublyLinkedList();
l.push(1);
l.push(2);
l.push(3);

console.log(l);
l.printList();

// console.log(l.pop())
// l.printList()
// console.log(l.pop())
// l.printList()
// console.log(l.pop())
// l.printList()
// console.log(l.pop())
// l.printList()

// l.shift(0)
// console.log(l)
// l.printList()

// l.unshift()
// console.log(l)
// l.printList()

// console.log(l.get(1))
// console.log(l.set(2, 'Gautam'))

console.log(l.insert(0, "Gautam"));
console.log(l);
l.printList();

l.printList(true);
