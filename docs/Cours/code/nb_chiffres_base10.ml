let rec nb n =
  if n = 0 then 0 else 1 + nb (n / 10)

let nombre_de_chiffres_en_base_10 n =
  if n = 0 then 1 else nb n
