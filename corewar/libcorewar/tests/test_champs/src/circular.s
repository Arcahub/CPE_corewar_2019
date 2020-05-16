.name "Circular memory"
.comment "Tests the circular memory"

xor r2,r2,r2
zjmp %:main

main:
	ld %97,r3
	ld %589824,r4
    st r4,-26
	ld %1064963,r4
    st r4,-42
    xor r2,r2,r2
    zjmp %-52
