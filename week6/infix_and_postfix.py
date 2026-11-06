def priority(op):
    if op == '^':
        return 3
    elif op in ('*', '/'):
        return 2
    elif op in ('+', '-'):
        return 1
def isOperator(expr):
    st=[]
    output =""
    
    for c in expr:
        if c.alnum:
            output +=c 
        elif c == '(':
            st.push(c)
        elif c == ')':
            while st and st.top != '(':
                output += st.top
                st.pop
            st.pop
        elif c in Operator:
            while st and priority(st[-1]) >= priority(c):
                output += st.top
                st.pop
            st.push
    while(st):
        output += st.top
        st.pop
            