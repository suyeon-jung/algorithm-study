const fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\n");

// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

const inputC = +input[0];
const inputTestCase = [];

for (let i = 1; i <= inputC; ++i) {
  const arr = input[i].split(" ").map((item) => +item);
  const newArr = [];
  for (let i = 1; i <= arr[0]; ++i) {
    newArr.push(arr[i]);
  }
  const testCase = {
    N: arr[0],
    arr: newArr,
  };
  inputTestCase.push(testCase);
}

function solution(C, testCase) {
  testCase.map((item) => {
    let sum = 0;
    for (let i = 0; i < item.N; i++) {
      sum += item.arr[i];
    }
    let avg = sum / item.N;
    let cnt = 0;
    for (let i = 0; i < item.N; i++) {
      if (item.arr[i] > avg) {
        cnt++;
      }
    }
    console.log(((cnt / item.N) * 100).toFixed(3) + "%");
  });
}

solution(inputC, inputTestCase);
