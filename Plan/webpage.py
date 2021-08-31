#!/usr/bin/env python3

import os
import locale
from datetime import datetime

topics = { 'algorithmic':{'dir': 'Algorithmique', 'md':'algorithmique.md', 'title':'Algorithmique'},
           'databases':{'dir':'BasesDeDonnees','md':'bd.md', 'title':'Bases de données'},
           'coding':{'dir':'Programmation','md':'prog.md', 'title':'Programmation'},
           'systems':{'dir':'Systemes','md':'systemes.md','title':'Systèmes'} }
synthesis = 'synthese.md'
chronology = 'chronologie.md'


class Course :
    def __init__(self, dir, file):
        self.part = dir
        self.date = file
        self.absract = ""
        self.description = ""
        self.set_data(dir, file)

    def set_data(self, dir, file):
        f = open(dir + '/' + file, 'r')
        s = ''
        space = ''
        for line in f:
            if line[0] == '#':
                self.abstract = s
                s = ''
                space = '> '
                continue
            s += space + line
        self.description = s

    def write_course(self, f, with_date=True, with_topic=False):
        f.write('* ')
        if(with_date):
            f.write(nice_date(self.date) + ' : ')
        if(with_topic):
            f.write('[' + self.part[0] + '] ')
        f.write(self.abstract)
        f.write(self.description)

    def write_in_right_position(self, f) :
        ordered_topics = sorted([ t['title'] for t in topics.values()])
        n = ordered_topics.index(self.part)
        for i in range(0, len(ordered_topics)) :
            if i==n : f.write(self.abstract.strip().replace('\n', '<br />'))
            f.write(' | ')
        f.write('\n')



def not_yet(file) :
    return file[0] == '_'

def headers():
    with open(synthesis, 'w') as f :
        f.write("""## Plan du cours\n
|   | """)
        for topic in sorted(topics.values(), key=lambda t: t['title']):
            f.write(topic['title'] + ' | ')
        f.write("""\n|---|-----------|---------|---------|-------|\n""")
        f.close()
    with open(chronology, 'w') as f :
        f.write("## Chronologie du cours\n\n")
        f.close()
    for topic in topics.values() :
        with open(topic['md'], 'w') as f :
            f.write('## ' + topic['title'] + '\n\n')
            f.close()


def nice_date(date):
    return datetime.strptime(date, "%Y%m%d").strftime("%A %-d %B %Y")
            
def bodies(courses):
    for topic in topics.values():
        #get only the courses for this topic
        topic_courses = list(filter(lambda c: c.part == topic['dir'], courses))
        topic_courses.sort(key=lambda c: c.date) # in chronological order
        with open(topic['md'], 'a') as f :
            for c in topic_courses :
                c.write_course(f)
            f.close()
    courses.sort(key=lambda c: c.date)
    with open(synthesis, 'a') as f:
        for c in courses:
            f.write('| '+ nice_date(c.date) + ' | ')
            c.write_in_right_position(f)
        f.close()
    with open(chronology, 'a') as f :
        old_date = ""
        for c in courses:
            if c.date != old_date:
                old_date = c.date
                f.write('#### ' + nice_date(c.date) + '\n')
            c.write_course(f, with_date=False, with_topic=True)
        f.close()


def write_foot(f):
    f.write('\n\n\n')
    f.write('[Synthèse](' + synthesis + ') [Chronologie](' + chronology +') ')
    for topic in topics.values() :
        f.write('[' + topic['title'] + '](' + topic['md'] + ') ')
    f.write('\n\n\n')
        
        
def footers():
    with open(synthesis, 'a') as f :
        write_foot(f)
        f.close()
    with open(chronology, 'a') as f :
        write_foot(f)
        f.close()
    for topic in topics.values() :
        with open(topic['md'], 'a') as f :
            write_foot(f)
            f.close()
        
            
if __name__ == '__main__':
    locale.setlocale(locale.LC_TIME,'')
    headers()
    courses = []
    for topic in topics.values() :
        dir = topic['dir']
        for file in os.listdir(dir) :
            if not_yet(file) : continue
            print("adding " + dir + '/' + file)
            courses.append(Course(dir, file))
    bodies(courses)
    footers()
