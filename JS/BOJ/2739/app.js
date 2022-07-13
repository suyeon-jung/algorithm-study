const fs = require("fs");
const filterPath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs.readFileSync(filterPath).toString();

solution(+input);

function solution(N) {
  for (let i = 1; i < 10; i++) {
    console.log(`${N} * ${i} = ${N * i}`);
  }
}
