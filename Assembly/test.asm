section	.data
    result times 9 DB 0

section	.text
    global _start
	
_start:
    mov ecx, 9
    mov esi, result

exit:
    mov eax, 1
    int 0x80
