makechecker:
	@make -C checker_folder >/dev/null
	@cp checker_folder/checker .

runchecker: makechecker
	@./checker $(LIST)

runcorrect: makechecker
	@make -C correct >/dev/null
	@./correct/push_swap $(LIST) | ./checker $(LIST)
