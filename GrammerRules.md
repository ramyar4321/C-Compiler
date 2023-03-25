# Grammer Rules

These are the grammer rules that will be used to
generate the Abstract Syntax Tree in the Parser.

The asterisk symbols means one or more and 
the vertical bar means either or.

Expr    :   Term (PLUS|MINUS Term)*
Term    :   Factor (MUL|DIV Factor)*
Factor  :   INT