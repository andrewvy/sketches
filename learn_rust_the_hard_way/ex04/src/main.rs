use std::thread;
use std::sync::{Mutex, Arc};

// Table has forks, a vector of many mutexes
// Mutexes allow only a single thread to access
// its contents at a single time.

struct Table {
  forks: Vec<Mutex<()>>
}

struct Philosopher {
  name: String,
  left: usize,
  right: usize
}

impl Philosopher {
  fn new(name: &str, left: usize, right: usize) -> Philosopher {
    Philosopher {
      name: name.to_string(),
      left: left,
      right: right
    }
  }

  fn eat(&self, table: &Table) {
    let _left = table.forks[self.left].lock().unwrap();
    let _right = table.forks[self.right].lock().unwrap();

    println!("{} is eating.", self.name);

    thread::sleep_ms(1000);

    println!("{} is done eating.", self.name);
  }
}

fn main() {
  let table = Arc::new(Table { forks: vec![
    Mutex::new(()),
    Mutex::new(()),
    Mutex::new(()),
    Mutex::new(()),
    Mutex::new(())
  ]});

  let philosophers = vec![
    Philosopher::new("Judith Butler", 0, 1),
    Philosopher::new("Gilles Deleuze", 1, 2),
    Philosopher::new("Karl Marx", 2, 3),
    Philosopher::new("Emma Goldman", 3, 4),
    Philosopher::new("Michel Foucault", 0, 4)
  ];

  // We set the return type to be a vector of inferenced type
  // philosophers gets turned into an iterable, which we can then
  // map over the elements.
  let handles: Vec<_> = philosophers.into_iter().map(|p| {
    let table = table.clone();

    // move in this context allows the inner scope
    // to obtain ownership of p
    thread::spawn(move || {
      p.eat(&table);
    })

    // Collect is called to "collect" the values returned by map.
    // This is why Vec<_> is specified, so collect knows to create
    // a collection of that type.
  }).collect();

  for h in handles {
    h.join().unwrap();
  }
}
