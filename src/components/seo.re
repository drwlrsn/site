let component = ReasonReact.statelessComponent("SEO");
module Helmet = Gatsby.Helmet;

let make =
    (~description=?, ~lang="en", ~meta=[], ~keywords=[], ~title, _children) => {
  ...component,
  render: _self => {
    let meta = meta @ [Helmet.{name: "keywords", content: String.concat(", ", keywords)}]
    let htmlAttributes = Helmet.{lang: lang};

    <Helmet
      title
      meta
      htmlAttributes
    />;
  },
};

[@bs.deriving abstract]
type jsProps = {
  description: Js.nullable(string),
  lang: string,
  keywords: list(string),
  title: string,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~title=jsProps->titleGet,
      ~description=Js.Nullable.toOption(jsProps->descriptionGet),
      ~lang=jsProps->langGet,
      ~keywords=jsProps->keywordsGet,
      [||],
    )
  );