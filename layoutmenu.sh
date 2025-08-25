#!/bin/sh

cat <<EOF | xmenu
"[]="   tile    0
"><>"   NULL    1
"[M]"   monocle 2
"[@]"   spiral  3
"[\\]"  dwindle 4
"H[]"   deck    5
"TTT"   bstack  6
"==="   bstackhoriz 7
"HHH"   grid    8
"###"   nrowgrid    9
"---"   horizgrid   10
":::"   gaplessgrid 11
"|M|"   centeredmaster  12 
">M>"   centeredfloatingmaster  13

EOF
