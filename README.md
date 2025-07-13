# Smart Contact

The **Smart Contact** is a console-based application developed in C++. It allows users to manage contact records efficiently, supporting operations like add, update, delete, search, sort, and display.

## Key Features

### Contact Management
- Each contact includes:
  - Unique ID
  - Name
  - Phone number
  - Email
  - Address
- Auto-generation of unique IDs
- Phone number uniqueness validation

### Search Functionality
- Search by **Name** (partial match)
- Search by **Phone Number** (partial match)
- Search by **ID** (exact match)

### Contact Operations
- Add new contacts
- Update existing contacts
- Delete contacts
- Display all contacts
- Sort contacts alphabetically by name

### Data Structure
- Uses `std::vector<Contact>` for dynamic contact storage
- Efficient searching and sorting using standard algorithms


## Technologies Used
- **Language:** C++
- **Libraries:** `<iostream>`, `<vector>`, `<string>`, `<algorithm>`, `<limits>`

