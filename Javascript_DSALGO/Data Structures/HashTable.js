class HashMap {
  constructor(size = 53) {
    this.keyMap = new Array(size);
  }

  // basic hashing function for creating a Hast Map
  // we use a prime number to avoid collisions
  _hash(key) {
    let magic_num = 0;
    const WEIRD_PRIME = 31;

    for (let i = 0; i < Math.min(key.length, 200); i++) {
      let ch = key[i].toLowerCase(); // making it case insensitive
      let charCode = ch.charCodeAt(0) - 96; // getting ascii code and subtracting 96 from it
      magic_num = (magic_num * WEIRD_PRIME + charCode) % this.keyMap.length;
    }
    return magic_num;
  }

  set(key, value) {
    let hashedKey = this._hash(key);
    let matched = false; // tracks whether key exist previously or not

    // if the hashed index has no value, we just create a array and assign it to the hashed index
    if (!this.keyMap[hashedKey]) this.keyMap[hashedKey] = [];
    // else we check if the key already exists
    else {
      let resArr = this.keyMap[hashedKey];

      for (let resArrItem of resArr) {
        // if the key already exists, we update the values
        if (resArrItem[0] === key) {
          matched = true;
          resArrItem[1] = value;
        }
      }
    }
    // we just push key value pair we don't get a match or no value existed for the hashed index
    if (!matched) this.keyMap[hashedKey].push([key, value]);
  }

  get(key) {
    let hashedKey = this._hash(key);

    let resArr = this.keyMap[hashedKey];
    // console.log(resArr)

    if (resArr) {
      for (let resArrItem of resArr) {
        if (resArrItem[0] === key) return resArrItem[1];
      }
    }
    return undefined;
  }

  remove(key) {
    let hashedKey = this._hash(key);

    let resArr = this.keyMap[hashedKey];

    if (resArr) resArr = resArr.filter((resArrItem) => resArrItem[0] !== key);

    this.keyMap[hashedKey] = resArr;
  }

  getKeys() {
    let keys = [];

    for (let i = 0; i < this.keyMap.length; i++) {
      let resArr = this.keyMap[i];

      if (resArr) {
        for (let resArrItem of resArr) {
          keys.push(resArrItem[0]);
        }
      }
    }

    return keys;
  }

  // values without duplicates - without using Set
  getValues() {
    let values = [];

    for (let i = 0; i < this.keyMap.length; i++) {
      let resArr = this.keyMap[i];

      if (resArr) {
        for (let resArrItem of resArr) {
          if (!values.includes(resArrItem[1])) values.push(resArrItem[1]);
        }
      }
    }

    return [...values];
  }

  // values without duplicates - using Set
  getValuesSet() {
    let values = new Set();

    for (let i = 0; i < this.keyMap.length; i++) {
      let resArr = this.keyMap[i];

      if (resArr) {
        for (let resArrItem of resArr) {
          values.add(resArrItem[1]);
        }
      }
    }

    return [...values];
  }

  getValuesWithDuplicates() {
    let values = [];

    for (let i = 0; i < this.keyMap.length; i++) {
      let resArr = this.keyMap[i];

      if (resArr) {
        for (let resArrItem of resArr) {
          values.push(resArrItem[1]);
        }
      }
    }

    return values;
  }

  printAllKeyValuePairs() {
    for (let i = 0; i < this.keyMap.length; i++) {
      let resArr = this.keyMap[i];

      if (resArr) {
        for (let resArrItem of resArr) {
          console.log(resArrItem[0] + "->" + resArrItem[1]);
        }
      }
    }
  }
}

let hashMap = new HashMap(10);
hashMap.set("blue", "#0000FF");
hashMap.set("pink", "#FFC0CB");
hashMap.set("magenta", "#FF00FF");
hashMap.set("green", "#008000");
hashMap.set("cyan", "#00FFFF");
hashMap.set("yellow", "#FFFF00");
hashMap.set("red", "#FF0000");
hashMap.set("hi", "hello");
hashMap.set("hey", "hello");
hashMap.set("bonjour", "hello");
hashMap.set("bye", "bye!!");

// testing for duplicate keys case - now it updates the value
hashMap.set("bye", "goodbye");
hashMap.set("hi", "Hello");

// console.log(hashMap.get("hi"))
// console.log(hashMap.get("yellow"))
// console.log(hashMap.get("blue"))
// console.log(hashMap.get("pink"))

// console.log(hashMap.getKeys())
// console.log(hashMap.getValuesWithDuplicates())
// console.log(hashMap.getValues())
// console.log(hashMap.getValuesSet())

// console.log(hashMap)

// hashMap.getKeys().forEach(function(key){
//     console.log(hashMap.get(key))
// })

// hashMap.remove("blue")

// console.log(hashMap)

hashMap.printAllKeyValuePairs();
