open SharedTypes;

open Utils;

let setStatus = (gameState: gameState) =>
  switch (gameState) {
  | Playing(Cross) => "X's are playing"
  | Playing(Circle) => "O's are playing"
  | Winner(Cross) => "X's Win!"
  | Winner(Circle) => "O's Win!"
  | Draw => "Draw"
  };

let component = ReasonReact.statelessComponent("Board");

let make = (~state: state, ~onMark, ~onRestart, _children) => {
  ...component,
  render: _ =>
    <div className="game-board">
      (
        state.board
        |> List.mapi((index: int, row: row) =>
             <BoardRow
               key=(string_of_int(index))
               gameState=state.gameState
               row
               onMark
               index
             />
           )
        |> Array.of_list
        |> ReasonReact.arrayToElement
      )
      <div className="status">
        (state.gameState |> setStatus |> toString)
      </div>
      (
        switch (state.gameState) {
        | Playing(_) => ReasonReact.nullElement
        | _ =>
          <button className="restart" onClick=onRestart>
            (toString("Restart"))
          </button>
        }
      )
    </div>,
};