# exemple en python

def recherche(tab : list, n : int) -> bool :
"""entree : tableau d'entiers trie dans l'ordre croissant et entier
    sortie : True si la valeur apparait dans le tableau, False sinon
(attention : on ne fait pas comme ca en python; dans la vraie vie,
il suffit de faire n in tab)"""
    if len(tab)==0 :
        return False
    i = len(tab)//2
    if n==tab[i] :
        return True
    elif n<tab[i] :
        return recherche(tab[:i], n)
    else :
        recherche(tab[i+1:], n)
