// Quick sort
function partition(arr, startIndex = 0, endIndex = arr.length - 1){
  const swap = (arr, idx1, idx2) => {
      [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]]
  }
  
  let pivot = arr[startIndex], pvtIdx = startIndex

  for(let i = startIndex+1; i <= endIndex; i++){
    if(pivot > arr[i]){
      pvtIdx++
      swap(arr, pvtIdx, i)
    }
  }
  swap(arr, startIndex, pvtIdx)
  return pvtIdx
}

function quickSort(arr, left = 0, right = arr.length-1){
  if(left < right){
    let pvtIdx = partition(arr, left, right)
  
    quickSort(arr, left, pvtIdx - 1)
    quickSort(arr, pvtIdx + 1, right)
  }
  return arr
}

