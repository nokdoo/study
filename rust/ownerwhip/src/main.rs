fn main() {
    let s1 = gives_ownership();

    let s2 = &s1;

    let s3 = &s1;
}

fn gives_ownership() -> String {
    let some_string = String::from("hello");
    some_string
}

fn takes_and_gives_back(a_string: String) -> String {
    a_string
}
