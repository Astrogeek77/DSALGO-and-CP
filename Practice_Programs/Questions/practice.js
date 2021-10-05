// const nums = [1, 3, 7, 9, 2]
// const target = 5

// var twoSum = function (nums, target) {
//   const numsMap = {}
//   console.log({ numsMap })

//   for (let p = 0; p < nums.length; p++) {
//     console.log({ p, value: nums[p] })

//     const numsMapValue = numsMap[nums[p]]
//     console.log({ numsMapValue })

//     if (numsMapValue >= 0) {
//       return [numsMapValue, p]
//     } else {
//       let numToFind = target - nums[p]
//       console.log({ numToFind })
//       numsMap[numToFind] = p
//       console.log({ numsMap })
//     }
//   }
//   return null
// };

// console.log(twoSum(nums, target))





// let nums = [-1,0,1,2,-1,-4]

// var threeSum = function(nums) {
    
//   let results = []
//   for(let p = 0; p < nums.length; p++){
//     console.log({ p, value: nums[p] })
//     let numsMap = {}
//     for(let n = p; n < nums.length; n++){
//       console.log({ n, value: nums[n] })
//       let numsMapValue = numsMap[nums[n]]
//       console.log({ numsMapValue })
//       if (numsMapValue >= 0){
//           results.push([nums[p], nums[numsMapValue], nums[n]])
//           console.log({results})
//       } else {
//           let target = 0 - nums[p]
//           console.log({target})
//           numsMap[target] = n
//           console.log({ numsMap })
//         }
//       }
      
//   }
//   return results
// };

// console.log(threeSum(nums))





// let height = [7, 1, 2, 3, 9]

// var maxArea = function(height){
//   mxArea = 0;
//   for(let p = 0; p < height.length; p++){
//     // console.log({p, value: height[p]})
//     for(let m = p+1; m < height.length; m++ ){
//       // console.log({m, value: height[m]})
//       var area = (Math.min(height[p], height[m]) * (m - p))
//       // console.log({area})
//       mxArea = Math.max(area, mxArea)
//       // console.log({mxArea})
//     }
//   }
//   return mxArea
// }

// console.log(maxArea(height))

// let height = [7, 1, 2, 3, 9]

// var maxArea = function(height){
//   mxArea = 0, p = 0; m = height.length - 1; 
//   while(p < m) {
//     console.log({p, value: height[p]})
//     console.log({m, value: height[m]})
//     var area = (Math.min(height[p], height[m]) * (m - p))
//     console.log({area})
//     mxArea = Math.max(area, mxArea)
//     console.log({mxArea})
//     if (height[p] <= height[m]) p++
//     else m++
//   }        
// return mxArea
// }

// console.log(maxArea(height))


  const elevationArray = [0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2]

  let totalWater = 0;

  for()


