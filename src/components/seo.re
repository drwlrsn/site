let component = ReasonReact.statelessComponent("SEO");
module Helmet = Gatsby.Helmet;

let make =
    (
      ~description=?,
      ~lang="en",
      ~meta: list(Helmet.meta)=[],
      ~keywords=[],
      ~title,
      _children,
    ) => {
  ...component,
  render: _self => {
    let titleProp = title;
    let a =
      Js.Dict.fromList([
        ("name", "keywords"),
        ("content", String.concat(", ", keywords)),
      ]);
    let b =
      Js.Dict.fromList([
        ("name", "description"),
        ("content", "replace me with metaDescription"),
      ]);
    let m = meta @ [a, b];
    let htmlAttributes = {"lang": lang};
    let titleTemplate = "%s | Replace me with: data.site.siteMetadata.title}";

    <Helmet titleTemplate title meta=m htmlAttributes />;
  },
};

[@bs.deriving abstract]
type jsProps = {
  description: Js.nullable(string),
  lang: string,
  keywords: list(string),
  title: string,
  meta: list(Helmet.meta),
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~title=jsProps->titleGet,
      ~description=Js.Nullable.toOption(jsProps->descriptionGet),
      ~lang=jsProps->langGet,
      ~keywords=jsProps->keywordsGet,
      ~meta=jsProps->metaGet,
      [||],
    )
  );