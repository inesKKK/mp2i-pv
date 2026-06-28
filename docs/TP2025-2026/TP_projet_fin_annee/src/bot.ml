let _ =
  let f = open_in "plateau" in
  let minimum = int_of_string (input_line f) in
  let maximum = int_of_string (input_line f) in
  let res = ((minimum + maximum) / 2) in
  print_int res;
  print_newline (); (* pour vider le buffer *)
  close_in f
