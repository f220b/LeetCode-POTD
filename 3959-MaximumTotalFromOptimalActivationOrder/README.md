# 3645. Maximum Total from Optimal Activation Order

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/maximum-total-from-optimal-activation-order/)

---

You are given two integer arrays `value` and `limit`, both of length `n`.

Initially, all elements are **inactive**. You may activate them in any order.

- To activate an inactive element at index `i`, the number of **currently** active elements must be **strictly less** than `limit[i]`.
- When you activate the element at index `i`, it adds `value[i]` to the **total** activation value (i.e., the sum of `value[i]` for all elements that have undergone activation operations).
- After each activation, if the number of **currently** active elements becomes `x`, then **all** elements `j` with `limit[j] <= x` become **permanently** inactive, even if they are already active.

Return the **maximum** **total** you can obtain by choosing the activation order optimally.

**Example 1:**

**Input:** value = [3,5,8], limit = [2,1,3]

**Output:** 16

**Explanation:**

One optimal activation order is:

<table>
	<thead>
		<tr>
			<th align="center" style="border: 1px solid black;">Step</th>
			<th align="center" style="border: 1px solid black;">Activated <code>i</code></th>
			<th align="center" style="border: 1px solid black;"><code>value[i]</code></th>
			<th align="center" style="border: 1px solid black;">Active Before <code>i</code></th>
			<th align="center" style="border: 1px solid black;">Active After <code>i</code></th>
			<th align="center" style="border: 1px solid black;">Becomes Inactive <code>j</code></th>
			<th align="center" style="border: 1px solid black;">Inactive Elements</th>
			<th align="center" style="border: 1px solid black;">Total</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">5</td>
			<td align="center" style="border: 1px solid black;">0</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;"><code>j = 1</code> as <code>limit[1] = 1</code></td>
			<td align="center" style="border: 1px solid black;">[1]</td>
			<td align="center" style="border: 1px solid black;">5</td>
		</tr>
		<tr>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">0</td>
			<td align="center" style="border: 1px solid black;">3</td>
			<td align="center" style="border: 1px solid black;">0</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">-</td>
			<td align="center" style="border: 1px solid black;">[1]</td>
			<td align="center" style="border: 1px solid black;">8</td>
		</tr>
		<tr>
			<td align="center" style="border: 1px solid black;">3</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">8</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;"><code>j = 0</code> as <code>limit[0] = 2</code></td>
			<td align="center" style="border: 1px solid black;">[0, 1]</td>
			<td align="center" style="border: 1px solid black;">16</td>
		</tr>
	</tbody>
</table>

Thus, the maximum possible total is 16.

**Example 2:**

**Input:** value = [4,2,6], limit = [1,1,1]

**Output:** 6

**Explanation:**

One optimal activation order is:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th align="center" style="border: 1px solid black;">Step</th>
			<th align="center" style="border: 1px solid black;">Activated <code>i</code></th>
			<th align="center" style="border: 1px solid black;"><code>value[i]</code></th>
			<th align="center" style="border: 1px solid black;">Active Before <code>i</code></th>
			<th align="center" style="border: 1px solid black;">Active After <code>i</code></th>
			<th align="center" style="border: 1px solid black;">Becomes Inactive <code>j</code></th>
			<th align="center" style="border: 1px solid black;">Inactive Elements</th>
			<th align="center" style="border: 1px solid black;">Total</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">6</td>
			<td align="center" style="border: 1px solid black;">0</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;"><code>j = 0, 1, 2</code> as <code>limit[j] = 1</code></td>
			<td align="center" style="border: 1px solid black;">[0, 1, 2]</td>
			<td align="center" style="border: 1px solid black;">6</td>
		</tr>
	</tbody>
</table>

Thus, the maximum possible total is 6.

**Example 3:**

**Input:** value = [4,1,5,2], limit = [3,3,2,3]

**Output:** 12

**Explanation:**

One optimal activation order is:​​​​​​​**​​​​​​​**

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th align="center" style="border: 1px solid black;">Step</th>
			<th align="center" style="border: 1px solid black;">Activated <code>i</code></th>
			<th align="center" style="border: 1px solid black;"><code>value[i]</code></th>
			<th align="center" style="border: 1px solid black;">Active Before <code>i</code></th>
			<th align="center" style="border: 1px solid black;">Active After <code>i</code></th>
			<th align="center" style="border: 1px solid black;">Becomes Inactive <code>j</code></th>
			<th align="center" style="border: 1px solid black;">Inactive Elements</th>
			<th align="center" style="border: 1px solid black;">Total</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">5</td>
			<td align="center" style="border: 1px solid black;">0</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">-</td>
			<td align="center" style="border: 1px solid black;">[ ]</td>
			<td align="center" style="border: 1px solid black;">5</td>
		</tr>
		<tr>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">0</td>
			<td align="center" style="border: 1px solid black;">4</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;"><code>j = 2</code> as <code>limit[2] = 2</code></td>
			<td align="center" style="border: 1px solid black;">[2]</td>
			<td align="center" style="border: 1px solid black;">9</td>
		</tr>
		<tr>
			<td align="center" style="border: 1px solid black;">3</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">1</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">-</td>
			<td align="center" style="border: 1px solid black;">[2]</td>
			<td align="center" style="border: 1px solid black;">10</td>
		</tr>
		<tr>
			<td align="center" style="border: 1px solid black;">4</td>
			<td align="center" style="border: 1px solid black;">3</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">2</td>
			<td align="center" style="border: 1px solid black;">3</td>
			<td align="center" style="border: 1px solid black;"><code>j = 0, 1, 3</code> as <code>limit[j] = 3</code></td>
			<td align="center" style="border: 1px solid black;">[0, 1, 2, 3]</td>
			<td align="center" style="border: 1px solid black;">12</td>
		</tr>
	</tbody>
</table>

Thus, the maximum possible total is 12.

**Constraints:**

- `1 <= n == value.length == limit.length <= 10^5`
- `1 <= value[i] <= 10^5`​​​​​​​
- `1 <= limit[i] <= n`
