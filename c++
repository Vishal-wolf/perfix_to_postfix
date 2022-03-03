// VISHAL BHAYDIYA 0801IT181091 //
#include&lt;bits/stdc++.h&gt;
using namespace std;
class Stack {
int top;
int MAX;
int* a;
public:
Stack(int size){
top = -1;
MAX = size;
a = new int [MAX];
}
bool push(int x);
int pop();
int peek();
bool isEmpty();
bool isFull();
};
bool Stack::isEmpty(){
return (top &lt; 0);
}
bool Stack::isFull(){
return (top == MAX - 1);
}
int Stack::peek(){
return a[top];
}
bool Stack::push(int x) {
if (top &gt;= (MAX - 1)) {
cout &lt;&lt; &quot;Stack Overflow&quot;;
return false;
}
else {
top++;
a[top] = x;
return true;
}
}
int Stack::pop()
{
if (top &lt; 0) {
cout &lt;&lt; &quot;Stack Underflow&quot;;
return INT_MIN;
}
else {
int x = a[top];
top--; return x;
}
}
int priority (char alpha)
{
if(alpha == &#39;+&#39; || alpha ==&#39;-&#39;)
return 1;
if(alpha == &#39;*&#39; || alpha ==&#39;/&#39;)
return 2;
if(alpha == &#39;^&#39;)
return 3;

return 0;
}
string convert(string infix)
{
int i = 0;
string postfix = &quot;&quot;;
int n; n=infix.length();
Stack s(n);
while(infix[i]!=&#39;\0&#39;)
{
if(infix[i]&gt;=&#39;a&#39; &amp;&amp; infix[i]&lt;=&#39;z&#39;|| infix[i]&gt;=&#39;A&#39;&amp;&amp; infix[i]&lt;=&#39;Z&#39;)
{
postfix += infix[i];
i++;
}
else if(infix[i]==&#39;(&#39;)
{
s.push(infix[i]);
i++;
}
else if(infix[i]==&#39;)&#39;)
{
while(s.peek()!=&#39;(&#39;)
postfix += s.pop();
s.pop();
i++;
}
else
{
while (!s.isEmpty() &amp;&amp; priority(infix[i]) &lt;= priority(s.peek())){
postfix += s.pop();
}
s.push(infix[i]);
i++;
}
}
while(!s.isEmpty()){
postfix += s.pop();
}
cout &lt;&lt; &quot;Postfix is : &quot; &lt;&lt; postfix;
return postfix;
}
int main()
{
string infix ;
getline(cin&gt;&gt;ws, infix);
string postfix;
cout &lt;&lt; &quot;Infix is : &quot; &lt;&lt; infix&lt;&lt;endl;
postfix = convert(infix);
return 0;
}
