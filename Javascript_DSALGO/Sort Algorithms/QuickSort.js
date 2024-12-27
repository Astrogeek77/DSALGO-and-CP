// Quick sort
function partition(arr, startIndex = 0, endIndex = arr.length - 1) {
  const swap = (arr, idx1, idx2) => {
    [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]];
  };

  let pivot = arr[startIndex],
    pvtIdx = startIndex;

  for (let i = startIndex + 1; i <= endIndex; i++) {
    if (pivot > arr[i]) {
      pvtIdx++;
      swap(arr, pvtIdx, i);
    }
  }
  swap(arr, startIndex, pvtIdx);
  return pvtIdx;
}

function quickSort(arr, left = 0, right = arr.length - 1) {
  if (left < right) {
    let pvtIdx = partition(arr, left, right);

    quickSort(arr, left, pvtIdx - 1);
    quickSort(arr, pvtIdx + 1, right);
  }
  return arr;
}

// with Comparator
function pivot(arr, comp, startIndex = 0, endIndex = arr.length - 1) {
  const swap = (arr, idx1, idx2) => {
    [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]];
  };

  let pivot = arr[startIndex],
    pvtIdx = startIndex;

  for (let i = startIndex + 1; i <= endIndex; i++) {
    if (comp(pivot, arr[i]) >= 0) {
      pvtIdx++;
      swap(arr, pvtIdx, i);
    }
  }
  swap(arr, startIndex, pvtIdx);
  return pvtIdx;
}

function quickSort(arr, comp, left = 0, right = arr.length - 1) {
  if (!comp) comp = (a, b) => a - b;
  if (left < right) {
    let pvtIdx = pivot(arr, comp, left, right);

    quickSort(arr, comp, left, pvtIdx - 1);
    quickSort(arr, comp, pvtIdx + 1, right);
  }
  return arr;
}
