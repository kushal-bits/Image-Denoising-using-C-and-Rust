# Outputs obtained by using same algorithm in `Rust` and `CPP`  

## Original Noisy Mona Lisa:  
![Mona Lisa](https://github.com/kushal-bits/Image-Denoising-using-Cpp-and-Rust/blob/main/tests/mona_lisa.pgm)  

## Using direct median filter:  
![median_filter](https://github.com/kushal-bits/Image-Denoising-using-Cpp-and-Rust/blob/main/Result/Medianfilter_monalisa.pnm)  

## Using modified median filter:  
![modified_median_filter](https://github.com/kushal-bits/Image-Denoising-using-Cpp-and-Rust/blob/main/Result/Modified_medianfilter_monalisa.pgm)

By updating the original image everytime along with creating the new image pixels, the continuous updation of values by median filter are providing higher accurate images with much lesser.

## Performance Comparision b/w C++ and Rust
For 
![Mona Lisa](https://github.com/kushal-bits/Image-Denoising-using-Cpp-and-Rust/blob/main/tests/mona_lisa.pgm) we compare the execution time taken by C++ and Rust.

### Time Taken by C++
![exec_time_cpp](https://github.com/kushal-bits/Image-Denoising-using-Cpp-and-Rust/blob/main/tests/exec_time_cpp.jpg)

### Time Taken by Rust
![exec_time_rs](https://github.com/kushal-bits/Image-Denoising-using-Cpp-and-Rust/blob/main/tests/exec_time_rs.jpeg)

