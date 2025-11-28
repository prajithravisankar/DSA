### 1) k-Combinations (choose k)

**Description.** Return all combinations of `k` numbers chosen from `1..n`. Order within a combination doesn't matter; combinations should be unique.

**Signature (Python):** `def combine(n: int, k: int) -> List[List[int]]`

**Constraints:** `1 <= k <= n <= 20` (answer size can be large)

**Example:**

Input: `n = 4, k = 2`

Output: `[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]`

**Hint:** Backtrack building the current combination; prune using remaining numbers to fill remaining slots.
