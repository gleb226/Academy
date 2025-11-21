# Contact Manager

A modern C++ console application for efficient contact management with persistent JSON storage.

## Overview

Contact Manager is a simple yet powerful command-line tool that allows you to organize and manage your contacts efficiently. Built with modern C++ practices, it provides a clean interface for contact operations and stores all data in a human-readable JSON format.

## Features

### Core Functionality
- **Add Contacts** - Create new contact entries with name, phone number, and email address
- **View All Contacts** - Display a complete list of all saved contacts with formatted output
- **Search Contacts** - Find specific contacts by their exact name
- **Remove Contacts** - Delete unwanted contact entries from the database
- **Auto-Save** - Automatic persistence to JSON file after every modification
- **Input Validation** - Built-in validation for email addresses and phone numbers

### Technical Highlights
- Modern C++17 implementation
- CMake build system with vcpkg package management
- JSON serialization using nlohmann-json library
- Professional string formatting with fmt library
- Clean separation of concerns with library and executable architecture
- Cross-platform compatibility (Windows, Linux, macOS)

## Requirements

### Build Tools
- **CMake** 3.20 or higher
- **C++ Compiler** with C++17 support
    - GCC 7+
    - Clang 5+
    - MSVC 2017+
- **vcpkg** package manager

### Dependencies
- **nlohmann-json** - Modern JSON library for C++
- **fmt** - Fast and safe alternative to iostream for text formatting

## Installation

### Step 1: Install vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
```

**Windows:**
```powershell
.\bootstrap-vcpkg.bat
```

**Linux/macOS:**
```bash
./bootstrap-vcpkg.sh
```

### Step 2: Install Dependencies

```bash
./vcpkg install nlohmann-json fmt
```

### Step 3: Clone the Project

```bash
git clone <repository-url>
cd ContactManager
```

### Step 4: Build the Project

```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

**For Release build:**
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build . -j4
```

## Usage

### Running the Application

**Linux/macOS:**
```bash
./ContactManager
```

**Windows:**
```powershell
.\ContactManager.exe
```

### Menu Options

```
=== Contact Manager ===
1. Add contact
2. View all contacts
3. Find contact
4. Remove contact
5. Exit
Choose option:
```

### Example Workflow

**Adding a Contact:**
```
Choose option: 1
Enter name: John Doe
Enter phone: +380501234567
Enter email: john.doe@example.com
Contact added successfully
```

**Viewing All Contacts:**
```
Choose option: 2

=== All Contacts ===
Name: John Doe
Phone: +380501234567
Email: john.doe@example.com
-------------------
Name: Jane Smith
Phone: +380672223344
Email: jane.smith@example.com
-------------------
```

**Finding a Contact:**
```
Choose option: 3
Enter name to search: John Doe

=== Contact Found ===
Name: John Doe
Phone: +380501234567
Email: john.doe@example.com
```

**Removing a Contact:**
```
Choose option: 4
Enter name to remove: John Doe
Contact removed successfully
```

## Data Storage

### JSON Format

All contacts are stored in `contacts.json` in the same directory as the executable:

```json
{
    "contacts": [
        {
            "name": "John Doe",
            "phone": "+380501234567",
            "email": "john.doe@example.com"
        },
        {
            "name": "Jane Smith",
            "phone": "+380672223344",
            "email": "jane.smith@example.com"
        }
    ]
}
```

### File Location

The `contacts.json` file is automatically created in the working directory when you add the first contact.

## Project Structure

```
ContactManager/
├── CMakeLists.txt              # Main CMake configuration
├── vcpkg.json                  # vcpkg dependencies manifest
├── README.md                   # This file
│
├── include/                    # Public headers
│   └── contact_manager/
│       ├── contact.h           # Contact class definition
│       └── storage.h           # Storage manager definition
│
└── src/                        # Implementation files
    ├── contact.cpp             # Contact implementation
    ├── storage.cpp             # Storage implementation
    └── main.cpp                # Application entry point
```

## Architecture

### Components

**Contact Class**
- Represents a single contact entity
- Handles JSON serialization and deserialization
- Provides getters and setters for contact properties

**ContactStorage Class**
- Manages the collection of contacts
- Handles file I/O operations
- Implements CRUD operations
- Automatic save after modifications

**Main Application**
- User interface and menu system
- Input validation
- Command routing

## Input Validation

### Email Validation
- Must contain the '@' character
- Example valid emails: `user@example.com`, `contact@domain.org`

### Phone Validation
- Cannot be empty
- No format restrictions (international formats supported)
- Examples: `+380501234567`, `123-456-7890`, `555-0123`

## Error Handling

The application handles the following error cases:
- Missing or corrupted JSON file (creates new database)
- Invalid JSON format (clears database and starts fresh)
- Empty phone number input
- Invalid email format (missing '@')
- Contact not found during search/removal operations
- File I/O errors

## Building for Different Configurations

### Debug Build
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

### Release Build
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

### Multi-threaded Compilation
```bash
cmake --build . -j4
```

## Platform-Specific Notes

### Windows
- Use backslashes in paths: `C:\vcpkg\scripts\buildsystems\vcpkg.cmake`
- Executable located in: `.\Debug\ContactManager.exe` or `.\Release\ContactManager.exe`

### Linux/macOS
- Use forward slashes in paths: `/home/user/vcpkg/scripts/buildsystems/vcpkg.cmake`
- Executable located in: `./ContactManager`
- May need to set execute permissions: `chmod +x ContactManager`

## Troubleshooting

### CMake cannot find vcpkg packages

**Solution:** Ensure CMAKE_TOOLCHAIN_FILE points to the correct vcpkg toolchain:
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=/absolute/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
```

