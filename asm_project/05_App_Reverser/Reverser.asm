.386
.model flat,c
.code

Reverser    proc
            push ebp
            mov ebp,esp
            push esi
            push edi


            xor eax,eax
            mov edi,[ebp+8]
            mov esi,[ebp+12]
            mov ecx,[ebp+16]
            test ecx,ecx

            lea esi,[esi+ecx*4-4]
            pushfd
            std


@@:            
            lodsd
            mov [edi],eax
            add edi,4
            dec ecx
            jnz @B
            ; @B     ; 向上转移到最近的@@处
            ; @F     ; 向下转移到最近的@@处

            popfd    ; 将栈顶弹入 EFLAGS
 
            mov eax,1

            pop edi
            pop esi
            pop ebp
            retn

Reverser    endp
end
