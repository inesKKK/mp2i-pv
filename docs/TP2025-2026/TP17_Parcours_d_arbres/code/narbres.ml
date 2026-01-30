type narbre = NNoeud of int * narbre list

type arbre = Noeud of noeud
and noeud = { x : int; fg : arbre option; fd : arbre option}

let na = NNoeud (1,
                [NNoeud (2,
                         [NNoeud (21, []); NNoeud (22, []); NNoeud (23, [])]);
                 NNoeud (3, [NNoeud (31, []); NNoeud (32, [])]);
                 NNoeud (4, [])])
let a =
  Noeud
    {x = 1;
     fg =
       Some
         (Noeud
            {x = 2;
             fg =
               Some
                 (Noeud
                    {x = 21; fg = None;
                     fd =
                       Some
                         (Noeud
                            {x = 22; fg = None;
                             fd = Some (Noeud {x = 23; fg = None; fd = None})})});
             fd =
               Some
                 (Noeud
                    {x = 3;
                     fg =
                       Some
                         (Noeud
                            {x = 31; fg = None;
                             fd = Some (Noeud {x = 32; fg = None; fd = None})});
                     fd = Some (Noeud {x = 4; fg = None; fd = None})})});
     fd = None}

