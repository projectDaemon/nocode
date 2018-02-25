extern crate ffgrep;

use std::env;
use std::process;

use ffgrep::Config;

fn main() {
    let args: Vec<String> = env::args().collect();

    let config = Config::new(&args).unwrap_or_else(|err|{
        eprintln!("Problem parsing arguments: {}",err);
        process::exit(1);
    });

    // println!("{:?}",args);
    // println!("Searching for {}",config.query);
    // println!("In file {}",config.filename);

    if let Err(e) = ffgrep::run(config){
        eprintln!("Application error : {}",e);
        process::exit(1);
    }
}
