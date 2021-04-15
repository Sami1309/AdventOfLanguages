// use std::env;
use std::fs;

fn main() {

    
    let contents = fs::read_to_string("data/7.in")
        .expect("Error reading file");
    println!("test:\n{}", contents);
}