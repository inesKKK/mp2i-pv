#include "grandes_lettres.h"

char *grandes_lettres[] = {"  *  \n * * \n*   *\n*****\n*   *",
                  "*** \n*  *\n*** \n*  *\n*** ",
                  " ** \n*  *\n*   \n*  *\n ** ",
                  "*** \n*  *\n*  *\n*  *\n*** ",
                  "***\n*  \n** \n*  \n***",
                  "***\n*  \n** \n*  \n*  ",
                  " ** \n*   \n* **\n* * \n ** ",
                  "*  *\n*  *\n****\n*  *\n*  *",
                  "*\n*\n*\n*\n*",
                  "   *\n   *\n   *\n*  *\n **",
                  "*  *\n* * \n**  \n* * \n*  *",
                  "*  \n*  \n*  \n*  \n***",
                  "*   *\n** **\n* * *\n*   *\n*   *",
                  "*   *\n**  *\n* * *\n*  **\n*   *",
                  " ** \n*  *\n*  *\n*  *\n ** ",
                  "** \n* *\n** \n*  \n*  ",
                  " ** \n*  *\n*  *\n* **\n ***",
                  "** \n* *\n** \n* *\n* *",
                  " ** \n*   \n ** \n   *\n ** ",
                  "*****\n  *  \n  *  \n  *  \n  *  ",
                  "*  *\n*  *\n*  *\n*  *\n ** ",
                  "*   *\n*   *\n*   *\n * * \n  *  ",
                  "*   *\n*   *\n*   *\n* * *\n * * ",
                  "*   *\n * * \n  *  \n * * \n*   *",
                  "*   *\n * * \n  *  \n *   \n*    ",
                  "****\n  * \n *  \n*   \n****",
                  "  \n  \n  \n  \n  "
};

char *grande_lettre(char c){
  if (c == ' '){
    return grandes_lettres[26];
  }
  return grandes_lettres[c - 'a'];
}
