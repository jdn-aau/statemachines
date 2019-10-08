sm 

a very simple efficient state machine in C

added howto document by using dot(graphviz)

A few comments:

- keep local global variables hidden for outside by : static int myLocalVar;
- consider if it is wise to implement memory in a state: local var like  static int IWillKeepValue;
- consider if more states is better than complex code in state(s)
- it is possible to track within the main "while (1)" 

/Jens
