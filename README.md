# LeetCode-POTD 🧩

A curated collection of my daily solutions to LeetCode's **Problem of the Day (POTD)**. Focused on optimized algorithms, clean implementations, and consistent daily coding practice.

[![LeetCode Profile](https://img.shields.io/badge/LeetCode-f220b-orange?style=flat&logo=leetcode&logoColor=white)](https://leetcode.com/u/f220b/)
[![GitHub last commit](https://img.shields.io/github/last-commit/f220b/LeetCode-POTD)](https://github.com/f220b/LeetCode-POTD/commits/main)
[![GitHub repo size](https://img.shields.io/github/repo-size/f220b/LeetCode-POTD)](https://github.com/f220b/LeetCode-POTD)

---

## 📊 LeetCode Stats

These cards pull data live from my LeetCode profile ([f220b](https://leetcode.com/u/f220b/)) every time this page loads — problems solved, ranking, and contest info stay up to date automatically.

<p align="center">
  <img src="https://leetcode-stats-card.vercel.app/api?username=f220b&theme=dark&border_radius=10" alt="f220b's LeetCode Stats" />
</p>

<p align="center">
  <img src="https://leetcard.jacoblin.cool/f220b?theme=dark&font=Karma&ext=activity" alt="f220b's LeetCode Activity" />
</p>

> **Note:** These are third-party badge services that query the public LeetCode GraphQL API on each page view. If a card fails to load, LeetCode may have rate-limited the service — refresh after a bit, or see [Auto-updating stats](#-auto-updating-stats-optional) below for a self-hosted alternative that's more reliable.

For full details (contest rating, ranking history, badges), visit my live profile: **[leetcode.com/u/f220b](https://leetcode.com/u/f220b/)**

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

## 🚀 Auto-updating stats (optional)

If you'd like these numbers to be committed into the README itself (rather than fetched live via an image), you can add a small GitHub Actions workflow that:

1. Queries the LeetCode GraphQL API (`https://leetcode.com/graphql`) for your public stats.
2. Writes the results between `<!--STATS:START-->` / `<!--STATS:END-->` markers in this file.
3. Commits the updated README on a schedule (e.g., daily via `cron`).

Popular ready-made actions for this: `JacobLinCool/leetcode-stats-card` (badge-based, used above) or writing a small script with `actions/github-script` + a GraphQL query against LeetCode's public API. Let me know if you'd like this workflow scaffolded out — I can generate the `.yml` and the fetch script.

<!--STATS:START-->
<!--STATS:END-->

## 📌 About

This repo is my personal log of daily LeetCode POTD submissions — a way to stay consistent, sharpen problem-solving skills, and track progress over time.

⭐ Feel free to explore, and reach out if you spot a more optimal approach to any solution!
