const fs = require("fs");
const filterPath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filterPath).toString().split("\n");

function solution(A, B) {
  const stringB = String(B);
  const one = +stringB[2];
  const ten = +stringB[1];
  const hun = +stringB[0];
  console.log(A * one);
  console.log(A * ten);
  console.log(A * hun);
  console.log(A * B);
}

solution(input[0], input[1]);
