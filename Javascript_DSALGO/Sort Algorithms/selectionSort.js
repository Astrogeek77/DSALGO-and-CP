function selectionSort(arr) {
  const swap = (arr, idx1, idx2) => {
    [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]];
  };

  for (var i = 0; i < arr.length; i++) {
    let mini = i;
    for (var j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[mini]) mini = j;
    }

    if (mini != i) swap(arr, i, mini);
  }

  return arr;
}

console.log(selectionSort([23, 6, -4, 95, 56, -69]));

// with comparator

function selectionSort(arr, comparator) {
  if (!comparator) {
    // Default comparator if none is provided
    comparator = (a, b) => a - b;
  }

  const swap = (arr, idx1, idx2) => {
    [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]];
  };

  for (var i = 0; i < arr.length; i++) {
    let mini = i;
    for (var j = i + 1; j < arr.length; j++) {
      if (comparator(arr[j], arr[mini]) < 0) mini = j;
    }

    if (mini != i) swap(arr, i, mini);
  }

  return arr;
}

console.log(selectionSort([23, 6, -4, 95, 56, -69]));
