extern crate rand;

use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
  println!("Guess the number!");
  println!("Please input your guess.");

  let secret_number = rand::thread_rng().gen_range(1, 101);

  // Takes pointer to guess, and since 'guess' is mutable
  // we can just read_line into it.

  loop {
    let mut guess = String::new();

    io::stdin().read_line(&mut guess)
      .ok()
      .expect("Failed to read line");

    // We handle the error by matching result
    let guess: u32 = match guess.trim().parse() {
      Ok(num) => num,
      Err(_) => continue
    };

    // Q: println is smart enough to take the type of 'guess'?
    println!("You guessed: {}", guess);

    match guess.cmp(&secret_number) {
      Ordering::Less => println!("Too small!"),
      Ordering::Greater => println!("Too big!"),
      Ordering::Equal => {
        println!("You win!");
        break;
      }
    }
  }
}
