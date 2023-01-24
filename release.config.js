var publishCmd = `
./gradlew assemble --parallel || exit 1
git tag -a -f \${nextRelease.version} \${nextRelease.version} -F CHANGELOG.md || exit 2
git push --force origin \${nextRelease.version} || exit 3
`
var config = require('semantic-release-preconfigured-conventional-commits');
config.plugins.push(
    ["@semantic-release/exec", {
        "publishCmd": publishCmd,
    }],
    ["@semantic-release/github", {
        "assets": [
            { "path": "build/libs/*.jar" },
        ]
    }],
    ["@semantic-release/npm", {
      "npmPublish": false
    }],
    "@semantic-release/git",
)
module.exports = config