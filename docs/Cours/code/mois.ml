type mois = Jan | Fev | Mar | Avr | Mai | Juin | Juil | Aou | Sep | Oct | Nov | Dec

let nombre_de_jours m =
  match m with
  | Fev -> 28
  | Jan | Mar | Mai | Juil | Aou | Oct | Dec -> 31
  | _ -> 30
