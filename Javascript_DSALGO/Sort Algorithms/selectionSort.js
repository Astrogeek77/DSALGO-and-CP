function selectionSort(arr){
  const swap = (arr, idx1, idx2) => {
      [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]]
  }
  
  for(var i = 0; i < arr.length; i++){
    let mini = i
    for(var j = i+1; j < arr.length; j++){
      if(arr[j] < arr[mini]) mini = j
    }

    if(mini != i) swap(arr, i, mini)
  }

  return arr
}