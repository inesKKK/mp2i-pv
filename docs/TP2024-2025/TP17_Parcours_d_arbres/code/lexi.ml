type lexi = Vide | Noeud of noeud
and noeud = { car : char;
              mutable fg : lexi;
              mutable fd : lexi;
              mutable fin : bool
            }

let ex1 = Noeud {
              car = 'i';
              fin = false;
              fg = Noeud {
                       car = 'n';
                       fd = Vide;
                       fin = false;
                       fg = Noeud {
                                car = 'f';
                                fd = Vide;
                                fin = true;
                                fg = Noeud {
                                         car = 'o';
                                         fg = Vide;
                                         fd = Vide;
                                         fin = true
                                       }
                              }
                     };
              fd =  Noeud {
                        car = 'm';
                        fd = Vide;
                        fin = false;
                        fg = Noeud {
                                 car = 'a';
                                 fd = Vide;
                                 fin = false;
                                 fg = Noeud {
                                          car = 't';
                                          fd = Vide;
                                          fin = false;
                                          fg = Noeud {
                                                   car = 'e';
                                                   fin = false;
                                                   fd = Noeud {
                                                            car = 'h';
                                                            fg = Vide;
                                                            fin = true;
                                                            fd = Noeud {
                                                                     car = 'r';
                                                                     fd = Vide;
                                                                     fin = false;
                                                                     fg = Noeud {
                                                                              car = 'i';
                                                                              fd = Vide;
                                                                              fin = false;
                                                                              fg = Noeud {
                                                                                       car = 'c';
                                                                                       fd = Vide;
                                                                                       fin = false;
                                                                                       fg = Noeud {
                                                                                                car = 'e';
                                                                                                fg = Vide;
                                                                                                fd = Vide;
                                                                                                fin = true
                                                                                              }
                                                                                     }
                                                                            }
                                                                   }
                                                          };
                                                   fg = Noeud {
                                                            car = 'l';
                                                            fd = Vide;
                                                            fin = false;
                                                            fg = Noeud {
                                                                     car = 'a';
                                                                     fd = Vide;
                                                                     fin = false;
                                                                     fg = Noeud {
                                                                              car = 's';
                                                                              fg = Vide;
                                                                              fd = Vide;
                                                                              fin = true;
                                                                            }
                                                                   }
                                                          }
                                                 }
                                        }
                               }
                      }
            };
