all : moteur bot com

allC : moteur botC com

moteur : moteur.c
	gcc -Wall -pedantic -o moteur moteur.c

bot : bot.ml
	ocamlopt -o bot bot.ml

botC : botC.c
	gcc -g -Wall -pedantic -o botC botC.c

com : communication.c
	gcc -Wall -pedantic -o com communication.c

run : all
	./com moteur bot

runC : allC
	./com moteur botC

see :
	ps -aef | egrep "com|moteur|bot"

clean :
	killall -9 moteur; killall -9 bot; killall -9 com; rm -f com moteur bot botC bot.cmi bot.cmx bot.o plateau
