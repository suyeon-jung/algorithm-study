const fs = require("fs");
const filterPath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filterPath).toString().split("\n");

input = input[0];
input = input.split(" ").map((item) => +item);

solution(input[0], input[1]);

function solution(A, B) {
  console.log(A + B);
}
