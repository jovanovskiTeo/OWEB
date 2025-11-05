
const images = [
  'shrek.jpg',
  'fin.jpg',
  'spongebob.jpg',
  'sanchez.jpg',
  'mordecai.jpg',
  'cat.jpg'
];

let cards = [...images, ...images];
let flippedCards = [];
let matchedCount = 0;
let moves = 0;
let timer = 0;
let timerStarted = false;
let timerInterval;

const board = document.getElementById('game-board');
const movesDisplay = document.getElementById('moves');
const timerDisplay = document.getElementById('timer');
const restartBtn = document.getElementById('restart');

function shuffle(array) {
  return array.sort(() => Math.random() - 0.5);
}

function startGame() {

  const existingCards = document.querySelectorAll('.card.flipped');
  if (existingCards.length > 0) {
    existingCards.forEach(card => card.classList.remove('flipped'));
    setTimeout(setupNewGame, 600);
  } else {
    setupNewGame();
  }
}

function setupNewGame() {
  board.innerHTML = '';
  cards = shuffle(cards);
  flippedCards = [];
  matchedCount = 0;
  moves = 0;
  timer = 0;
  timerStarted = false;
  clearInterval(timerInterval);

  movesDisplay.textContent = moves;
  timerDisplay.textContent = timer;

  cards.forEach(imgSrc => {
    const card = document.createElement('div');
    card.classList.add('card');
    card.dataset.image = imgSrc;

    const inner = document.createElement('div');
    inner.classList.add('card-inner');

    const front = document.createElement('div');
    front.classList.add('card-front');

    const back = document.createElement('div');
    back.classList.add('card-back');
    const img = document.createElement('img');
    img.src = imgSrc;
    back.appendChild(img);

    inner.appendChild(front);
    inner.appendChild(back);
    card.appendChild(inner);

    card.addEventListener('click', flipCard);
    board.appendChild(card);
  });
}
function flipCard() {
  if (!timerStarted) {
    timerStarted = true;
    startTimer();
  }

  if (flippedCards.length === 2 || this.classList.contains('flipped')) return;

  this.classList.add('flipped');
  flippedCards.push(this);

  if (flippedCards.length === 2) {
    moves++;
    movesDisplay.textContent = moves;
    checkMatch();
  }
}

function checkMatch() {
  const [card1, card2] = flippedCards;

  if (card1.dataset.image === card2.dataset.image) {
    matchedCount += 2;
    flippedCards = [];

    if (matchedCount === cards.length) {
      clearInterval(timerInterval);
      setTimeout(() => alert(`🎉 You won in ${moves} moves and ${timer} seconds!`), 300);
    }
  } else {
    setTimeout(() => {
      card1.classList.remove('flipped');
      card2.classList.remove('flipped');
      flippedCards = [];
    }, 1000);
  }
}

function startTimer() {
  timerInterval = setInterval(() => {
    timer++;
    timerDisplay.textContent = timer;
  }, 1000);
}

restartBtn.addEventListener('click', startGame);

setupNewGame();
