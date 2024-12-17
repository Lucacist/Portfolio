const rows = 20; // Réduction du nombre de lignes
const cols = 20; // Réduction du nombre de colonnes
const speed = 1000; // Vitesse en millisecondes (300ms pour ralentir)

const container = document.getElementById("game-container");
let grid = createGrid(rows, cols);
let nextGrid = createGrid(rows, cols);

function createGrid(rows, cols) {
  return Array.from({ length: rows }, () => Array(cols).fill(0));
}

function createHtmlGrid() {
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      const cell = document.createElement("div");
      cell.classList.add("cell");
      container.appendChild(cell);
    }
  }
}

function updateHtmlGrid() {
  const cells = document.querySelectorAll(".cell");
  let index = 0;
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      cells[index].classList.toggle("alive", grid[i][j] === 1);
      index++;
    }
  }
}

function randomizeGrid() {
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      grid[i][j] = Math.random() > 0.7 ? 1 : 0; // Probabilité ajustée
    }
  }
}

function getNeighborCount(grid, x, y) {
  const directions = [
    [-1, -1],
    [-1, 0],
    [-1, 1],
    [0, -1],
    [0, 1],
    [1, -1],
    [1, 0],
    [1, 1],
  ];
  return directions.reduce((count, [dx, dy]) => {
    const newX = x + dx;
    const newY = y + dy;
    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
      count += grid[newX][newY];
    }
    return count;
  }, 0);
}

function computeNextGeneration() {
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      const neighbors = getNeighborCount(grid, i, j);
      if (grid[i][j] === 1) {
        nextGrid[i][j] = neighbors === 2 || neighbors === 3 ? 1 : 0;
      } else {
        nextGrid[i][j] = neighbors === 3 ? 1 : 0;
      }
    }
  }

  // Copier nextGrid dans grid
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      grid[i][j] = nextGrid[i][j];
    }
  }
}

function gameLoop() {
  computeNextGeneration();
  updateHtmlGrid();
  setTimeout(gameLoop, speed); // Ralentir la vitesse de la simulation
}

// Initialisation
createHtmlGrid();
randomizeGrid();
updateHtmlGrid();
gameLoop();
