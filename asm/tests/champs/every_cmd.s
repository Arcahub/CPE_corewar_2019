.name "ALL"
.comment "just test all instruct"

l2:
sti r1,%:live,%1
and r1,%0,r1
live: live %1
zjmp %:live
fork %4
lfork %4
ld 4, r4
st r8, 8
add r2, r2, r2
sub r2, r2, r2
or %5, 5, r5
xor r1, r2, r3
ldi 4, %4, r4
lld %4, r9
lldi %7, r2, r7
aff r16
