use std::fs::File;
use std::io::{BufRead, BufReader, BufWriter, Write};
use std::time::Instant;


fn main() -> std::io::Result<()> {

    let start_time = Instant::now();

    let mut arra: Vec<Vec<i32>> = vec![vec![0; 2000]; 2000];
    let mut arr: Vec<Vec<i32>> = vec![vec![0; 2000]; 2000];
    let mut window: [i32; 9] = [0; 9];
    let mut row = 0;
    let mut col = 0;
    let mut numrows = 0;
    let mut numcols = 0;
    let mut max = 0;

    let file = File::open("mona_lisa.pgm")?;
    let reader = BufReader::new(file);

    // Read the file line by line
    let mut lines = reader.lines();
    if let Some(Ok(input_line)) = lines.next() {
        if input_line != "P2" {
            eprintln!("Version error");
        } else {
            println!("Version : {}", input_line);
        }
    }

    // Parse image size 
    if let Some(Ok(size_line)) = lines.next() {
        let mut parts = size_line.split_whitespace();
        if let (Some(cols), Some(rows)) = (parts.next(), parts.next()) {
            numcols = cols.parse().unwrap();
            numrows = rows.parse().unwrap();
            println!("{} columns and {} rows", numcols, numrows);
           
        }
    }

    // parsing maximum intensity 
    if let Some(Ok(size_line)) = lines.next()
    {
        let mut parts = size_line.split_whitespace();
        if let (Some(max_val)) = (parts.next()) {
            max = max_val.parse().unwrap();
            println!("Maximum Intensity {}", max);
        }
    }

    for row in 0..=numrows {
        arra[row][0] = 0;
    }
    for col in 0..=numcols {
        arra[0][col] = 0;
    }

    for row in 1..=numrows {
        if let Some(Ok(data_line)) = lines.next() {
            let mut parts = data_line.split_whitespace();
            for col in 1..=numcols {
                if let Some(value) = parts.next() {
                    arra[row][col] = value.parse().unwrap();
                }
            }
        }
        
    }

    for row in 1..=numrows {
        for col in 1..=numcols {
            window[0] = arra[row - 1][col - 1];
            window[1] = arra[row - 1][col];
            window[2] = arra[row - 1][col + 1];
            window[3] = arra[row][col - 1];
            window[4] = arra[row][col];
            window[5] = arra[row][col + 1];
            window[6] = arra[row + 1][col - 1];
            window[7] = arra[row + 1][col];
            window[8] = arra[row + 1][col + 1];

            window.sort();

            arra[row][col] = window[4];
            arr[row][col] = arra[row][col];
        }
    }

    let mut outfile = BufWriter::new(File::create("Medianfilter_monalisa1.pgm")?);
    writeln!(outfile, "P2")?;
    writeln!(outfile, "{} {}", numcols, numrows)?;
    writeln!(outfile, "255")?;

    for row in 1..=numrows {
        for col in 1..=numcols {
            write!(outfile, "{} ", arr[row][col])?;
        }
    }
    
    let end_time = Instant::now();

    // Calculate the elapsed time
    let elapsed_time = end_time - start_time;

    // Print the elapsed time in milliseconds
    println!("Execution time: {} milliseconds", elapsed_time.as_millis());

    Ok(())
}
