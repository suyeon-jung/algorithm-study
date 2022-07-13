const graph = {
  A: ["B", "C"],
  B: ["A", "D"],
  C: ["A", "G", "H", "I"],
  D: ["B", "E", "F"],
  E: ["D"],
  F: ["D"],
  G: ["C"],
  H: ["C"],
  I: ["C", "J"],
  J: ["I"],
};

const BFS = (graph, start) => {
  const visited = []; // 탐색 완료한 노드
  let queue = [];

  queue.push(start);
  while (queue.length !== 0) {
    const curNode = queue.shift(); // FIFO
    if (!visited.includes(curNode)) {
      visited.push(curNode);
      queue = [...queue, ...graph[curNode]];
    }
  }
  return visited;
};

console.log(BFS(graph, "A"));
