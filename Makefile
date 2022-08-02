
.PHONY: all
all: caffeene

caffeene: main.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: install
install:
	install -m 755 caffeene /usr/local/bin

.PHONY: clean
clean:
	rm -f caffeene
