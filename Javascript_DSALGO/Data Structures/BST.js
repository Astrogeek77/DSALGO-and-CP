class Node {
  constructor(value) {
    this.value = value
    this.left = null
    this.right = null
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null
  }
  insert(value) {
    var newNode = new Node(value)
    if (this.root === null) {
      this.root = newNode
      return this
    }
    var current = this.root
    while (true) {
      if (value === current.value) return undefined
      if (value < current.value) {
        if (current.left === null) {
          current.left = newNode
          return this
        }
        current = current.left
      } else {
        if (current.right === null) {
          current.right = newNode
          return this
        }
        current = current.right
      }
    }
  }
  find(value) {
    if (this.root === null) return false
    var current = this.root,
      found = false
    while (current && !found) {
      if (value < current.value) {
        current = current.left
      } else if (value > current.value) {
        current = current.right
      } else {
        found = true
      }
    }
    if (!found) return undefined
    return current
  }
  contains(value) {
    if (this.root === null) return false
    var current = this.root,
      found = false
    while (current && !found) {
      if (value < current.value) {
        current = current.left
      } else if (value > current.value) {
        current = current.right
      } else {
        return true
      }
    }
    return false
  }

  BFS(root = this.root) {
    var node = root,
      queue = [],
      visited = []
    queue.push(node)

    while (queue.length) {
      // avoid variables in the loop - Colt Steele
      // let node = queue.shift()

      node = queue.shift()
      visited.push(node.value)

      if (node.left) queue.push(node.left)
      if (node.right) queue.push(node.right)
    }

    return visited
  }

  BFSReverse(root = this.root) {
    var node = root,
      queue = [],
      visited = []
    queue.push(node)

    while (queue.length) {
      // avoid variables in the loop - Colt Steele
      // let node = queue.shift()

      node = queue.shift()
      visited.push(node.value)

      if (node.right) queue.push(node.right)
      if (node.left) queue.push(node.left)
    }

    return visited
  }

  DFSPreorder(root = this.root) {
    var visited = []

    function traverse(curr) {
      visited.push(curr.value)
      if (curr.left) traverse(curr.left)
      if (curr.right) traverse(curr.right)
    }

    traverse(root)
    return visited
  }

  DFSInorder(root = this.root) {
    var visited = []

    function traverse(curr) {
      if (curr.left) traverse(curr.left)
      visited.push(curr.value)
      if (curr.right) traverse(curr.right)
    }

    traverse(root)
    return visited
  }

  DFSPostorder(root = this.root) {
    var visited = []

    function traverse(curr) {
      if (curr.left) traverse(curr.left)
      if (curr.right) traverse(curr.right)
      visited.push(curr.value)
    }

    traverse(root)
    return visited
  }

  DFSPreorderIterative(root = this.root) {
    var node = root,
      stack = [],
      visited = []
    stack.push(node)

    while (stack.length) {
      // avoid variables in the loop - Colt Steele
      // let node = stack.unshift()

      node = stack.pop()
      visited.push(node.value)

      if (node.right) stack.push(node.right)
      if (node.left) stack.push(node.left)
    }
    /*
            //      10
            //   5     13
            // 2  7  11  16

            stack - 
            visited - 10 5 2 7 13 11 16
        */

    return visited
  }

  DFSInorderIterative(root = this.root) {
    var node = root,
      stack = [],
      visited = []

    while (node || stack.length) {
      // avoid variables in the loop - Colt Steele

      while (node) {
        stack.push(node)
        node = node.left
      }

      node = stack.pop()
      visited.push(node.value)

      node = node.right
    }
    /*
            //      10
            //   5     13
            // 2  7  11  16

            stack - 
            visited - 2 5 7 10 11 13 16
        */

    return visited
  }

  DFSPostorderIterative(root = this.root) {
    // we achieve postorder traversal by using two stacks
    var node = root,
      stack1 = [],
      stack2 = [],
      visited = []
    stack1.push(node)

    while (stack1.length) {
      // avoid variables in the loop - Colt Steele
      // let node = stack.unshift()

      node = stack1.pop()
      stack2.push(node)

      if (node.left) stack1.push(node.left)
      if (node.right) stack1.push(node.right)
    }

    while (stack2.length) {
      node = stack2.pop()
      visited.push(node.value)
    }
    /*
            //      10
            //   5     13
            // 2  7  11  16

            stack1 - 
            stack2 - 10 13 16 11 5 7 2
            visited - 2 7 5 11 16 13 10
        */

    return visited
  }
}

//      10
//   5     13
// 2  7  11  16

var tree = new BinarySearchTree()
tree.insert(10)
tree.insert(5)
tree.insert(13)
tree.insert(11)
tree.insert(2)
tree.insert(16)
tree.insert(7)
