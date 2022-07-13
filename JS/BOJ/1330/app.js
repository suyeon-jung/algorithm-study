const fs = require("fs");
const filterPath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let input = fs
  .readFileSync(filterPath)
  .toString()
  .split(" ")
  .map((item) => +item);

function solution(A, B) {
  if (A > B) console.log(">");
  if (A < B) console.log("<");
  if (A === B) console.log("==");
}

solution(input[0], input[1]);
