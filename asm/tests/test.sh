##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## test
##

CHAMP_SRC_DIR='./champs'

REF_BINARY='asm'
MY_ASM_PATH="../asm"
MY_BINARY='my_asm'
REF_OUTPUT="$ref"
MY_OUTPUT="$my"

EXIT_STATUS=0

RED="\e[31m"
GREEN="\e[32m"

do_test() {
    local filepath=$1
    local exit_code_ref=0
    local exit_code_my=0

    echo -n "TESTING WITH: "
    echo $filepath
    ./$REF_BINARY $filepath 2>/dev/null
    exit_code_ref=`echo $?`
    if [ -f $filepath ]
    then
        mv `echo -n $filepath | sed 's/\.s/.cor/g' | awk -F'/' '{print $3}'` ref 2>/dev/null
    fi
    ./$MY_BINARY $filepath 2>/dev/null
    exit_code_my=`echo $?`
    if [ -f $filepath ]
    then
        mv `echo $filepath | sed 's/\.s/.cor/g'` my 2>/dev/null
    fi

    if [ $exit_code_ref != $exit_code_my ]
    then
        echo -e "$RED KO: exit code diff (my: $exit_code_my != ref: $exit_code_ref)"
        EXIT_STATUS=1
    fi
    if [ $exit_code_ref = 84 ] && [ $exit_code_my = 84 ]
    then
        echo -e "$GREEN OK: Test passed"
        echo -ne "\e[0m"
        return 0
    fi
    diff my ref
    if [ $? != 0 ]
    then
        echo -e "$RED KO: files differ"
        EXIT_STATUS=1
    else
        echo -e "$GREEN OK: Test passed"
    fi
    echo -ne "\e[0m"
    rm -f ref
    rm -f my
}

run() {
    for filename in $CHAMP_SRC_DIR/*.s; do
        do_test $filename
    done
}

cd $(dirname "$0")

if [ ! -d $CHAMP_SRC_DIR ]
then
  echo "No champs dir." >&2
  exit 1
fi

if [ ! -f $MY_ASM_PATH ]
then
  echo "$MY_ASM_PATH not found" >&2
  exit 1
fi

cp $MY_ASM_PATH $MY_BINARY
run
rm $MY_BINARY
exit $EXIT_STATUS
