import { greeter, addHtmlContent } from './Utils';
import Student from './Student';

let user = new Student("TypeScript", "User");


addHtmlContent("content", greeter(user));

addHtmlContent("content", "\n" + user.fullName);