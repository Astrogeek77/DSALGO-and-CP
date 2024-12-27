class Trie {
    constructor() {
        this.characters = {};
        this.isWord = false;
    }
    addWord(word, index = 0) {
        if (index === word.length) {
            this.isWord = true;
        } else if (index < word.length) {
            var char = word[index];
            var subTrie = this.characters[char] || new Trie();
            subTrie.addWord(word, index + 1);
            this.characters[char] = subTrie;
        }
        return this;
    }


    findWord(word, i = 0) {
        if(i === word.length) return this
       
        const char = word[i]
        if(!this.characters[char])
            return undefined
       
        return this.characters[char].findWord(word, i + 1)    
    }
    getWords(words = [], currentWord = ""){
        if(this.isWord) words.push(currentWord)
       
        for(let char in this.characters)
            this.characters[char].getWords(words, currentWord + char)
           
        return words    
    }
   
    autoComplete(prefix){
        let currentNode = this
       
        for(let char of prefix){
            if(!currentNode.characters[char]) return []
           
            currentNode = currentNode.characters[char]
        }
       
        return currentNode.getWords([], prefix)
    }
   
    removeWord(word, index = 0) {
        if (index === word.length)
            this.isWord = false;
        else
        {
            var char = word[index];
               
            if (this.characters[char])
            {
                this.characters[char].removeWord(word, index + 1);
               
                // If the this.characters[char] is not an end of another word and has no children, delete it
                if (Object.keys(this.characters[char].characters).length === 0
                && !this.characters[char].isWord)
                {
                    delete this.characters[char];
                }
            }
        }
        return this;
    }
}


function logger(arg){
    console.log(`"${arg}": ${arg}`)
}




// // add word


// let test, log
// var firstTrie = new Trie();
// firstTrie.addWord("fun")


// logger(firstTrie.characters) // {f: Trie}
// logger(!!firstTrie.characters["f"]) // true
 
// logger(firstTrie.characters.f.characters.u) // {u: Trie}
// logger(!!firstTrie.characters.f.characters.u) // true
 
// firstTrie.characters.f.characters.u.characters.n.isWord // true
// !!firstTrie.characters.f.characters.u.characters.n // true
// !!firstTrie.characters.f.characters.u.characters.n.characters // {}
 
// !!firstTrie.characters.f.characters.u.characters.l // true
 
// var secondTrie = new Trie();
// secondTrie.addWord("ha")
// secondTrie.addWord("hat")
// secondTrie.addWord("has")
// secondTrie.addWord("have")
// secondTrie.addWord("hate")
 
// secondTrie.characters.h.characters.a.isWord // true
// secondTrie.characters.h.characters.a.characters.t.isWord // true
// secondTrie.characters.h.characters.a.characters.a.isWord // false




// var t = new Trie();
// t.addWord('fun')
// t.addWord('fast')
// t.addWord('fat')
// t.addWord('fate')
// t.addWord('father')
 
// t.findWord('taco') // undefined
// t.findWord('fat').characters // {t: Trie}
// t.findWord('father').characters // {}
// t.findWord('father').isWord // true




// var t = new Trie();
// t.addWord('fun')
// t.addWord('fast')
// t.addWord('fat')
// t.addWord('fate')
// t.addWord('father')
// t.addWord('forget')
// t.addWord('awesome')
// t.addWord('argue')
 
// t.getWords() // ["fun", "fast", "fat", "fate", "father", "forget", "awesome", "argue"]
 
// t.getWords().length // 8




// var t = new Trie();
// t.addWord('fun')
// t.addWord('fast')
// t.addWord('fat')
// t.addWord('fate')
// t.addWord('father')
// t.addWord('forget')
// t.addWord('awesome')
// t.addWord('argue')
 
// t.autoComplete('fa') // ["fast","fat", "fate", "father"]
// t.autoComplete('a') // ["awesome", "argue"]
// t.autoComplete('arz') // []






// var t = new Trie();
// t.addWord('fun')
// t.addWord('fast')
// t.addWord('fat')
// t.addWord('fate')
// t.addWord('father')
// t.addWord('forget')
// t.addWord('awesome')
// t.addWord('argue')
 
 
// t.removeWord('fat')
// t.characters.f.characters.a.characters.t.isWord // false
// t.characters.f.characters.a.characters.t.characters.e.isWord // true
 
// t.removeWord('argue')
 
// t.characters.a.characters.r // undefined






// add word
let trie = new Trie()


trie.addWord("ha")
trie.addWord("hat")
trie.addWord("has")
trie.addWord("have")
trie.addWord("hey")
// trie.addWord("hi")


console.log(trie.characters)
console.log(trie.characters.h.characters.a.characters.t.isWord)
console.log(!trie.characters.h.characters.i)


console.log(trie.findWord("hey").isWord)
console.log(!!trie.findWord("hi"))


console.log(trie.getWords())


console.log(trie.autoComplete("ha"))


console.log(trie.removeWord("hey"))


console.log(trie.autoComplete("ha"))

