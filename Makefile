makechecker:
	@make -C dchecker >/dev/null
	@cp dchecker/checker .

runchecker: makechecker
	@./checker $(LIST)

runcorrect: makechecker
	@make -C correct >/dev/null
	@./correct/push_swap $(LIST) #| ./checker $(LIST)
