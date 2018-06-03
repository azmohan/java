class stack {
    Object data[1000];
    int top = -1;

    public void push (Object o) {
        top ++;
        data[top] = o;
    }

    public void pop (Object o) {
        top --;
        return data[top + 1];
    }
}
