/**
 * @file README.md
 * @brief Simple Calculator Application using Qt (C++)
 * @author Prateek Narkhede
 *
 * @section description Description
 *
 * This project is a GUI-based Calculator application developed using Qt and C++.
 * It performs basic arithmetic operations including addition, subtraction,
 * multiplication, and division.
 *
 * The project demonstrates:
 * - Qt signal-slot mechanism
 * - Dynamic button connections
 * - Event-driven programming
 * - GUI design using Qt Designer
 * - Basic state management using flags
 *
 *
 * @section features Features
 *
 * - Digit input (0–9)
 * - Addition (+)
 * - Subtraction (-)
 * - Multiplication (*)
 * - Division (/)
 * - Equals (=) calculation
 * - Change sign (+/-)
 * - Clean numeric formatting (no unnecessary trailing zeros)
 *
 *
 * @section how_it_works How It Works
 *
 * The calculator operates in 3 stages:
 *
 * 1. User enters the first operand.
 * 2. User selects a mathematical operator.
 *      → The value is stored in `calcval`.
 *      → A corresponding trigger flag is activated.
 * 3. User enters second operand and presses "=".
 *      → Based on the active trigger, the correct operation is performed.
 *
 * Global state variables:
 *
 * - calcval        → Stores first operand
 * - addTrigger     → Addition selected
 * - subTrigger     → Subtraction selected
 * - multTrigger    → Multiplication selected
 * - divTrigger     → Division selected
 *
 *
 * @section project_structure Project Structure
 *
 * Calculator (QMainWindow)
 * --- NumPressed()         → Handles digit button input
 * --- MathButtonPressed()  → Stores first operand & selects operation
 * --- EqualButtonPressed() → Executes calculation
 * --- ChangeNumberSign()   → Toggles number sign
 *
 *
 * @section technologies Technologies Used
 *
 * - C++
 * - Qt Framework
 * - Qt Designer
 * - Signal & Slot mechanism
 * - QRegExp (input validation)
 *
 *
 * @section how_to_build How to Build
 *
 * 1. Install Qt (Qt Creator recommended)
 * 2. Clone the repository:
 *      git clone <your-repo-url>
 * 3. Open the .pro or CMakeLists.txt file in Qt Creator
 * 4. Build and Run
 *
 *
 * @section learning_outcome Learning Outcome
 *
 * This project helped strengthen understanding of:
 * - Event-driven architecture in Qt
 * - Connecting multiple buttons dynamically
 * - Managing application state using flags
 * - Handling user input validation
 * - Structuring clean GUI applications
 */

## Output:-

https://github.com/user-attachments/assets/7ba5e106-9672-406c-9eaa-50a3770ce114

