


const MAX_POINTS: u32 = 100_000;
const MAX_POINTS1: u32 = 100000;


fn main() {
    // mut
    let mut x = 5;
    println!("The value of x is : {}",x);
    x = 6;
    println!("The value of x is : {}",x);

    // constants
    println!("The contants is : {}",MAX_POINTS);
    println!("The contants is : {}",MAX_POINTS1);

    // Shadow
    let x = 5;
    let x = x + 1;
    let x = x * 2;
    println!("The value of x is: {}", x);

    
    let spaces = "   ";
    let spaces = spaces.len();
    println!("The length of spaces is: {}", spaces);
}

