.name    "Overrider"
.comment "Try to override an instruction while it's being executed"

xor r2,r2,r2
zjmp %:main

replacement:
    zjmp %36
    live %1

main:
    ld :replacement,r3
    fork %:child

parent:
    st r1,6
    live %1
    xor r2,r2,r2
    st r3,:child_jmp
    xor r2,r2,r2
    zjmp %0

child:
    st r1,6
    live %1
    xor r2,r2,r2
child_jmp:
    zjmp %:child_a
    live %1

child_a:
    ld %97,r4
    aff r4
    st r1,6
    live %1
    xor r2,r2,r2
    zjmp %:end

child_b:
    ld %98,r4
    aff r4
    st r1,6
    live %1
    xor r2,r2,r2
    zjmp %:end

end:
    xor r2,r2,r2
    zjmp %0
