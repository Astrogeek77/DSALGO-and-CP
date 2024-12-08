function validAnagram(word1, word2){
  // add whatever parameters you deem necessary - good luck!
  
  if(word1.length != word2.length) 
    return false;
  // if(word1 === word2) 
  //   return true;
  
  const freq1 = {}
  // var freq2 = {}
  
  for(let x = 0; x < word1.length; x++) {
      let ch = word1[x];
      freq1[ch] ? freq1[ch] += 1 : freq1[ch] = 1;
  }
  
 // for(let ch in word2) {
 //     freq2[ch] = freq2[ch] ? freq2[ch] + 1 : 1;
 // }
  
  for(let i = 0; i < word2.length; i++){
      let ch = word2[i];
      
      // if(freq1[ch] != freq2[ch]) return false;
      
      if(!freq1[ch]) {
         return false 
      } else {
        freq1[ch] -= 1
      }    
  }
  
  return true;
  
}

validAnagram('cat', 'tac');



function countUniqueValues(val){
  // add whatever parameters you deem necessary - good luck!
  
  if(val.length === 0) return 0;
  
  let l = 0, r = 1;
  
//   while(r < val.length){
//       if(val[l] !== val[r]) {
//           // [val[l], val[r]] = [val[r], val[l]]
//           val[l] = val[r]
//           l++
//       }
//       r++
//   }
  
  for(let r = 1; r < val.length; r++){
      if(val[l] !== val[r]) {
          // [val[l], val[r]] = [val[r], val[l]]
          l++
          val[l] = val[r]
      }
  }
  
  return l + 1
}






// function sameFrequency(num1, num2){
//   // good luck. Add any arguments you deem necessary.
//   var digits1 = getDigits(num1)
//   var digits2 = getDigits(num2)
  
//   digits1.sort()
//   digits2.sort()
  
//   return digits1 === digits2
// }


// function getDigits(num){
//     let digits = [], n = num;
//     while(n != 0){
//         digits.push(n / 10);
//         n = Math.trunc(n % 10);
//     }
//     return digits
// }

function sameFrequency(num1, num2){
  let strNum1 = num1.toString();
  let strNum2 = num2.toString();
  if(strNum1.length !== strNum2.length) return false;
  
  let countNum1 = {};
  let countNum2 = {};
  
  for(let i = 0; i < strNum1.length; i++){
    countNum1[strNum1[i]] = (countNum1[strNum1[i]] || 0) + 1
  }
  
  for(let j = 0; j < strNum1.length; j++){
    countNum2[strNum2[j]] = (countNum2[strNum2[j]] || 0) + 1
  }
  
  for(let key in countNum1){
    if(countNum1[key] !== countNum2[key]) return false;
  }
 
  return true;
}


function areThereDuplicates(...args) {
    
    args.sort()
    
    var l = 0, r = 1
    while(r < args.length){
        if(args[l++] === args[r++]) return true
    }
    return false
}



function averagePair(args, num){
  // add whatever parameters you deem necessary - good luck!
  
  let l = 0, n = args.length, r = n-1
  
  while(l < r) {
      let avg = (args[l] + args[r]) / 2
      if(num === avg)
        return true;
      else if (avg > num) 
        r--;
      else 
        l++;
  }
  return false
}



// function isSubsequence(checkstr, str) {
//   // good luck. Add any arguments you deem necessary.
//   let l = 0, n1 = checkstr.length
//   let r = 0, n2 = str.length
  
//   if(!checkstr) return true
  
//   while(r < n2){
//       if(checkstr[l] == str[r]) l++
//       if(l == n1) return true
//       r++
//   }
  
//   return false
  
// }.

function isSubsequence(checkstr, str){
    if(checkstr.length == 0) return true
    if(str.length == 0) return false
    
    if(checkstr[0] === str[0]) return isSubsequence(checkstr.slice(1), str.slice(1))
    return isSubsequence(checkstr, str.slice(1))
}




function maxSubarraySum(arr, num){
  // add whatever parameters you deem necessary - good luck!
  
  if(arr.length < num) return null
  
  let l = 0, r = num, n = arr.length
  let currSum = 0, maxSum = 0;
  
  for(let i = 0; i < num; i++){
      currSum += arr[i];
  }
  
  maxSum = currSum
  while(r < n){
      currSum = currSum + arr[r] - arr[r - num]
      maxSum = Math.max(currSum, maxSum)
      r++
  }
  
  return maxSum
}


// power(2,0) // 1
// power(2,2) // 4
// power(2,4) // 16

function power(num, pow){
    if(pow == 0) return 1;
    return num * power(num, pow - 1)
}


//factorial(1) // 1
// factorial(2) // 2
// factorial(4) // 24
// factorial(7) // 5040

function factorial(num){
   if(num <= 1) return 1
   return num * factorial(num-1)
}


// productOfArray([1,2,3]) // 6
// productOfArray([1,2,3,10]) // 60

function productOfArray(arr, i){
    if(arr.length == 0) return 1
    return arr[0] * productOfArray(arr.slice(1))
}



// SAMPLE INPUT/OUTPUT
// recursiveRange(6) // 21
// recursiveRange(10) // 55 

function recursiveRange(num){
   if(num <= 0) return 0
   return num + recursiveRange(num-1)
}



// fib(4) // 3
// fib(10) // 55
// fib(28) // 317811
// fib(35) // 9227465

function fib(num){
  // add whatever parameters you deem necessary - good luck! 
  
  if(num <= 2) return 1
  return fib(num-1) + fib(num-2)
}



function reverse(str){
  // add whatever parameters you deem necessary - good luck!
  if(str.length <= 1) return str
  return reverse(str.slice(1)) + str[0]
}

// reverse('awesome') // 'emosewa'
// reverse('rithmschool') // 'loohcsmhtir'


// isPalindrome('awesome') // false
// isPalindrome('foobar') // false
// isPalindrome('tacocat') // true
// isPalindrome('amanaplanacanalpanama') // true
// isPalindrome('amanaplanacanalpandemonium') // false

function isPalindrome(str){
  // add whatever parameters you deem necessary - good luck!
  if(str.length === 1) return true
  if(str.length === 2) return str[0] === str[1]
  
  if(str[0] === str.slice(-1)) return isPalindrome(str.slice(1, -1))
  return false
}




// SAMPLE INPUT / OUTPUT
// const isOdd = val => val % 2 !== 0;

// someRecursive([1,2,3,4], isOdd) // true
// someRecursive([4,6,8,9], isOdd) // true
// someRecursive([4,6,8], isOdd) // false
// someRecursive([4,6,8], val => val > 10); // false

function someRecursive(arr, cb){
  // add whatever parameters you deem necessary - good luck!
  
  // array check
  if(arr.length === 0) return false
  // base condition
  if(cb(arr[0])) return true
  // return condition
  return someRecursive(arr.slice(1), cb)
}


function flatten(arr){
  // add whatever parameters you deem necessary - good luck!
  let resArr = []
  
  for(let i = 0; i < arr.length; i++){
      let x = arr[i]
      if(Array.isArray(x)){
          resArr = resArr.concat(flatten(x))
      }
      else resArr.push(x)
  }
  
  return resArr
}

// flatten([1, 2, 3, [4, 5] ]) // [1, 2, 3, 4, 5]
// flatten([1, [2, [3, 4], [[5]]]]) // [1, 2, 3, 4, 5]
// flatten([[1],[2],[3]]) // [1,2,3]
// flatten([[[[1], [[[2]]], [[[[[[[3]]]]]]]]]]) // [1,2,3]





