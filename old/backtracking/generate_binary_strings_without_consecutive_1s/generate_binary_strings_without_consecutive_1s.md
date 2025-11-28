### 5) Generate Binary Strings Without Consecutive 1s

**Description.** Generate all binary strings of length `n` that do not contain consecutive `1`s.

**Signature (Python):** `def generateNoConsecOnes(n: int) -> List[str]`

**Constraints:** `1 <= n <= 20` (output grows but is Fibonacci-like)

**Example:**

Input: `n = 3`

Output: `["000","001","010","100","101"]` (order doesn't matter)

**Hint:** Backtrack by appending `0` always, append `1` only if previous was `0`.
