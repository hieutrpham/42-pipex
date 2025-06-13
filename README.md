# 42-pipex
Building a pipeline in C

# TODO:
- handle errno for when no command. why doesn't it print the correct message?
- if infile invalid
    - print {file_name}: no such file. exit 0. no other prints
    - still create outfile
- if cmds invalid
    - only the last child error gets printed

