load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_nelhage_rules_boost",
    urls = ["https://github.com/nelhage/rules_boost/archive/ccc90b00c2fae7267cc25b77199fb992acd5e799.zip"],
    strip_prefix = "rules_boost-ccc90b00c2fae7267cc25b77199fb992acd5e799",
    sha256 = "68c67476f8e6257cb858a2378a4663a54690ed64562db2c3be4702c537e1edd8"
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()