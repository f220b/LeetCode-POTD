// scripts/update-readme.js
// Fetches public stats for a LeetCode user via LeetCode's GraphQL API
// and writes them into README.md between the STATS markers as a plain
// markdown table (no external images/badges).

const fs = require("fs");
const path = require("path");

const USERNAME = process.env.LEETCODE_USERNAME || "f220b";
const README_PATH = path.join(__dirname, "..", "README.md");
const START_MARKER = "<!--STATS:START-->";
const END_MARKER = "<!--STATS:END-->";

const QUERY = `
query userProfile($username: String!) {
  matchedUser(username: $username) {
    username
    profile {
      ranking
    }
    submitStatsGlobal {
      acSubmissionNum {
        difficulty
        count
      }
    }
  }
  userContestRanking(username: $username) {
    attendedContestsCount
    rating
    globalRanking
    topPercentage
  }
}
`;

async function fetchStats(username) {
  const res = await fetch("https://leetcode.com/graphql", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Referer: `https://leetcode.com/u/${username}/`,
    },
    body: JSON.stringify({
      query: QUERY,
      variables: { username },
    }),
  });

  if (!res.ok) {
    throw new Error(`LeetCode API request failed: ${res.status}`);
  }

  const json = await res.json();
  if (json.errors) {
    throw new Error(`LeetCode API returned errors: ${JSON.stringify(json.errors)}`);
  }
  return json.data;
}

function pickCount(acSubmissionNum, difficulty) {
  const entry = acSubmissionNum.find((e) => e.difficulty === difficulty);
  return entry ? entry.count : 0;
}

function buildTable(data, username) {
  const user = data.matchedUser;
  const contest = data.userContestRanking;

  const acNums = user.submitStatsGlobal.acSubmissionNum;
  const total = pickCount(acNums, "All");
  const easy = pickCount(acNums, "Easy");
  const medium = pickCount(acNums, "Medium");
  const hard = pickCount(acNums, "Hard");
  const ranking = user.profile.ranking ? user.profile.ranking.toLocaleString() : "N/A";

  const contestRating = contest && contest.rating ? Math.round(contest.rating) : "Unrated";
  const contestsAttended = contest ? contest.attendedContestsCount : 0;
  const contestGlobalRank = contest && contest.globalRanking ? contest.globalRanking.toLocaleString() : "N/A";
  const topPercentage = contest && contest.topPercentage ? `Top ${contest.topPercentage.toFixed(2)}%` : "N/A";

  const updatedAt = new Date().toISOString().split("T")[0];

  return `
| Metric | Value |
|---|---|
| **Total Solved** | ${total} |
| 🟢 Easy | ${easy} |
| 🟡 Medium | ${medium} |
| 🔴 Hard | ${hard} |
| **Global Ranking** | ${ranking} |
| **Contest Rating** | ${contestRating} |
| **Contests Attended** | ${contestsAttended} |
| **Contest Global Rank** | ${contestGlobalRank} |
| **Contest Top %** | ${topPercentage} |

*Last updated: ${updatedAt} · Source: [leetcode.com/u/${username}](https://leetcode.com/u/${username}/)*
`;
}

async function main() {
  const data = await fetchStats(USERNAME);
  const table = buildTable(data, USERNAME);

  const readme = fs.readFileSync(README_PATH, "utf8");
  const startIdx = readme.indexOf(START_MARKER);
  const endIdx = readme.indexOf(END_MARKER);

  if (startIdx === -1 || endIdx === -1) {
    throw new Error("Could not find STATS markers in README.md");
  }

  const before = readme.slice(0, startIdx + START_MARKER.length);
  const after = readme.slice(endIdx);

  const updated = `${before}\n${table}\n${after}`;
  fs.writeFileSync(README_PATH, updated, "utf8");
  console.log("README.md stats section updated successfully.");
}

main().catch((err) => {
  console.error(err);
  process.exit(1);
});
