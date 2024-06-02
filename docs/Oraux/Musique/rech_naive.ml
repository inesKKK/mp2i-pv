let est_prefixe motif part ind_part =
  let rec parcours ind_motif =
    if ind_motif = Array.length motif then
      true
    else if motif.(ind_motif) = part.(ind_part+ind_motif) then
      parcours (ind_motif+1)
    else
      false
  in
  parcours 0

let recherche motif part : int =
  let rec parcours ind_part =
    if ind_part = Array.length part then
      -1
    else if est_prefixe motif part ind_part then
      ind_part
    else
      parcours (ind_part + 1)
  in
  parcours 0
