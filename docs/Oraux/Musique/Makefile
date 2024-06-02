.PHONY: clean
.PRECIOUS: %.cmi %.cmo

main: main.ml musique.cmo rech_naive.cmo
	ocamlc musique.cmo rech_naive.cmo main.ml -o main

%.cmi : %.mli
	ocamlc -c $<

%.cmo : %.ml %.cmi
	ocamlc -c $<

clean:
	@rm -f *.cmi *.cmo main
