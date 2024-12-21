function insertionSort(arr) {
  for (var i = 1; i < arr.length; i++) {
    var currentVal = arr[i];
    for (var j = i - 1; j >= 0 && arr[j] > currentVal; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = currentVal;
  }
  return arr;
}

function insertionSort(arr, comp) {
  if (!comp) comp = (a, b) => a - b;
  for (var i = 1; i < arr.length; i++) {
    var currentVal = arr[i];
    for (var j = i - 1; j >= 0 && comp(arr[j], currentVal) > 0; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = currentVal;
  }
  return arr;
}
