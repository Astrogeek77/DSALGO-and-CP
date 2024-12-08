// Bubble Sort 

function bubbleSort(arr){
    const swap = (arr, idx1, idx2) => {
        [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]]
    }

    var noSwaps = true
    for(let i = arr.length; i > 0; i--){
        for(let j = 0; j < i-1; j++){
            if(arr[j] > arr[j+1]) {
              swap(arr, j, j+1)
              noSwaps = false
            }
        }
      if(noSwaps) break;
    }

    return arr;
}

console.log(bubbleSort([23, 6, -4, 95, 56, -69]))




