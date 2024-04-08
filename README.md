# Sales Data Analysis Program

This C++ program is designed to process sales data for a company with six salespeople. It calculates various sales metrics, generates an annual sales report, and identifies the salesperson and quarter with the highest sales.

## Features

- Reads salesperson data from an input file.
- Processes sales data from another input file.
- Calculates total sales by quarter and by salesperson.
- Prints an annual sales report in a tabular format.
- Identifies the salesperson with the maximum total sales for the year.
- Identifies the quarter with the maximum total sales for the year.

## How to Use

1. **Clone the Repository:**
   ```
   git clone https://github.com/AdamAlbaghali/SalesDataAnalysis.git
   ```

2. **Compile the Program:**
   ```
   g++ main.cpp -o 1.cpp
   ```

3. **Run the Program:**
   ```
   ./a.out
   ```

4. **Input Files:**
   - SalesManID.txt: Contains salesperson IDs.
   - SalesData.txt: Contains sales data (salesperson ID, month, sale amount).

5. **Output:**
   - SalesdataAnalysis.txt: Contains the generated annual sales report and identified maximum sales by salesperson and quarter.

## Requirements

- C++ compiler (GCC or Clang recommended)
- Input files: SalesManID.txt, SalesData.txt

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests for any improvements or bug fixes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
