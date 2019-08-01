let a;
function f(x, y) {
    console.log(arguments.length);
    console.log(arguments.callee);
    a = arguments.callee;
}

f(1);
a(1);
