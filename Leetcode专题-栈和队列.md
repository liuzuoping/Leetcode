<!-- GFM-TOC -->
* [1. 用栈实现队列](#1-用栈实现队列)
* [2. 用队列实现栈](#2-用队列实现栈)
* [3. 最小值栈](#3-最小值栈)
* [4. 用栈实现括号匹配](#4-用栈实现括号匹配)
* [5. 数组中元素与下一个比它大的元素之间的距离](#5-数组中元素与下一个比它大的元素之间的距离)
* [6. 循环数组中比当前元素大的下一个元素](#6-循环数组中比当前元素大的下一个元素)
<!-- GFM-TOC -->

## 0. 栈与队列基础知识

### Stack中常用方法

```java
public class StackTest {
	public static void main(String[] args) {
		Stack stack = new Stack();
		stack.push(1);//入栈
		
		System.out.println(stack.isEmpty());//false
		
		stack.pop();//出栈
		System.out.println(stack.isEmpty());//true
		
		stack.push(1);//入栈     int 类型
		stack.push(2l);//入栈     Long类型
		stack.push(3.0);//入栈   double类型
		System.out.println("栈中有： "+stack.size()+" 个元素 。");//栈中有： 3 个元素 。		
		//栈中可以存放任何类型
		Person p = new Person("xiaoming",20);
		stack.push(p); //入栈  引用对象
		System.out.println("栈中有： "+stack.size()+" 个元素 。");//栈中有： 3 个元素 。
		//System.out.println(stack.get(4)); java.lang.ArrayIndexOutOfBoundsException: Array index out of range: 4
		
		System.out.println(stack.get(3)); // Person [name=xiaoming, age=20]
		System.out.println(stack.peek()); // Person [name=xiaoming, age=20] 取栈顶值（不出栈）
		
		System.out.println(stack.contains(2));//false
		System.out.println(stack.contains(2l));//true
		
		stack.add(2, p); //入栈
		System.out.println(stack.get(2));//Person [name=xiaoming, age=20]
		System.out.println(stack.size());
		
		System.out.println(stack.capacity());// 10
		
		System.out.println(stack.empty());//false 判空
		System.out.println("栈中有： "+stack.size()+" 个元素 。");//栈中有： 5 个元素 。
		
		Stack stack1 = (Stack) stack.clone();//克隆一个栈结构
		System.out.println("克隆的stack1栈中有： "+stack.size()+" 个元素 。");//克隆的stack1栈中有： 5 个元素 。
		System.out.println(stack.equals(stack1));//true
		
		stack.push("你好");
		System.out.println(stack.equals(stack1));//false
		
		System.out.println(stack.elements().toString());//java.util.Vector$1@7852e922
		
		System.out.println("p元素的下标是："+stack.indexOf(p));//p元素的下标是：2
		
		//stack.forEach();
		
		System.out.println(stack.firstElement());//获取栈底元素
		System.out.println(stack.lastElement());//获取栈顶元素
		
		//stack.insertElementAt(1, "hh");
		//stack.notify();有关线程的操作      Exception in thread "main" java.lang.IllegalMonitorStateException
		
		System.out.println("删除之前有"+stack.size()+"个元素"); //删除之前有6个元素
		stack.remove(3);//删除一个元素
		System.out.println("删除一个元素有"+stack.size()+"个元素");//删除之前有5个元素
		
		System.out.println("之前stack1中有"+stack1.size()+"个元素");
		//stack.removeAll(stack1);
		stack1.removeAll(stack1);  //之前stack1中有5个元素     奇怪的用法！！！！！
		System.out.println("removeAll之后，stack1中有"+stack1.size()+"个元素");//removeAll之后，stack1中有0个元素
		
		System.out.println("改变之前，下表为2的元素值为："+stack.get(2));//改变之前，下表为2的元素值为：Person [name=xiaoming, age=20]
		stack.set(2, "改变下标为2的元素");
		System.out.println("改变之后，下表为2的元素值为："+stack.get(2));//改变之后，下表为2的元素值为：改变下标为2的元素
		
		Object[] stackList = stack.toArray();
		for(int i =0;i<stack.size();i++) {
			System.out.print(stackList[i]+",");
		}
		//1,2,改变下标为2的元素,Person [name=xiaoming, age=20],你好,	
	}
}
```

### 队列常用方法

队列是一个典型的先进先出（FIFO）的容器。即从容器的一端放入事物，从另一端取出，并且事物放入容器的顺序与取出的顺序是相同的。
队列的两种实现方式：

在这里插入图片描述

#### 1、offer()和add()的区别

add()和offer()都是向队列中添加一个元素。但是如果想在一个满的队列中加入一个新元素，调用 add() 方法就会抛出一个 unchecked 异常，而调用 offer() 方法会返回 false。可以据此在程序中进行有效的判断！

#### 2、peek()和element()的区别

peek()和element()都将在不移除的情况下返回队头，但是peek()方法在队列为空时返回null，调用element()方法会抛出NoSuchElementException异常。

#### 3、poll()和remove()的区别

poll()和remove()都将移除并且返回对头，但是在poll()在队列为空时返回null，而remove()会抛出NoSuchElementException异常。


# 1. 用栈实现队列

使用栈实现队列的下列操作：

    push(x) -- 将一个元素放入队列的尾部。
    pop() -- 从队列首部移除元素。
    peek() -- 返回队列首部的元素。
    empty() -- 返回队列是否为空。

示例:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false

说明:

    你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

```java
class MyQueue {
    private Stack<Integer> a;
    private Stack<Integer> b;
    /** Initialize your data structure here. */
    public MyQueue() {
        a=new Stack<>();
        b=new Stack<>();
    }
    /** Push element x to the back of queue. */
    public void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if(b.isEmpty()){
            while(!a.isEmpty()){
                b.push(a.pop());
            }
        }
        return b.pop();
    }    
    /** Get the front element. */
    public int peek() {
        if(b.isEmpty()){
            while(!a.isEmpty()){
                b.push(a.pop());
            }
        }
        return b.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return a.isEmpty()&&b.isEmpty();
    }
}
```

# 2. 用队列实现栈

使用队列实现栈的下列操作：

    push(x) -- 元素 x 入栈
    pop() -- 移除栈顶元素
    top() -- 获取栈顶元素
    empty() -- 返回栈是否为空

注意:

    你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

```java
class MyStack {
    private Queue<Integer> a;
    private Queue<Integer> b;
    /** Initialize your data structure here. */
    public MyStack() {
        a=new LinkedList<>();
        b=new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        a.offer(x);
        while(!b.isEmpty())
            a.offer(b.poll());
        Queue temp=a;
        a=b;
        b=temp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return b.poll();
    }
    
    /** Get the top element. */
    public int top() {
        return b.peek();
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return b.isEmpty();
    }
}
```

# 3. 最小栈

设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

    push(x) —— 将元素 x 推入栈中。
    pop() —— 删除栈顶的元素。
    top() —— 获取栈顶元素。
    getMin() —— 检索栈中的最小元素。


示例:

`输入：`
`["MinStack","push","push","push","getMin","pop","top","getMin"]`
`[[],[-2],[0],[-3],[],[],[],[]]`

`输出：`
`[null,null,null,null,-3,null,0,-2]`

`解释：`
`MinStack minStack = new MinStack();`
`minStack.push(-2);`
`minStack.push(0);`
`minStack.push(-3);`
`minStack.getMin();   --> 返回 -3.`
`minStack.pop();`
`minStack.top();      --> 返回 0.`
`minStack.getMin();   --> 返回 -2.`

提示：

    pop、top 和 getMin 操作总是在 非空栈 上调用。

```java
class MinStack {
    private Stack<Integer> stack;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new Stack<Integer>();
    }
    
    public void push(int x) {
        if(stack.isEmpty()){
            stack.push(x);
            stack.push(x);
        }else{
            int tmp=stack.peek();
            stack.push(x);
            if(tmp<x){
                stack.push(tmp);
            }else{
                stack.push(x);
            }
        }
    }
    
    public void pop() {
        stack.pop();
        stack.pop();
    }
    
    public int top() {
        return stack.get(stack.size()-2);
    }
    
    public int getMin() {
        return stack.peek();
    }
}
```

思路 ：**class MinStack 每次入栈2个元素，一个是入栈的元素本身，一个是当前栈元素的最小值  如：入栈序列为2-3-1，则入栈后栈中元素序列为：2-2-3-2-1-1 * 用空间代价来换取时间代价**

# 4.[有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

```html
"()[]{}"

Output : true
```

```java
public boolean isValid(String s) {
    Stack<Character> stack = new Stack<>();
    for (char c : s.toCharArray()) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else {
            if (stack.isEmpty()) {
                return false;
            }
            char cStack = stack.pop();
            boolean b1 = c == ')' && cStack != '(';
            boolean b2 = c == ']' && cStack != '[';
            boolean b3 = c == '}' && cStack != '{';
            if (b1 || b2 || b3) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}
```

# 5. [每日温度](https://leetcode-cn.com/problems/daily-temperatures/)

根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int n=T.length;
        int[] dist=new int[n];
        Stack<Integer> indexs=new Stack<>();
        for(int curIndex=0;curIndex<n;curIndex++){
            while(!indexs.isEmpty()&&T[curIndex]>T[indexs.peek()]){
                int preIndex=indexs.pop();
                dist[preIndex]=curIndex-preIndex;
            }
            indexs.add(curIndex);
        }
        return dist;
    }
}
```

# 6. 循环数组中比当前元素大的下一个元素

503\. Next Greater Element II (Medium)

[Leetcode](https://leetcode.com/problems/next-greater-element-ii/description/) / [力扣](https://leetcode-cn.com/problems/next-greater-element-ii/description/)

```text
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.
```

与 739. Daily Temperatures (Medium) 不同的是，数组是循环数组，并且最后要求的不是距离而是下一个元素。

```java
public int[] nextGreaterElements(int[] nums) {
    int n = nums.length;
    int[] next = new int[n];
    Arrays.fill(next, -1);
    Stack<Integer> pre = new Stack<>();
    for (int i = 0; i < n * 2; i++) {
        int num = nums[i % n];
        while (!pre.isEmpty() && nums[pre.peek()] < num) {
            next[pre.pop()] = num;
        }
        if (i < n){
            pre.push(i);
        }
    }
    return next;
}
```



## [7 删除字符串中的所有相邻重复项](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/)

给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：

```
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
```

 

提示：

    1 <= S.length <= 20000
    S 仅由小写英文字母组成。

```java
class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sb=new StringBuilder();
        int sbLength=0;
        for(char character:S.toCharArray()){
            if(sbLength!=0&&character==sb.charAt(sbLength-1))
                sb.deleteCharAt(sbLength-- -1);
            else{
                sb.append(character);
                sbLength++;
            }
        }
        return sb.toString();
    }
}
```





## 8 [包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

```
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```

 

提示：

    各函数的调用总次数不超过 20000 次

```java
class MinStack {
    Stack<Integer> A, B;
    public MinStack() {
        A = new Stack<>();
        B = new Stack<>();
    }
    public void push(int x) {
        A.add(x);
        if(B.empty() || B.peek() >= x)
            B.add(x);
    }
    public void pop() {
        if(A.pop().equals(B.peek()))
            B.pop();
    }
    public int top() {
        return A.peek();
    }
    public int min() {
        return B.peek();
    }
}
```

本题难点： 将 min() 函数复杂度降为 O(1) ，可通过建立辅助栈实现；

    数据栈 AAA ： 栈 AAA 用于存储所有元素，保证入栈 push() 函数、出栈 pop() 函数、获取栈顶 top() 函数的正常逻辑。
    辅助栈 BBB ： 栈 BBB 中存储栈 AAA 中所有 非严格降序 的元素，则栈 AAA 中的最小元素始终对应栈 BBB 的栈顶元素，即 min() 函数只需返回栈 BBB 的栈顶元素即可。

因此，只需设法维护好 栈 BBB 的元素，使其保持非严格降序，即可实现 min() 函数的 O(1)O(1)O(1) 复杂度。

函数设计：

    push(x) 函数： 重点为保持栈 BBB 的元素是 非严格降序 的。
        将 xxx 压入栈 AAA （即 A.add(x) ）；
        若 ① 栈 BBB 为空 或 ② xxx 小于等于 栈 BBB 的栈顶元素，则将 xxx 压入栈 BBB （即 B.add(x) ）。
    
    pop() 函数： 重点为保持栈 A,BA, BA,B 的 元素一致性 。
        执行栈 AAA 出栈（即 A.pop() ），将出栈元素记为 yyy ；
        若 yyy 等于栈 BBB 的栈顶元素，则执行栈 B 出栈（即 B.pop() ）。
    
    top() 函数： 直接返回栈 AAA 的栈顶元素即可，即返回 A.peek() 。
    
    min() 函数： 直接返回栈 BBB 的栈顶元素即可，即返回 B.peek() 。

## 9 第k个数

有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。

```
示例 1:

输入: k = 5

输出: 9
```

```java
class Solution {
    public int getKthMagicNumber(int k) {
        int i3=0,i5=0,i7=0;
        int dp[]=new int[k];
        dp[0]=1;
        for(int i=1;i<k;i++){
            dp[i]=Math.min(Math.min(3*dp[i3],5*dp[i5]),7*dp[i7]);
            if(dp[i]==3*dp[i3]) i3++;
            if(dp[i]==5*dp[i5]) i5++;
            if(dp[i]==7*dp[i7]) i7++;
        }
        return dp[k-1];
    }
}
```

## 10 [Excel表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number/)

给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

示例 1:

```
输入: "A"
输出: 1

示例 2:

输入: "AB"
输出: 28

示例 3:

输入: "ZY"
输出: 701
```

```java
class Solution {
    public int titleToNumber(String s) {
        char[] charArray=s.toCharArray();
        int res=0;
        for(int i=0;i<charArray.length;i++){
            res=res*26+(charArray[i]-'A'+1);
        }
        return res;
    }
}
```



