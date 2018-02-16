
#![allow(unused_variables)]
fn main() {
    let guess: u32 = "42".parse().expect("Not a number!");

    let x = 2.0; // f64
    let y: f32 = 3.0; // f32


    let tup: (i32, f64, u8) = (500, 6.4, 1);
    
    let tup = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of y is: {}", y);


    let x: (i32, f64, u8) = (500, 6.4, 1);
    let five_hundred = x.0;
    let six_point_four = x.1;
    let one = x.2;


    let months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];


    let a = [1, 2, 3, 4, 5];
    let index = 10;
    let element = a[index];
    println!("The value of element is: {}", element);
}
