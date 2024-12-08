class Node {
    constructor(val){
        this.next = null
        this.val = val
    }
}

class Stack {
    constructor(){
        this.first = null
        this.last = null
        this.size = 0
    }

    isEmpty(){
        return this.size === 0
    }

    push(val){
        let newNode = new Node(val)
        if(this.first == null) {
            this.first = newNode
            this.last = newNode
        } else {
            let curr = this.first
            this.first = newNode
            newNode.next = curr
        }
        this.size++
        return this.size
    }

    pop(){
        let nodeToBeDeleted = this.first
        if(this.size == 0) return null
        else if(this.size == 1){
            this.first = null
            this.last = null
        }
        else {
            let nextNode = nodeToBeDeleted.next
            this.first = nextNode
        }
        this.size--
        return nodeToBeDeleted
    }
}

const stack = new Stack()
stack.push(1)
stack.push(2)
stack.push(3)

// stack.pop()
