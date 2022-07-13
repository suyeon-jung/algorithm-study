const fs = require("fs");
const filterPath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filterPath).toString().split("\n");

solution(+input[0]);

function solution(N) {
  for (let line = 1; line <= 5; line++) {
    const starCnt = line;
    const spaceCnt = N - line;
    let printString = "";
    for (let i = 0; i < starCnt; i++) {
      printString += "*";
    }
    for (let i = 0; i < spaceCnt; i++) {
      printString += " ";
    }
    console.log(printString);
  }
}
