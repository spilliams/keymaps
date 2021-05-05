STENO_ENABLE = no
NKRO_ENABLE = no
TMPVAR := $(SRC)
SRC = $(filter-out sten.c, $(TMPVAR))

CONSOLE_ENABLE = no
