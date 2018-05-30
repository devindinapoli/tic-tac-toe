/* Instead of import, we use 'open' to call other components */
open Utils;

/* Component is created */
let component = ReasonReact.statelessComponent("App");

/* Render elements to the screen */
let make = _children => {
  ...component,
  render: _self =>
    <div>
      <div className="title"> (toString("Tic Tac Toe")) </div>
      <Game />
    </div>,
};