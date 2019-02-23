.PHONY: all clean

CFLAGS := -Wall -Wextra -pedantic -std=c99 -g3 #-Wno-unused-parameter

ifdef DECIMAL_TEN
CFLAGS += -DDECIMAL_TEN
endif

all: sol spider freecell

#canfield:
sol: sol.c sol.h schemes.h
	$(CC) $(CFLAGS) -DKLONDIKE $< -o $@

spider: sol.c sol.h schemes.h
	$(CC) $(CFLAGS) -DSPIDER sol.c -o $@

freecell: sol.c sol.h schemes.h
	$(CC) $(CFLAGS) -DFREECELL sol.c -o $@

clean:
	rm -f sol spider freecell

.PHONY: getfuns test
getfuns: sol.c
	@grep -o '^\w.* \w.*(.*)[^/]*{\|^#if.*\|^#e[ln].*' $<|sed 's/ *{$$/;/' \
	| perl -0777 -pe 's{#if[^\n]*\n(#elif[^\n]*\n)?#endif[^\n]*\n}{}igs'

test:
	@grep -n --color=always 'TODO\|XXX' README.md sol.*
longtest: test
	sed 's/\t/        /g' sol.c|grep -n --color=always '^.\{81\}'|awk '{print "\033[35msol.c\033[36m:" $$0}'

.PHONY: frtest  # TODO: remove me
frtest:
	$(MAKE) test | grep FREECELL --color=always
