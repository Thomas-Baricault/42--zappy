all: server client gfx

server:
	@make -C server all

client:
	@make -C client all

gfx:
	@make -C gfx all

clean:
	@make -C server clean
	@make -C client clean
	@make -C gfx clean

fclean: clean
	@rm -dfr bin

re: fclean all


.PHONY: all server client gfx clean fclean re
