╔═══╦═══╦═══╗
║ 1 ║ 2 ║ 3 ║ 2 → a b c
║ ║abc║def║ 3 → d e f
╠═══╬═══╬═══╣
║ 4 ║ 5 ║ 6 ║ 4 → g h i
║ghi║jkl║mno║ 5 → j k l
╠═══╬═══╬═══╣
║ 7 ║ 8 ║ 9 ║ 6 → m n o
║pqrs║tuv║wxyz║ 7 → p q r s
╚═══╩═══╩═══╝ 8 → t u v
9 → w x y z

### 4) Letter Combinations of a Phone Number (simplified)

**Description.** Given digit string `digits` (2–9), return all letter combinations mapped by phone keypad.

**Signature (Python):** `def letterCombinations(digits: str) -> List[str]`

**Constraints:** `0 <= len(digits) <= 10` (cartesian product of letters)

**Example:**

Input: `digits = "23"`

Output: `["ad","ae","af","bd","be","bf","cd","ce","cf"]`

**Hint:** Map each digit to letters, then backtrack across positions building strings.
