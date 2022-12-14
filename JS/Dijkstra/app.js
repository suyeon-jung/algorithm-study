// 1. 최단거리배열
// 2. 거리가 가장 짧은 노드 선택을 위한 우선순위큐
// 3. 무방향 가중치 그래프

const INF = Infinity;
const N = 6;

// 방문 배열
const visited = new Array(N).fill(false);
// 최단거리배열
// const dist = new Array(N).fill(INF);

// 그래프
const graph = [
  [INF, 1, INF, 2, INF],
  [1, INF, 3, INF, 2],
  [INF, 3, INF, INF, 1],
  [2, INF, INF, INF, 2],
  [INF, 2, 1, 2, INF],
];

// 최소 거리를 가지는 정점 반환
const getMinVertex = function (vertex) {
  let minVal = INF;
  let idx = 0;
  for (let i = 0; i < vertex.length; i++) {
    if (minVal > vertex[i] && !visited[i]) {
      minVal = vertex[i];
      idx = i;
    }
  }
  return idx;
};

const dijkstra = (start) => {
  let dist = graph[start];
  let count = 0;
  let min = 0;
  let adjacent = dist;
  visited[start - 1] = true;

  while (count < N) {
    const minIdx = getMinVertex(adjacent);
    min += adjacent[minIdx];
    const nextAdjacent = graph[minIdx];

    for (let i = 0; i < N; i++) {
      if (dist[i] > nextAdjacent[i] + min && !visited[i]) {
        dist[i] = nextAdjacent[i] + min;
      }
    }
    adjacent = graph[minIdx];
    visited[minIdx] = true;
    count++;
  }
  console.log(dist);
};

const main = (function () {
  dijkstra(1);
})();
