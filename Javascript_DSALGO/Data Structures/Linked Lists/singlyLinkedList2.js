class Node{
  constructor(val){
    this.val = val
    this.next = null
  }
}

class SinglyLinkedList {
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

  printList(curr = this.head) {
    let str = "";
    while (curr) {
      str += curr.val + "->";
      curr = curr.next;
    }
    console.log(str);
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

  // push node to the last
  push(val) {
    let newNode = new Node(val);
    if (this.head == null) {
      this.head = newNode;
      this.tail = this.head;
    } else {
      // let curr = head.next
      // while(curr && curr.next) curr = curr.next
      // curr.next = newnode
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.incLen();
    return this;
  }

  search(val) {
    let curr = this.head;
    while (curr) {
      if (curr.val == val) return curr;
      curr = curr.next;
    }
    return null;
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
      let prev = this.get(pos - 1);
      let nodeToBeRemoved = prev.next;
      prev.next = nodeToBeRemoved.next;

      this.decLen();
      return true;
    }
  }

  pop() {
    if (this.length <= 0) return undefined;

    if (this.head.next == null) {
      let curr = this.head;
      this.head = null;
      this.tail = null;
      this.zeroLen();
      return curr;
    }

    let curr = this.head,
      prev = this.head;

    // while(curr){
    //   if(curr.val == tail.val && curr.next == null){
    //     break
    //   } else curr = curr.next
    // }

    while (curr.next) {
      prev = curr;
      curr = curr.next;
    }

    prev.next = null;
    this.tail = prev;

    this.decLen();
    return curr;
  }

  shift() {
    if (this.length <= 0) return undefined;

    if (this.head.next == null) {
      let curr = this.head;
      this.head = null;
      this.tail = null;
      this.zeroLen();
      return curr;
    }

    let newHead = this.head.next;
    let oldHead = this.head;
    oldHead.next = null;
    this.head = newHead;

    this.decLen();
    return oldHead;
  }

  unshift(val) {
    let newHead = new Node(val);

    if (!this.head) {
      this.head = newHead;
      this.tail = this.head;
    } else {
      newHead.next = this.head;
      this.head = newHead;
    }

    this.incLen();
    return this.head;
  }

  get(pos) {
    if (pos >= this.length || pos < 0) return undefined;

    let curr = this.head;

    while (pos--) {
      curr = curr.next;
    }

    return curr;
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

      let prev = this.get(pos - 1),
        temp = prev.next;
      prev.next = newNode;
      newNode.next = temp;

      this.incLen();
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

let list = new SinglyLinkedList()
// console.log(list)


list.push(23)
list.push(12)
list.push(99)
// console.log(list)





// console.log(list.search(12))
// console.log(list.search(2))


// console.log(list)
// list.remove(23)
// console.log(list)


// console.log(list.pop())
// console.log(list)
// console.log(list.pop())
// console.log(list)
// console.log(list.pop())
// console.log(list)
// console.log(list.pop())
// console.log(list)

list.unshift("Jain")
// console.log(list)
list.unshift("Gautam")
// console.log(list)



// console.log(list.shift())
// console.log(list)
// console.log(list.shift())
// console.log(list)
// console.log(list.shift())
// console.log(list)
// console.log(list.shift())
// console.log(list)

list.printList()
// console.log(list.get(0))
// list.reverse()

// console.log(list.set(1, 'Gautam'))
// list.printList()

// console.log(list)
// list.insert(3, 'King')
// list.printList()

// console.log(list.remove('Gautam'))
list.removeAt(0)
console.log(list)
list.printList()

