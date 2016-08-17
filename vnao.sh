###
# Copyright (C) 2016 Nicolas A. Ortega
# License: GNU GPLv3
###
#!/bin/bash
astyle --style=attach \
    --indent=spaces=4 \
    --indent-switches \
    --indent-labels \
    --indent-preproc-define \
    --indent-col1-comments \
    --pad-oper \
    --unpad-paren \
    --align-pointer=name \
    --add-brackets \
    --break-after-logical \
    --lineend=linux \
    src/mw/*.cpp \
    examples/01.ChatRoom/src/*.cpp \
    include/*.h 

rm -rf src/*.orig include/*.orig examples/01.ChatRoom/src/*.orig

echo "I CAN'T READ THAT CODE!!!"
