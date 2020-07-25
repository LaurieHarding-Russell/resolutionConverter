cc_binary(
    name = "converter",
    srcs = [
        "ConvertInterface.cpp"
    ],
    deps = [
        "@boost//:gil",
        "@boost//:filesystem",
        "@boost//:algorithm",
        "@boost//:asio",
        "@boost//:bind",
        "@boost//:thread",    
    ],
    linkopts = [
        "-lpng", 
        "-ljpeg",
        "-lpthread"
    ],
    visibility = ["//visibility:public"]
)