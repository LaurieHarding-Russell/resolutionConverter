
load("@rules_python//python:defs.bzl", "py_binary")
load("@my_deps//:requirements.bzl", "requirement")

py_binary(
  name = "converter",
  srcs = ["converter.py"],
    deps = [
        requirement("python-resize-image"),
        requirement("Pillow"),
    ],
    data = glob(["from/*", "to/*"])
)