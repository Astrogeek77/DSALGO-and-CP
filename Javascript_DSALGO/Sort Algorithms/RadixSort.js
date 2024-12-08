// Radix Sort

function radixSort(arr){
    const getDigitAt = (num, pos) => Math.floor(Math.abs(num) / Math.pow(10, pos) % 10)
    const countDigits = (num) => num == 0 ? 1 : Math.floor(Math.log10(Math.abs(num)) + 1)
    const maxDigitCount = (nums) => {
        let cnt = 0
        for(let i = 0; i < nums.length; i++) cnt = Math.max(countDigits(nums[i]), cnt)
        return cnt
    }

    let maxDigitCnt = maxDigitCount(arr)
    for(let k = 0; k < maxDigitCnt; k++){
        let buckets = Array.from({length: 10}, () => [])
        for(let i = 0; i < arr.length; i++){
            let bucketIdx = getDigitAt(arr[i], k)
            buckets[bucketIdx].push(arr[i])
        }
        nums = [].concat(...buckets)
    }

    return nums
}