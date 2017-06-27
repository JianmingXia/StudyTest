const { h, app } = require("hyperapp")
const hyperx = require("hyperx")
const html = hyperx(h)

app({
  state: "Hi.",
  view: state => html`<h1>${state}</h1>`
})
