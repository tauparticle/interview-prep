/*
 * This is a JavaScript Scratchpad.
 *
 * Enter some JavaScript, then Right Click or choose from the Execute Menu:
 * 1. Run to evaluate the selected text (Ctrl+R),
 * 2. Inspect to bring up an Object Inspector on the result (Ctrl+I), or,
 * 3. Display to insert the result in a comment after the selection. (Ctrl+L)
 */

var x = Math.round(Math.random() * 15);


if (x % 3 === 0 && x != 0) {
  console.log("fizz");
}
else if (x % 5 === 0 && x != 0) {
  console.log("Buzz");
}
else if (x % 3 === 0 && x % 5 === 0 {
  console.log("FizzBuzz");
}
else {
  console.log(x);
}
/*
Exception: TypeError: Math.Random is not a function
@Scratchpad/1:10:9
*/
/*
undefined
*/