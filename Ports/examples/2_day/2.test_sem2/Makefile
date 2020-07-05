UCOS_SRC=/root/rtos/uCOS-II/source
UCOS_PORT_SRC=/root/rtos/uCOS-II/Ports/src
UCOS_PORT_EX=$(shell pwd)

EXAMPLE=test

all:
	@gcc -D__LINUX__ -I$(UCOS_SRC) -I$(UCOS_PORT_SRC) -I$(UCOS_PORT_EX)  $(EXAMPLE).c $(UCOS_SRC)/uCOS_II.c $(UCOS_PORT_SRC)/pc.c $(UCOS_PORT_SRC)/os_cpu_c.c  -o $(EXAMPLE)

clean:
	@rm -f *.o
	@rm -f *.bak
	@rm -f *~	
