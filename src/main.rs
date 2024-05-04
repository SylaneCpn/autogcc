use std::process::Command;

enum Flags {
    Clean,
    Unknown,
}

fn add_flags(args: Vec<String>) -> Vec<Flags> {
    let mut flags = Vec::new();
    args.iter().map(|x| x.as_str()).for_each(|x| match x {
        "--clean" => flags.push(Flags::Clean),
        _ => flags.push(Flags::Unknown),
    });
    flags
}

fn main() {
    let paths = std::fs::read_dir("./").unwrap();
    let binding = std::env::current_dir().unwrap();
    let exe_name = binding.file_name().unwrap();
    let args: Vec<String> = std::env::args().collect();

    let _flags = add_flags(args.clone());

    if args.len() == 1 {
        let mut o_files_buffer = Vec::new();
        //unwraps the item
        paths
            .map(|p| p.unwrap())
            //check if is a file and not a directory
            .filter(|e| e.metadata().unwrap().is_file())
            //get the file name
            .map(|x| x.file_name().into_string().unwrap())
            //only the .ts file
            .filter(|s| s.ends_with(".c"))
            //call gcc for each file
            .for_each(|t| {
                o_files_buffer.push(t.clone().replace(".c", ".o"));
                let mut c = Command::new("gcc")
                    .arg(t)
                    .arg("-c")
                    .spawn()
                    .expect("gcc command failed to start");
                let _ = c.wait();
            });

        //build
        let mut build = Command::new("gcc")
            .args(&o_files_buffer[..])
            .arg("-o")
            .arg(exe_name)
            .spawn()
            .expect("gcc command failed to start");

        let _ = build.wait();
    } else if (args[1] == "--clean") && (args.len() == 2) {
        //unwraps the item
        paths
            .map(|p| p.unwrap())
            //check if is a file and not a directory
            .filter(|e| e.metadata().unwrap().is_file())
            //get the file name
            .map(|x| x.file_name().into_string().unwrap())
            //only the .ts file
            .filter(|s| s.ends_with(".o") || (s.as_str() == exe_name.to_str().unwrap()))
            //call gcc for each file
            .for_each(|t| {
                let mut c = Command::new("rm").arg(t).spawn().expect("failed to rm");
                let _ = c.wait();
            });
    }
}