### Packages not found after installation

**Solution:** Verify packages are installed:
```bash
./vcpkg list
```

### Compilation errors with C++17

**Solution:** Ensure your compiler supports C++17:
- GCC: version 7 or higher
- Clang: version 5 or higher
- MSVC: Visual Studio 2017 or higher

## Development

### Compiler Warnings

The project is configured with strict warning levels:
- **MSVC:** `/W4`
- **GCC/Clang:** `-Wall -Wextra -Wpedantic`

### Adding New Features

The modular architecture makes it easy to extend functionality:
1. Add new methods to `ContactStorage` class for new operations
2. Implement the logic in `storage.cpp`
3. Add corresponding menu options in `main.cpp`

## License

This project is provided as-is for educational purposes.

## Resources

### Documentation
- [CMake Documentation](https://cmake.org/documentation/)
- [vcpkg Documentation](https://vcpkg.io/en/)
- [nlohmann-json GitHub](https://github.com/nlohmann/json)
- [fmt GitHub](https://github.com/fmtlib/fmt)

### Tutorials
- [Modern CMake Practices](https://cliutils.gitlab.io/modern-cmake/)
- [vcpkg Quick Start](https://github.com/microsoft/vcpkg#quick-start)
- [C++17 Features](https://en.cppreference.com/w/cpp/17)

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## Authors

Created as part of C++ CMake and vcpkg learning project.

## Acknowledgments

- nlohmann for the excellent JSON library
- fmt library developers for modern string formatting
- Microsoft vcpkg team for the package manager
- CMake developers for the build system

---

**Happy Contact Managing!**# Contact Manager

A modern C++ console application for efficient contact management with persistent JSON storage.

## Overview

Contact Manager is a simple yet powerful command-line tool that allows you to organize and manage your contacts efficiently. Built with modern C++ practices, it provides a clean interface for contact operations and stores all data in a human-readable JSON format.

## Features

### Core Functionality
- **Add Contacts** - Create new contact entries with name, phone number, and email address
- **View All Contacts** - Display a complete list of all saved contacts with formatted output
- **Search Contacts** - Find specific contacts by their exact name
- **Remove Contacts** - Delete unwanted contact entries from the database
- **Auto-Save** - Automatic persistence to JSON file after every modification
- **Input Validation** - Built-in validation for email addresses and phone numbers

### Technical Highlights
- Modern C++17 implementation
- CMake build system with vcpkg package management
- JSON serialization using nlohmann-json library
- Professional string formatting with fmt library
- Clean separation of concerns with library and executable architecture
- Cross-platform compatibility (Windows, Linux, macOS)

## Requirements

### Build Tools
- **CMake** 3.20 or higher
- **C++ Compiler** with C++17 support
    - GCC 7+
    - Clang 5+
    - MSVC 2017+
- **vcpkg** package manager

### Dependencies
- **nlohmann-json** - Modern JSON library for C++
- **fmt** - Fast and safe alternative to iostream for text formatting

## Installation

### Step 1: Install vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
```

**Windows:**
```powershell
.\bootstrap-vcpkg.bat
```

**Linux/macOS:**
```bash
./bootstrap-vcpkg.sh
```

### Step 2: Install Dependencies

```bash
./vcpkg install nlohmann-json fmt
```

### Step 3: Clone the Project

```bash
git clone <repository-url>
cd ContactManager
```

### Step 4: Build the Project

```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

**For Release build:**
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build . -j4
```

## Usage

### Running the Application

**Linux/macOS:**
```bash
./ContactManager
```

**Windows:**
```powershell
.\ContactManager.exe
```

### Menu Options

```
=== Contact Manager ===
1. Add contact
2. View all contacts
3. Find contact
4. Remove contact
5. Exit
Choose option:
```

### Example Workflow

**Adding a Contact:**
```
Choose option: 1
Enter name: John Doe
Enter phone: +380501234567
Enter email: john.doe@example.com
Contact added successfully
```

**Viewing All Contacts:**
```
Choose option: 2

=== All Contacts ===
Name: John Doe
Phone: +380501234567
Email: john.doe@example.com
-------------------
Name: Jane Smith
Phone: +380672223344
Email: jane.smith@example.com
-------------------
```

**Finding a Contact:**
```
Choose option: 3
Enter name to search: John Doe

=== Contact Found ===
Name: John Doe
Phone: +380501234567
Email: john.doe@example.com
```

**Removing a Contact:**
```
Choose option: 4
Enter name to remove: John Doe
Contact removed successfully
```

## Data Storage

### JSON Format

All contacts are stored in `contacts.json` in the same directory as the executable:

```json
{
    "contacts": [
        {
            "name": "John Doe",
            "phone": "+380501234567",
            "email": "john.doe@example.com"
        },
        {
            "name": "Jane Smith",
            "phone": "+380672223344",
            "email": "jane.smith@example.com"
        }
    ]
}
```

### File Location

The `contacts.json` file is automatically created in the working directory when you add the first contact.

## Project Structure

```
ContactManager/
├── CMakeLists.txt              # Main CMake configuration
├── vcpkg.json                  # vcpkg dependencies manifest
├── README.md                   # This file
│
├── include/                    # Public headers
│   └── contact_manager/
│       ├── contact.h           # Contact class definition
│       └── storage.h           # Storage manager definition
│
└── src/                        # Implementation files
    ├── contact.cpp             # Contact implementation
    ├── storage.cpp             # Storage implementation
    └── main.cpp                # Application entry point
```

## Architecture

### Components

**Contact Class**
- Represents a single contact entity
- Handles JSON serialization and deserialization
- Provides getters and setters for contact properties

**ContactStorage Class**
- Manages the collection of contacts
- Handles file I/O operations
- Implements CRUD operations
- Automatic save after modifications

**Main Application**
- User interface and menu system
- Input validation
- Command routing

## Input Validation

### Email Validation
- Must contain the '@' character
- Example valid emails: `user@example.com`, `contact@domain.org`

### Phone Validation
- Cannot be empty
- No format restrictions (international formats supported)
- Examples: `+380501234567`, `123-456-7890`, `555-0123`

## Error Handling

The application handles the following error cases:
- Missing or corrupted JSON file (creates new database)
- Invalid JSON format (clears database and starts fresh)
- Empty phone number input
- Invalid email format (missing '@')
- Contact not found during search/removal operations
- File I/O errors

## Building for Different Configurations

### Debug Build
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

### Release Build
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

### Multi-threaded Compilation
```bash
cmake --build . -j4
```

## Platform-Specific Notes

### Windows
- Use backslashes in paths: `C:\vcpkg\scripts\buildsystems\vcpkg.cmake`
- Executable located in: `.\Debug\ContactManager.exe` or `.\Release\ContactManager.exe`

### Linux/macOS
- Use forward slashes in paths: `/home/user/vcpkg/scripts/buildsystems/vcpkg.cmake`
- Executable located in: `./ContactManager`
- May need to set execute permissions: `chmod +x ContactManager`

## Troubleshooting

### CMake cannot find vcpkg packages

**Solution:** Ensure CMAKE_TOOLCHAIN_FILE points to the correct vcpkg toolchain:
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=/absolute/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
```

### Packages not found after installation

**Solution:** Verify packages are installed:
```bash
./vcpkg list
```

### Compilation errors with C++17

**Solution:** Ensure your compiler supports C++17:
- GCC: version 7 or higher
- Clang: version 5 or higher
- MSVC: Visual Studio 2017 or higher

## Development

### Compiler Warnings

The project is configured with strict warning levels:
- **MSVC:** `/W4`
- **GCC/Clang:** `-Wall -Wextra -Wpedantic`

### Adding New Features

The modular architecture makes it easy to extend functionality:
1. Add new methods to `ContactStorage` class for new operations
2. Implement the logic in `storage.cpp`
3. Add corresponding menu options in `main.cpp`

## License

This project is provided as-is for educational purposes.

## Resources

### Documentation
- [CMake Documentation](https://cmake.org/documentation/)
- [vcpkg Documentation](https://vcpkg.io/en/)
- [nlohmann-json GitHub](https://github.com/nlohmann/json)
- [fmt GitHub](https://github.com/fmtlib/fmt)

### Tutorials
- [Modern CMake Practices](https://cliutils.gitlab.io/modern-cmake/)
- [vcpkg Quick Start](https://github.com/microsoft/vcpkg#quick-start)
- [C++17 Features](https://en.cppreference.com/w/cpp/17)

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

## Authors

Created as part of C++ CMake and vcpkg learning project.

## Acknowledgments

- nlohmann for the excellent JSON library
- fmt library developers for modern string formatting
- Microsoft vcpkg team for the package manager
- CMake developers for the build system

---

**Happy Contact Managing!**