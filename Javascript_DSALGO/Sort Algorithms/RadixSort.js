const getDigit = (num, pos) =>
  Math.floor((Math.abs(num) / Math.pow(10, pos)) % 10);
const digitCount = (num) =>
  num == 0 ? 1 : Math.floor(Math.log10(Math.abs(num)) + 1);
const mostDigits = (nums) => {
  let cnt = 0;
  for (let i = 0; i < nums.length; i++)
    cnt = Math.max(digitCount(nums[i]), cnt);
  return cnt;
};

function radixSort(nums) {
  // Separate non-negative and negative numbers
  let nonNegatives = nums.filter((num) => num >= 0);
  let negatives = nums.filter((num) => num < 0);

  // Sort non-negative numbers using radix sort
  let maxDigitCnt = mostDigits(nonNegatives);
  for (let k = 0; k < maxDigitCnt; k++) {
    let buckets = Array.from({ length: 10 }, () => []);
    for (let i = 0; i < nonNegatives.length; i++) {
      let bucketIdx = getDigit(nonNegatives[i], k);
      buckets[bucketIdx].push(nonNegatives[i]);
    }
    nonNegatives = [].concat(...buckets);
  }

  // Sort negative numbers in reverse using radix sort
  maxDigitCnt = mostDigits(negatives);
  for (let k = 0; k < maxDigitCnt; k++) {
    let buckets = Array.from({ length: 10 }, () => []);
    for (let i = 0; i < negatives.length; i++) {
      let bucketIdx = getDigit(Math.abs(negatives[i]), k);
      buckets[bucketIdx].push(negatives[i]);
    }
    negatives = [].concat(...buckets);
  }

  // Reverse the order of negative numbers and combine with non-negative numbers
  return negatives.reverse().concat(nonNegatives);
}

console.log(radixSort([23, 6, -4, 95, 56, -69]));
