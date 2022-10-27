section .bss
        char resb 1

section .text
        global _start
	
_start:
        mov ecx, 9

    L2:
        mov al, 10
        sub al, cl
        mov bl, 1
        push ecx
        mov ecx, 9

    L1:
        push eax
        mul bl
        call printIntByte
        mov al, 32
        call print
        pop eax
        inc bl
        loop L1

        call newLine
        pop ecx
        loop L2


exit:
    mov eax, 1
    int 0x80

print:
    push eax
    push ebx
    push ecx
    push edx

    mov ecx, char
    mov byte [ecx], al
    mov edx, 1
    mov ebx, 1
    mov eax, 4
    int 0x80

    pop edx
    pop ecx
    pop ebx
    pop eax
    ret

printIntByte:
    push eax
    push ebx
    push ecx

    mov ecx, 2
    mov bl, 0x10
    div bl
    add ah, 48
    add al, 48

    printIntByteL3:
    cmp al, 58
    jc printIntByteL2
    jmp printIntByteL1

    printIntByteL1:
    add al, 7

    printIntByteL2:
    call print
    mov al, ah
    loop printIntByteL3

    pop ecx
    pop ebx
    pop eax
    ret

newLine:
    push eax

    mov al, 10
    call print

    pop eax
    ret