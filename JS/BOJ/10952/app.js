const fs = require("fs");
const filterPath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let input = fs.readFileSync(filterPath).toString().split("\n");

const inputArray = [];
for (let i = 0; ; ++i) {
  const tempValue = input[i].split(" ").map((item) => +item);
  inputArray.push({ A: tempValue[0], B: tempValue[1] });
  if (tempValue[0] == 0 && tempValue[1] == 0) break;
}

solution(inputArr);

function solution(arr) {
  let A = -1;
  let B = -1;
  let idx = 0;
  while (A !== 0 || B !== 0) {
    const { A, B } = arr[idx];
    console.log(A + B);
    idx++;
  }
  for (let i = 0; ; ++i) {
    const { A, B } = arr[i];
    if (A == 0 && B == 0) break;
    console.log(A + B);
  }
}
