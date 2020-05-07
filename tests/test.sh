##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## test
##

CHAMP_SRC_DIR='./champs'
CWD='tests'

REF_BINARY='asm'
MY_ASM_PATH="../asm/asm"
MY_BINARY='my_asm'
REF_OUTPUT="$ref"
MY_OUTPUT="$my"

RED="\e[31m"
GREEN="\e[32m"

## BINARY_OUTPUT_PATH = $(sed 's/.s/.cor/g' $filepath)

do_test() {
    local filepath=$1
    local exit_code_ref=0
    local exit_code_my=0

    echo -n "TESTING WITH: "
    echo $filepath
    ./$REF_BINARY $filepath
    exit_code_ref=`echo $?`
    mv `echo -n $filepath | sed 's/\.s/.cor/g' | awk -F'/' '{print $3}'` ref
    ./$MY_BINARY $filepath
    exit_code_my=`echo $?`
    mv `echo $filepath | sed 's/\.s/.cor/g'` my

    if [ $exit_code_ref != $exit_code_my ]
    then
        echo -e "$RED KO: exit code diff (my: $exit_code_my != ref: $exit_code_ref)"
    fi
    diff my ref
    if [ $? != 0 ]
    then
        echo -e "$RED KO: files differ"
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

cd $CWD

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
rm MY_BINARY
