cc_test(name = "mptcp_server.exe",
        srcs = [
                 "mptcp_server.cpp",
                 "main.cpp",
               ],
       cppflags = [
                   "-Imedia_server_library",
                   "-Imedia_server_protocol"
                  ],
       ldflags = [
                 ],
       deps = [
               "//media_server_library/base/BUILD:base",
               "//media_server_library/network/BUILD:network",
               "//media_server_library/logging/BUILD:logging",
              ]
       )
