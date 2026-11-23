all: server client gfx

server:
	make -C server all
	cp server/build/server .

client:
	make -C client all
	cp client/build/client .

gfx:
	make -C gfx all
	cp gfx/build/gfx .

clean:
	make -C server clean
	make -C client clean
	make -C gfx clean

fclean: clean
	rm -f server
	rm -f client
	rm -f gfx

re: fclean all


.PHONY: all server client gfx clean fclean re
