# 🚀 CPP Lab Tasks

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-blue.svg?style=for-the-badge)
![GitHub Stars](https://img.shields.io/github/stars/abhinavgautam08/labtask-cpp?style=for-the-badge)

**A collection of C++ programming exercises and lab assignments focused on fundamental concepts and problem-solving**

[Getting Started](#-getting-started) • [Programs](#-programs) • [Contributing](#-contributing)

</div>

---

## 📋 Overview

This repository contains a curated collection of C++ programming lab tasks designed to strengthen understanding of core programming concepts. Each program tackles different aspects of C++ programming, from basic syntax to more advanced concepts like data structures, algorithms, and object-oriented programming.

**Perfect for:**
- Students learning C++ fundamentals
- Practicing algorithmic problem-solving
- Preparing for coding assessments
- Building a portfolio of C++ projects

---

## ✨ Programs

<table>
<thead>
<tr>
<th>Program</th>
<th>Description</th>
<th>Concepts Covered</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>Prog1.cpp</code></td>
<td>Introduction to basic C++ syntax and operations</td>
<td>Variables, Input/Output, Basic Operations</td>
</tr>
<tr>
<td><code>Prog2.cpp</code></td>
<td>Control structures and conditional logic</td>
<td>If-else, Loops, Decision Making</td>
</tr>
<tr>
<td><code>Prog3.cpp</code></td>
<td>Functions and modular programming</td>
<td>Function Declaration, Parameters, Return Values</td>
</tr>
<tr>
<td><code>Prog4.cpp</code></td>
<td>Arrays and string manipulation</td>
<td>Arrays, Strings, Iteration</td>
</tr>
<tr>
<td><code>Prog5.cpp</code></td>
<td>Object-oriented programming concepts</td>
<td>Classes, Objects, Encapsulation</td>
</tr>
</tbody>
</table>

---

## 🛠️ Getting Started

### Prerequisites

Ensure you have the following installed on your system:

- **C++ Compiler**: GCC 7.0+ or Clang 5.0+
- **Operating System**: Windows, macOS, or Linux
- **Build Tools** (optional): CMake 3.10+ or Make

#### Installing a C++ Compiler

**Linux (Ubuntu/Debian):**
```bash
sudo apt update
sudo apt install g++ build-essential
```

**macOS:**
```bash
xcode-select --install
```

**Windows:**
- Install [MinGW-w64](https://www.mingw-w64.org/) or [Visual Studio](https://visualstudio.microsoft.com/)

### Installation

1. **Clone the repository**
```bash
git clone https://github.com/abhinavgautam08/labtask-cpp.git
cd labtask-cpp
```

2. **Verify compiler installation**
```bash
g++ --version
```

### Usage

#### Compile and Run Individual Programs

**Using g++:**
```bash
# Compile
g++ Prog1.cpp -o prog1

# Run
./prog1
```

**Using clang++:**
```bash
# Compile
clang++ Prog1.cpp -o prog1

# Run
./prog1
```

#### Compile All Programs

**Linux/macOS:**
```bash
# Create output directory
mkdir -p build

# Compile all programs
for file in Prog*.cpp; do
    g++ "$file" -o "build/${file%.cpp}" -std=c++17 -Wall -Wextra
done
```

**Windows (PowerShell):**
```powershell
# Create output directory
New-Item -ItemType Directory -Force -Path build

# Compile all programs
Get-ChildItem Prog*.cpp | ForEach-Object {
    g++ $_.Name -o "build/$($_.BaseName).exe" -std=c++17 -Wall -Wextra
}
```

### Testing

Run each compiled program to test functionality:

```bash
# Linux/macOS
./build/prog1
./build/prog2
# ... and so on

# Windows
.\build\prog1.exe
.\build\prog2.exe
# ... and so on
```

---

## 📁 Project Structure

```
labtask-cpp/
│
├── Prog1.cpp          # Basic C++ programming concepts
├── Prog2.cpp          # Control flow and loops
├── Prog3.cpp          # Functions and modularity
├── Prog4.cpp          # Arrays and strings
├── Prog5.cpp          # Object-oriented programming
└── README.md          # Project documentation
```

---

## 🗺️ Project Roadmap

- [x] **Phase 1**: Basic syntax and I/O operations
- [x] **Phase 2**: Control structures implementation
- [ ] **Phase 3**: Advanced data structures (Linked Lists, Stacks, Queues)
- [ ] **Phase 4**: Algorithm implementations (Sorting, Searching)
- [ ] **Phase 5**: File handling and stream operations
- [ ] **Phase 6**: Template programming and STL

---

## 🤝 Contributing

Contributions are welcome! Whether it's bug fixes, new features, or improved documentation, your help is appreciated.

### How to Contribute

1. **Fork the repository**
   ```bash
   # Click the 'Fork' button on GitHub
   ```

2. **Clone your fork**
   ```bash
   git clone https://github.com/YOUR_USERNAME/labtask-cpp.git
   cd labtask-cpp
   ```

3. **Create a feature branch**
   ```bash
   git checkout -b feature/amazing-feature
   ```

4. **Make your changes**
   - Write clean, documented code
   - Follow C++ best practices
   - Add comments where necessary

5. **Commit your changes**
   ```bash
   git commit -m "Add: Implemented amazing feature"
   ```

6. **Push to your fork**
   ```bash
   git push origin feature/amazing-feature
   ```

7. **Open a Pull Request**
   - Go to the original repository
   - Click "New Pull Request"
   - Describe your changes clearly

### Contribution Guidelines

- Use meaningful variable and function names
- Follow consistent code formatting
- Add comments for complex logic
- Test your code before submitting
- Update documentation if needed

---

## 📝 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- C++ Standard Library Documentation
- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ reference
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Programming tutorials
- All contributors who have helped improve this project

---

## 📧 Contact

**Abhinav Gautam** - [@abhinavgautam08](https://github.com/abhinavgautam08)

Project Link: [https://github.com/abhinavgautam08/labtask-cpp](https://github.com/abhinavgautam08/labtask-cpp)

---

<div align="center">

**⭐ Star this repository if you find it helpful!**

Made with ❤️ by [Abhinav Gautam](https://github.com/abhinavgautam08)

</div>
