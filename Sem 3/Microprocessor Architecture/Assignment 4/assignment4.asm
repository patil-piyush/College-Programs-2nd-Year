;Assignment No.:4
;Tile: Using accept procedure convert hexadecimal number to BCD

section .data
    nline       db 10, 10
    nline_len   equ $-nline

    ano         db 10, "       Assignment No.: 4 ", 10
                db "Hex to BCD conversion", 10
    ano_len     equ $-ano

    hmsg        db "Enter a 4-digit Hex number: ", 0
    hmsg_len    equ $-hmsg

    emsg        db "Invalid input. Please enter a valid hex number.", 0
    emsg_len    equ $-emsg

section .bss
buf resb 6        ; buffer for hex input
char_ans resb 4   ; buffer for individual BCD digits

%macro Print 2
    mov rax, 1          
    mov rdi, 1          
    mov rsi, %1        
    mov rdx, %2        
    syscall
%endmacro

%macro Read 2
    mov rax, 0        
    mov rdi, 0        
    mov rsi, %1        
    mov rdx, %2        
    syscall
%endmacro

%macro Exit 0
    mov rax, 60
    mov rdi, 0
    syscall
%endmacro

section .text
    global _start

_start:
    Print ano, ano_len
    Print hmsg, hmsg_len

    call Accept_16    ; Get hex input
    call HEX_BCD      ; Convert to BCD and print

    Exit

;-------------------------------------------------------------
HEX_BCD:                     ; Procedure to convert hex to BCD
    mov ax, bx                ; bx contains the hex number
    mov bx, 10                ; Divide by 10 to get BCD digits
    xor bp, bp                ; Clear bp (used as a counter)

back:
    xor dx, dx                ; Clear dx (for remainder)
    div bx                    ; Divide ax by 10 (ax = quotient, dx = remainder)
    push dx                   ; Push remainder (BCD digit) onto the stack
    inc bp                    ; Increment counter for number of digits
    cmp ax, 0                 ; Check if quotient is 0
    jne back                  ; If not, repeat

back1:
    pop dx                    ; Pop last digit
    add dl, 30h               ; Convert to ASCII
    mov [char_ans], dl        ; Store result
    Print char_ans, 1         ; Print individual digit

    dec bp                    ; Decrement counter
    jnz back1                 ; If counter is not zero, continue popping

    ret

;--------------------------------------------------------------
Accept_16:                    ; ASCII (character) to hex number input
    Read buf, 5               ; Read 4 hex digits and enter key
    mov rcx, 4                ; Set counter for 4 hex digits
    mov rsi, buf              ; Set pointer to buffer
    xor bx, bx                ; Clear bx (for storing hex value)

next_byte:
    shl bx, 4                 ; Shift left by 4 (make room for new digit)
    mov al, [rsi]             ; Get next character

    cmp al, '0'               ; Check if digit is between '0' and '9'
    jb error
    cmp al, '9'
    jbe sub30                 ; If between '0' and '9', subtract 30h

    cmp al, 'A'               ; Check if digit is between 'A' and 'F'
    jb error
    cmp al, 'F'
    jbe sub37                 ; If between 'A' and 'F', subtract 37h

    cmp al, 'a'               ; Check if digit is between 'a' and 'f'
    jb error
    cmp al, 'f'
    jbe sub57                 ; If between 'a' and 'f', subtract 57h

error:
    Print emsg, emsg_len       ; Print error message and exit if invalid input
    Exit

sub57:
    sub al, 20h                ; Convert lower-case hex digit to number
    jmp valid_input            ; Jump to valid input processing

sub37:
    sub al,07h                 ; Convert upper-case hex digit to number
    jmp valid_input            ; Jump to valid input processing

sub30:
    sub al, 30h                ; Convert '0'-'9' to number

valid_input:
    add bx, ax                 ; Add converted digit to bx
    inc rsi                    ; Move to next digit
    dec rcx                    ; Decrement counter
    jnz next_byte              ; Repeat for all digits

    ret
