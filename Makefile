makechecker:
	@make -C dchecker >/dev/null
	@cp dchecker/checker .

runchecker: makechecker
	@./checker $(LIST)
