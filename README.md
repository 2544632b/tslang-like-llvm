Use guide:

Create a variable:
```typescript
let a = 10;
let b = "hello world!";
let c = 3.14;
let d = true;
```

Nullish operator:
```typescript
let test: string = get_string() ?? "You should enter something....";
print_string_ln(test);

// input: xxx
// output: xxx
// input: <empty>
// output: You should enter something....
```

If is static:
```typescript
const x = 10;
const str = "hello!";

// P.S.: Do not written like this!
const variable: string = <StringLiteral> ?? "Default string"; // <- ERROR
```

TODO: Union type
```typescript
let variable: string|boolean = "hello world!";
let var2: number|boolean = true;
```

Create a array:
```typescript
let arr = [0, 1, 2, 3, 4, 5, 6, ... <n>];
let arr2: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, ... <n>];
let arr3: string[] = ["orange", "tomato", "potato", "apple"];
let arr4: boolean[] = [true, false, false, true, true];
```

Push & pop:
```typescript
let arr: string[] = [];
push_back_string("apple");
push_back_string("tomato");

// Current array: ["apple", "tomato"]

print_string_ln(arr[0]);
```

Array foreach:
```typescript
let arr = [0, 1, 2, 3, 4, 5, 6, ... <n>];

for(let i = 0; i < array_length(arr); ++i) {
  print_number(arr[i]);
  print_string(" ");
}
```

Function:
```typescript
function hello(args1: number, args2: string, args3: boolean, args4: number[], args5: string[]) {
  //....
}

function hello2(....): string {
  // ....
  return "xxxx";
}
```

Condition expression:
```typescript
function test(str: string) {
  return str == "hi" ? "hello" : "You should say hi.";
}
```

BUGs: Number array may be zero if in some functions:
```typescript
let arr = [1, 2, 3, 4, 5, 6]; // <- Number array
// let arr: number[] = [1, 2, 3, 4, 5, 6];  // output: [1, 2, 3, 4, 5, 6]

function test(arr: number[]) {
  for(let i = 0; i < array_length(arr); ++i) {
    print_number(arr[i]);
    print_string(" ");
  }
  print_ln();
}
test(arr);
// output: [0, 0, 0, 0, 0, 0]

test([0, 1, 2, 3, 4, 5, 6]);
// output: [0, 0, 0, ..., 0];
```
