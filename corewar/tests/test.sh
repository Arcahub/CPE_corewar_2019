##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## test
##

MY_BINARY="../corewar"
REF_BINARY="./corewar"

MY_OUTPUT="my"
REF_OUTPUT="ref"

TESTS_FILE="tests"
CHAMPS_SRCDIR="champs"
LOG_DIR="logs"

EXIT_STATUS=0

RED="\e[31m"
GREEN="\e[32m"

do_test()
{
    local id=$1
    local champs=`cat $TESTS_FILE | grep -A1000 "\[$id\]" | grep -B1000 "^\[$id-END]" | grep -v "^\[.*\]" | grep -v "DUMP=" | sed "s/.*/$CHAMPS_SRCDIR\/&\.cor/" | tr '\n' ' ' | sed '$s/ $//'`
    local dump=`cat $TESTS_FILE | grep -A1000 "\[$id\]" | grep -B1000 "^\[$id-END]" | grep -v "^\[.*\]" | grep "DUMP=" | sed s/DUMP=//g`
    local my_exit=0
    local ref_exit=0

    if [ $dump != "" ]
    then
        dump="-dump $dump"
    fi
    ./$MY_BINARY $champs $dump > $MY_OUTPUT 2>/dev/null
    my_exit=$?
    ./$REF_BINARY $champs $dump > $REF_OUTPUT
    ref_exit=$?
    if [ $my_exit != $ref_exit ]
    then
        echo -e "$RED KO: exit code diff (my: $exit_code_my != ref: $exit_code_ref)\e[0m"
        EXIT_STATUS = 1
    fi
    diff $MY_OUTPUT $REF_OUTPUT
    if [ $? != 0 ]
    then
        mkdir -p $LOG_DIR/$id
        cp $MY_OUTPUT $LOG_DIR/$id/$MY_OUTPUT
        cp $REF_OUTPUT $LOG_DIR/$id/$REF_OUTPUT
        echo -e "$RED KO: files differ\e[0m"
        EXIT_STATUS=1
    else
        echo -e "$GREEN OK: Test passed\e[0m"
    fi
    rm my
    rm ref
}

cd $(dirname "$0")

if [ ! -f $TESTS_FILE ]
then
    echo "No tests file"
    exit 1
fi

if [ ! -d $CHAMPS_SRCDIR ]
then
    echo "No champs dir"
    exit 1
fi

if [ ! -f $REF_BINARY ]
then
    echo "No $REF_BINARY"
    exit 1
fi

if [ ! -f $MY_BINARY ]
then
    echo "Didn't find your binary"
    exit 84
fi

for lst in `cat $TESTS_FILE | grep "^\[.*\]$" | grep -vi end | sed s/'\['// | sed s/'\]'//`
do
    do_test $lst
done
exit $EXIT_STATUS
