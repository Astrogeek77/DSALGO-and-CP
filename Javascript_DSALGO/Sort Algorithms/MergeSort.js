// Merge Sort
function merge(arr1, arr2) {
  let res = [];
  let i = 0,
    j = 0;

  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] < arr2[j]) {
      res.push(arr1[i]);
      i++;
    } else {
      res.push(arr2[j]);
      j++;
    }
  }

  while (i < arr1.length) {
    res.push(arr1[i]);
    i++;
  }

  while (j < arr2.length) {
    res.push(arr2[j]);
    j++;
  }

  return res;
}

function mergeSort(arr) {
  if (arr.length <= 1) return arr;

  let mid = Math.floor(arr.length / 2);
  let left = mergeSort(arr.slice(0, mid));
  let right = mergeSort(arr.slice(mid));

  return merge(left, right);
}

// Merge Sort with comparator
function mergeSort(arr, comp) {
  if (!comp) comp = (a, b) => a - b;
  if (arr.length <= 1) return arr;

  let mid = Math.floor(arr.length / 2);
  let left = mergeSort(arr.slice(0, mid), comp);
  let right = mergeSort(arr.slice(mid), comp);

  return merge(left, right, comp);
}

function merge(arr1, arr2, comp) {
  let res = [];
  let i = 0,
    j = 0;

  while (i < arr1.length && j < arr2.length) {
    if (comp(arr1[i], arr2[j]) <= 0) {
      res.push(arr1[i]);
      i++;
    } else {
      res.push(arr2[j]);
      j++;
    }
  }

  while (i < arr1.length) {
    res.push(arr1[i]);
    i++;
  }

  while (j < arr2.length) {
    res.push(arr2[j]);
    j++;
  }

  return res;
}
