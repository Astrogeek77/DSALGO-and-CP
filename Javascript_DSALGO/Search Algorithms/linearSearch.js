function linearSearch(arr, val){
  // add whatever parameters you deem necessary - good luck!
  
  for(let i = 0; i < arr.length; i++){
      if(arr[i] === val) 
        return i
  }
  return -1;
}
