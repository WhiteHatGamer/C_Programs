.ONESHELL:

-r:
	mkdir $(DIR)
	cd $(DIR)
	mkdir bin build include lib obj src tests docs
	echo # $(DIR)> README.md
	copy ..\Test\main.c src\main.c
	copy ..\Test\Makefile Makefile