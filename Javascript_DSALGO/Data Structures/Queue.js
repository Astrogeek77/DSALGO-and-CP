class Node {
    constructor(val){
        this.next = null
        this.val = val
    }
}

class Queue {
    constructor(val){
        this.first = null
        this.last = null
        this.size = 0
    }

    enqueue(val){
        let newNode = new Node(val)
        if(this.size == 0){
            this.first = newNode
            this.last = newNode
        } else {
            let lastNode = this.last
            this.last = newNode
            lastNode.next = newNode
        }
        this.size++
        return this.size
    }

    dequeue(){
        if(this.size == 0) return null
        let nodeToBeDeleted = this.first
        
        if(this.first == this.last){
            this.last = null
        }
        let nextNode = nodeToBeDeleted.next
        this.first = nextNode
        this.size--
        return nodeToBeDeleted
    }
}

let q = new Queue()
q.enqueue("First")
q.enqueue("Second")
