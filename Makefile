chacker: checker_folder/srcs/*.c checker_folder/includes/*.h
	@make -C checker_folder >/dev/null
	@cp checker_folder/checker .
	@echo "checker done"
