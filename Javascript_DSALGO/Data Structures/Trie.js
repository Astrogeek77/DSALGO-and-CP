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
    if (i === word.length) return this;

    const char = word[i];
    if (!this.characters[char]) return undefined;

    return this.characters[char].findWord(word, i + 1);
  }
  getWords(words = [], currentWord = "") {
    if (this.isWord) words.push(currentWord);

    for (let char in this.characters)
      this.characters[char].getWords(words, currentWord + char);

    return words;
  }

  autoComplete(prefix) {
    let currentNode = this;

    for (let char of prefix) {
      if (!currentNode.characters[char]) return [];

      currentNode = currentNode.characters[char];
    }

    return currentNode.getWords([], prefix);
  }

  removeWord(word, index = 0) {
    if (index === word.length) this.isWord = false;
    else {
      var char = word[index];

      if (this.characters[char]) {
        this.characters[char].removeWord(word, index + 1);

        // If the this.characters[char] is not an end of another word and has no children, delete it
        if (
          Object.keys(this.characters[char].characters).length === 0 &&
          !this.characters[char].isWord
        ) {
          delete this.characters[char];
        }
      }
    }
    return this;
  }
}
