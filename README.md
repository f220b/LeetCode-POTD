# LeetCode-POTD 🧩

A curated collection of my daily solutions to LeetCode's **Problem of the Day (POTD)**. Focused on optimized algorithms, clean implementations, and consistent daily coding practice.

[![LeetCode Profile](https://img.shields.io/badge/LeetCode-f220b-orange?style=flat&logo=leetcode&logoColor=white)](https://leetcode.com/u/f220b/)
[![GitHub last commit](https://img.shields.io/github/last-commit/f220b/LeetCode-POTD)](https://github.com/f220b/LeetCode-POTD/commits/main)
[![GitHub repo size](https://img.shields.io/github/repo-size/f220b/LeetCode-POTD)](https://github.com/f220b/LeetCode-POTD)

---

## 📊 LeetCode Stats

<!--STATS:START-->
| Metric | Value |
|---|---|
| **Total Solved** | — |
| 🟢 Easy | — |
| 🟡 Medium | — |
| 🔴 Hard | — |
| **Global Ranking** | — |
| **Contest Rating** | — |
| **Contests Attended** | — |
| **Contest Global Rank** | — |
| **Contest Top %** | — |

*Stats populate automatically once the update workflow runs. Source: [leetcode.com/u/f220b](https://leetcode.com/u/f220b/)*
<!--STATS:END-->

This table is kept current by a GitHub Actions workflow that queries LeetCode's own GraphQL API and rewrites the numbers above — no third-party badge images, just plain data pulled straight from my profile.

---

## 🛠️ Tech Stack

- **Languages:** C++ (primary), Python, Java
- **Platform:** [LeetCode](https://leetcode.com/problemset/all/)
- **Paradigms:** Greedy, Dynamic Programming, Graphs, Binary Search, Trees, and more

## 📝 Approach

Each solution is written with a focus on:

1. **Time Complexity** — aiming for the most optimal theoretical bound.
2. **Space Complexity** — minimizing memory footprint.
3. **Readability** — clean, idiomatic code with sensible naming and structure.

## 📁 Repo Structure

Each problem lives in its own folder, named `<problem-number>-<ProblemNameInPascalCase>`, e.g.:

```
LeetCode-POTD/
├── 1-TwoSum/
├── 121-BestTimeToBuyAndSellStock/
├── 1250-LongestCommonSubsequence/
└── ...
```

Every folder contains the solution file(s) for that problem, solved as part of the daily challenge.

## ⚙️ How the auto-updating stats work

1. `scripts/update-readme.js` sends a GraphQL query to `https://leetcode.com/graphql` asking for:
   - Total / Easy / Medium / Hard problems solved
   - Global profile ranking
   - Contest rating, contests attended, contest global rank, and top percentile
2. `.github/workflows/update-stats.yml` runs that script once a day (and on every push to `main`, and on-demand via "Run workflow").
3. The script rewrites everything between the `<!--STATS:START-->` and `<!--STATS:END-->` markers in this file and commits the change automatically.

**Setup:** just add the two files (`scripts/update-readme.js` and `.github/workflows/update-stats.yml`) to this repo — no API key or secret is needed since LeetCode's profile/contest data is public. If your LeetCode username changes, update `LEETCODE_USERNAME` in the workflow file.

## 📌 About

This repo is my personal log of daily LeetCode POTD submissions — a way to stay consistent, sharpen problem-solving skills, and track progress over time.

⭐ Feel free to explore, and reach out if you spot a more optimal approach to any solution!
