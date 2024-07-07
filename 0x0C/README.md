# Back-Tracking Method

1. Visted Case Definition: define how to store visited case (`9663`)
    * expand & escape the sight of thinking: **ALWAYS there can be an better way** 

2. Simplification in logics be simplified code (`1182`)
    * Try to simplify logics. This will added to implementing codes easily with less effort in debugging, therefore effective clean codes. **THINK LIKE COMPUTER**


    * taking example: `1182`
        * **THINK LIKE COMPUTER**: Earned insight after running test-cases, you might be able to think of conditions in computer-way(such as returnging condition) 
        * simplified logic: 
            1. visit current if alignes with condition
            2. then, another condition
        * implementation: 
            1. just implement steps of logic:
            ```
            visit(cur);
            visit(cur,stat+status[cur]);
            ```
            2. consider what specifically will do during steps

