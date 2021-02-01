#!/bin/bash

# 1.First create new session in tmux:
tmux new-session -d -s mySession 

# 1.1 send command to tmux with "tmux send-keys..."
# 1.2 note: C-m acts like enter key
tmux send-keys 'ls -a' 'C-m'

# 2.Then select it:
tmux select-window -t mySession:0

# 3.Split tmux window horizontally
tmux split-window -h 

tmux send-keys 'docker images' 'C-m' 

# 4. Split tmux first window vertically into 2 window, and access it with "-v -t 0" and "-v -t 1"
tmux split-window -v -t 0

tmux send-keys 'echo Hi' 'C-m'

tmux split-window -v -t 1 

# 5. Connect to the created tmux session
tmux -2 attach-session -t mySession

