
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "rules_python",
    remote = "https://github.com/bazelbuild/rules_python.git",
    commit = "38f86fb55b698c51e8510c807489c9f4e047480e",
)


load("@rules_python//python:repositories.bzl", "py_repositories")
py_repositories()
load("@rules_python//python:pip.bzl", "pip_repositories", "pip3_import")

pip_repositories()

# This rule translates the specified requirements.txt into
# @my_deps//:requirements.bzl, which itself exposes a pip_install method.
pip3_import(
   name = "my_deps",
   requirements = "//:requirments.txt",
)

load("@my_deps//:requirements.bzl", "pip_install")
pip_install()

