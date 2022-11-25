section .bss

section .text
        global _start
	
_start:
        push    ebp
        mov     ebp, esp
        sub     esp, 16
        mov     DWORD [ebp-4], edi
        mov     DWORD [ebp-16], esi
        mov     eax, DWORD [ebp-16]
        mov     eax, DWORD [eax]
        mov     edi, eax
        
        mov     eax, 0
        leave
        ret