const arr1 = new Array();
const arr2 = new Array(1, 2, 3);
const arr3 = [1, 2, 3];

// 키값으로 순회(인덱스)
for (const key in arr3) {
  console.log(key, arr3[key]);
}

// value값으로 순회
for (const item of arr3) {
  console.log(item);
}

arr3.forEach((item, index) => console.log(item, index));

const newArr = arr3.map((item) => item * 2);
console.log(newArr);

// 길이
console.log(arr3.length);

// 요소의 인덱스 찾기
arr3.indexOf(3);

// 요소 찾기
const find = arr3.findIndex((element) => element > 2);
console.log(find);

// 정렬
arr1.sort();
arr1.reverse();

// 요소 합치기(기존 배열 유지)
arr1.concat(4);
// 배열을 문자열로 반환(기존 배열 유지)
arr1.join(" ");

// 요소 자르기
arr1.slice(0, 1); // (인덱스, 인덱스 -1)
arr1.splice(1, 2); // (인덱스, 요소개수)

// 뒤에서 push, pop
arr4 = [1, 2, 3, 4];
arr4.pop();
console.log(arr4, "pop");
arr4.push(5);
console.log(arr4, "push");
