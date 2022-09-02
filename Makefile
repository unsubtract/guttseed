CC = musl-gcc
CFLAGS = -pipe -Wall -Wextra --std=c99 -pedantic -D_FORTIFY_SOURCE=2
# LDFLAGS =

all: bftoguttseed guttseedtobf
guttseedtobf: guttseedtobf.o guttseed.o hexmsm_rng.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ guttseedtobf.o guttseed.o hexmsm_rng.o

bftoguttseed: bftoguttseed.o guttseed.o hexmsm_rng.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ bftoguttseed.o guttseed.o hexmsm_rng.o

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm ./bftoguttseed ./guttseedtobf *.o
