# exemple en python
def note_sous_la_moyenne(notes) :
    return len(notes)!=0 and ( notes[0]<10 or note_sous_la_moyenne(notes[1:]) )
