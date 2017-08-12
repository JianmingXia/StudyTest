import { greeter, addHtmlContent } from './Utils';
import Student from './Student';
declare var IS_PRODUCTION: any;
declare var LOCAL_DEVELOP: any;

let user = new Student("TypeScript", "User");


addHtmlContent("content", greeter(user));

addHtmlContent("content", "\n" + user.fullName);


if (IS_PRODUCTION) {
  addHtmlContent("content", "\nIS_PRODUCTION");
} else if (LOCAL_DEVELOP) {
  addHtmlContent("content", "\nLOCAL_DEVELOP");
}