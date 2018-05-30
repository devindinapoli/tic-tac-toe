/* Define our player variant */
type player =
  | Cross
  | Circle;

/* Define our field variant */
type field =
  | Empty
  | Marked(player);

/* Here we define our playing board */
type row = list(field);
type board = list(row);

/* Defines our game state (ie. whose turn, who won, or if it's a draw) */
type gameState =
  | Playing(player)
  | Winner(player)
  | Draw;

type state = {
  board,
  gameState,
};