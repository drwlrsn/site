module Helmet = {
  [@bs.module "react-helmet"]
  external linkClass : ReasonReact.reactClass = "default";
  type metaT =
    option(
      array(
        {
          .
          "name": string,
          "content": string,
        },
      ),
    );
  let make =
      (~title: option(string)=?, ~bodyAttributes=?, ~meta: metaT=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=linkClass,
      ~props={
        "title": Js.Nullable.fromOption(title),
        "bodyAttributes": Js.Nullable.fromOption(bodyAttributes),
        "meta": Js.Nullable.fromOption(meta),
      },
      children,
    );
};

/*
 module Helmet = {
   [@bs.module "react-helmet"]
   external helmet: ReasonReact.reactClass = "default";

   type htmlAttributes = {lang: string};
   type meta = {
     name: string,
     content: string,
   };

   [@bs.deriving abstract]
   type jsProps = {
     htmlAttributes: Js.nullable(htmlAttributes),
     title: string,
     titleTemplate: Js.nullable(string),
     meta: Js.nullable(list(meta)),
   };

   let make = (~htmlAttributes=?, ~titleTemplate=?, ~meta=?, ~title, _children) =>
     ReasonReact.wrapJsForReason(
       ~reactClass=helmet,
       ~props=
         jsProps(
           ~htmlAttributes=Js.Nullable.fromOption(htmlAttributes),
           ~titleTemplate=Js.Nullable.fromOption(titleTemplate),
           ~meta=Js.Nullable.fromOption(meta),
           ~title,
         ),
     );
 };

 module StaticQuery = {
   [@bs.module "gatsby"]
   external staticQuery: ReasonReact.reactClass = "StaticQuery";
   type render = unit => ReasonReact.reactElement;

   [@bs.deriving abstract]
   type jsProps = {
     query: unit => unit,
     render: unit => ReasonReact.reactElement,
   };
   let make = (~query, ~render, _children) =>
     ReasonReact.wrapJsForReason(
       ~reactClass=staticQuery,
       ~props=jsProps(~query, ~render),
     );
 };
 */