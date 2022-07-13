class Queue {
  constructor() {
    this.arr = [];
    this.front = 0;
    this.rear = 0;
  }
  enqueue(data) {
    this.arr.push(data);
  }
  dequeue() {
    return this.arr.shift() || null;
  }
  peek() {
    return this.arr[this.arr.length - 1];
  }
  length() {
    return this.arr.length;
  }
  clear() {
    this.arr = [];
  }
}
let q = new Queue();
