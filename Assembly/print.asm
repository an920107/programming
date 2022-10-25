section .bss
    char resb 1

section .text
    global _start
	
_start:
    mov edx, 1
    mov ecx, char
    mov byte [ecx], 48
    mov ebx, 1
    mov eax, 4
    int 0x80

exit:
    mov eax, 1
    int 0x80