
let component = ReasonReact.statelessComponent("Seo");
module Helmet = Gatsby.Helmet;

let make = (~description=?, ~lang="en", ~meta=[], ~keywords=[], ~title, _children) => {
  ...component,
  render: _self => <Helmet title="Hi" />
};