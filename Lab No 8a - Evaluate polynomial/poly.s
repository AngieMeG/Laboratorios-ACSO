.text
.global _start
_start: MOV R1, #2		@ Registro de x
	MOV R2, #3		@ Registro de a
	MOV R3, #4		@ Registro de b
	MOV R4, #5		@ Registro de c
	MLA R5, R1, R2, R3      @ Calcula ax + b 
	MLA R6, R1, R5, R4      @ Calcula x(ax + b) + c
	MOV R7, #1		
	SVC 0
.end