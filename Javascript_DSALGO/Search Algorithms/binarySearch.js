function binarySearch(arr, val){
  // add whatever parameters you deem necessary - good luck!
  let l = 0, r = arr.length - 1, mid = Math.floor((r + l) / 2)
  
  while(arr[mid] !== val && l <= r){
      if(arr[mid] < val) l = mid + 1
      else r = mid - 1;
        
      mid = Math.floor((r + l) / 2)
  }
  return arr[mid] == val ? mid : -1
}

binarySearch([1, 3, 5, 8, 9, 15], 8)