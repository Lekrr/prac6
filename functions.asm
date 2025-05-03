section .text
global f1
global f1_der
global f2
global f2_der
global f3
global f3_der

; e^x + 2
f1:
    push ebp
    mov ebp, esp
    sub esp, 8

    mov eax, dword[ebp + 8]
    mov dword[esp], eax
    mov eax, dword[ebp + 12]
    mov dword[esp + 4], eax
    call f1_der

    fld1
    fld1
    fadd
    fadd

    leave
    ret

f1_der:
    push ebp
    mov ebp, esp

    finit
    fldl2e ; log_2 e
    fmul qword[ebp + 8] ; log_2 e^x
    fld st0 ; log_2 e^x : log_2 e^x
    fld1 ; 1 : log_2 e^x : log_2 e^x
    fxch ; log_2 e^x : 1 : log_2 e^x
    fprem ; {log_2 e^x} : 1 : log_2 e^x
    f2xm1 ; 2^{log_2 e^x} - 1 : 1 : log_2 e^x
    fadd ; 2^{log_2 e^x} : log_2 e^x
    fscale ; 2^({log_2 e^x} + [log_2 e^x]) = 2^(log_2 e^x) = e^x

    leave
    ret

f2:
    push ebp
    mov ebp, esp

    finit
    fld1 ; 1
    fchs ; -1
    fdiv qword[ebp + 8] ; -1/x

    leave
    ret

f2_der:
    push ebp
    mov ebp, esp

    finit
    fld1 ; 1
    fdiv qword[ebp + 8] ; 1 / x
    fdiv qword[ebp + 8] ; 1 / x^2

    leave
    ret

f3:
    push ebp
    mov ebp, esp

    finit
    fld qword[ebp + 8] ; x
    fld1 ; 1 : x
    fld1
    fld1
    fadd
    fadd
    fadd ; x + 1
    fmul qword[.consts]
    fdiv qword[.consts + 8]

    leave
    ret
.consts: dq -2., 3.

f3_der:
    push ebp
    mov ebp, esp

    finit
    fld qword[.consts]
    fdiv qword[.consts + 8]

    leave
    ret
.consts: dq -2., 3.