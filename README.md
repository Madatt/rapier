# Rapier

An OS for Raspberry Pi Zero (And 2 in the future).

# Features:
+ Basic MMU support
+ VideoCore:
    + Read/write to mailboxes
    + Framebuffer init
    + Drawing to framebuffer
    + Basic font
+ ATAGs parse

# TODO:
+ Memory managment
    + Dividing memory into blocks
    + Block allocation/deallocation
    + Multiple MMU tables for different processes
+ Actual console for input/output
+ Threading
+ Some kind of filesystem support
