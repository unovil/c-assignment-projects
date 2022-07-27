# Using `setjmp()` and `longjmp()`

Write a C program that uses these to handle program errors
- when discovering an unrecoverable error,
  - transfer control to main input loop and start again
- make a function named `error_recovery()` that
  - prints an error
  - uses `longjmp()` to transfer back
- `main()` should include an infinite loop for `setjmp()` before processing
- you can add dummy code that simulates an error by calling `error_recover()`