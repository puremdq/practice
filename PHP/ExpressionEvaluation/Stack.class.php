<?php
/**
 * User: Pure
 * Date: 2016/12/13
 * Time: 19:42
 * 封装一个栈操作类
 */
class stack
{

    private $size = 50;   //栈大小
    private $top = -1;       // int 栈顶
    private $stack = array();


    public function __construct($size = 50)
    {
        $this->initStack($size);
    }


    //初始化栈
    public function initStack($size = 50)
    {
        $this->size = $size;
        $this->top = -1;
    }


    //判断栈是否为空
    public function isEmptyStack()
    {
        if ($this->top == -1)
            return true;
        else
            return false;
    }

    //判断栈是否已满
    public function isFullStack()
    {
        if ($this->top >= $this->size - 1)
            return true;
        else
            return false;
    }

    //入栈
    public function push($data)
    {


        if ($this->isFullStack()) {

            return false;

        } else {

            $this->stack[++$this->top] = $data;
            return true;

        }
    }


    //出栈
    public function pop()
    {


        if ($this->isEmptyStack()) {

            return false;

        } else {

            $res = $this->stack[$this->top];
            //unset($this->stack[$this->top]);
            $this->top--;
            return $res;

        }

    }

    //得到栈顶元素但不出栈
    public function getTop()
    {

        if ($this->isEmptyStack()) {

            return null;

        } else {
            return $this->stack[$this->top];

        }
    }

}
