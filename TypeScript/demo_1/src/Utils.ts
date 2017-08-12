interface Person {
  firstName: string;
  lastName: string;
}

function greeter(person: Person) {
  return "Hello, " + person.firstName + " " + person.lastName + " !";
}

function addHtmlContent(id: string, content: string) {
  let div = document.getElementById(id);
  div.innerText += content;
}

export { greeter, addHtmlContent }