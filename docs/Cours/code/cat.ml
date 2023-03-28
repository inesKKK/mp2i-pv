let affichage fichier = let instream = open_in fichier in
                        try
                          while true do
                            let lu = input_line instream in
                            print_endline lu
                          done
                        with End_of_file -> close_in instream
