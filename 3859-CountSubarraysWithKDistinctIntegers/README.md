# 3859. Count Subarrays With K Distinct Integers

**Difficulty:** Hard  
[View on LeetCode](https://leetcode.com/problems/count-subarrays-with-k-distinct-integers/)

---

You are given an integer array `nums` and two integers `k` and `m`.

Return an integer denoting the count of **subarrays** of `nums` such that:

- The subarray contains **exactly** `k` **distinct** integers.
- Within the subarray, each **distinct** integer appears **at least** `m` times.

**Example 1:**

**Input:** nums = [1,2,1,2,2], k = 2, m = 2

**Output:** 2

**Explanation:**

The possible subarrays with `k = 2` distinct integers, each appearing at least `m = 2` times are:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Subarray</th>
			<th style="border: 1px solid black;">Distinct<br />
			numbers</th>
			<th style="border: 1px solid black;">Frequency</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">[1, 2, 1, 2]</td>
			<td style="border: 1px solid black;">{1, 2} &rarr; 2</td>
			<td style="border: 1px solid black;">{1: 2, 2: 2}</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">[1, 2, 1, 2, 2]</td>
			<td style="border: 1px solid black;">{1, 2} &rarr; 2</td>
			<td style="border: 1px solid black;">{1: 2, 2: 3}</td>
		</tr>
	</tbody>
</table>

Thus, the answer is 2.

**Example 2:**

**Input:** nums = [3,1,2,4], k = 2, m = 1

**Output:** 3

**Explanation:**

The possible subarrays with `k = 2` distinct integers, each appearing at least `m = 1` times are:

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">Subarray</th>
			<th style="border: 1px solid black;">Distinct<br />
			numbers</th>
			<th style="border: 1px solid black;">Frequency</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">[3, 1]</td>
			<td style="border: 1px solid black;">{3, 1} &rarr; 2</td>
			<td style="border: 1px solid black;">{3: 1, 1: 1}</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">[1, 2]</td>
			<td style="border: 1px solid black;">{1, 2} &rarr; 2</td>
			<td style="border: 1px solid black;">{1: 1, 2: 1}</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">[2, 4]</td>
			<td style="border: 1px solid black;">{2, 4} &rarr; 2</td>
			<td style="border: 1px solid black;">{2: 1, 4: 1}</td>
		</tr>
	</tbody>
</table>

Thus, the answer is 3.

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `1 <= k, m <= nums.length`
