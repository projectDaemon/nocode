fn main() {
    let number = 3;

    if number < 5 {
        println!("condition was true");
    } else {
        println!("condition was false");
    }


    // let condition = true;
//
    // let number = if condition {
        // 5
    // } else {
        // "six"
    // };
//
    // println!("The value of number is: {}", number);


    let a = [10, 20, 30, 40, 50];

    for element in a.iter() {
        println!("the value is: {}", element);
    }

    for number in 1..4 {
        println!("{}!", number);
    }

    for number in (1..4).rev() {
        println!("{}!", number);
    }
    println!("LIFTOFF!!!");
}

