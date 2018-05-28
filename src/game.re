[%bs.raw {|require('./game.css)|}];

open SharedTypes;

type action = 
  | ClickSquare(string)
  | Restart;

type winner = 
  | Cross
  | Circle
  | NoOne;

type winningRows = list(list(int));

let winningCombs = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
];

let gameEnded = board =>
List.for_all(
    field => field == Marked(Circle) || field == Marked(Cross),
    board,
);

let whosPlaying = (gameState: gameState) =>
    switch (gameState) {
    | Playing(Cross) => Playing(Circle)
    | _ => Playing(Cross)
    };

let getWinner = (flattenBoard, coords) =>
    switch (
        List.nth(flattenBoard, List.nth(coords, 0)),
        List.nth(flattenBoard, List.nth(coords, 1)),
        List.nth(flattenBoard, List.nth(coords, 2)),
    ) {
    | (Marked(Cross), Marked(Cross), Marked(Cross)) => Cross
    | (Marked(Circle), Marked(Circle), Marked(Circle)) => Circle
    | (_, _, _) => NoOne
    };