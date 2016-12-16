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

/**
 * @param Str $expression 表达式
 * @return Mixed|double 表达式的值
 * */
function expressionEvaluation($expression)
{
    $expression = divideExpression($expression);

    $operandStack = new stack(20);//操作数栈
    $operatorStack = new stack(20);//操作符栈

    $operatorStack->push('#');
    $expression[] = '#';

    //var_dump($expression);
    //exit();

    for ($i = 0; $i < count($expression); $i++) {

        if (isOperand($expression[$i])) {

            //如果是操作数
            // echo $expression[$i].'<br/>';
            $operandStack->push($expression[$i]);


        } elseif (isOperator($expression[$i])) {

            //如果是操作符
            if (compareOperator($expression[$i], $operatorStack->getTop()) > 0) {

                //当前操作符比栈顶元素优先级高

                /* echo "<br> expression $expression[$i]  <br>";

                 echo "<pre>";
                 var_dump($operatorStack->stack);
                 var_dump($operandStack->stack);
                 echo "</pre>";*/

                if ($expression[$i] == '(') {

                    $operatorStack->push($expression[$i]);

                } elseif ($expression[$i] == ')') {

                    //要计算
                    $operator = $operatorStack->pop();

                    if ($operator != '(') {

                        $operand2 = $operandStack->pop();
                        $operand1 = $operandStack->pop();

                        $res = calculate($operand1, $operator, $operand2);

                        //echo "$operand1 $operator $operand2<br>";

                        $operandStack->push($res);

                        if ($operatorStack->getTop() == '(') {
                            $operatorStack->pop();

                        } else {
                            //youcuo
                            echo "有误";

                        }

                    }

                } elseif (isOperand($expression[$i + 1])) {

                    //下个元素不是操作符  可以计算

                    $operand1 = $operandStack->pop();
                    $operand2 = $expression[$i + 1];

                    $res = calculate($operand1, $expression[$i], $operand2);

                    $operandStack->push($res);

                    $i++;

                } elseif ($expression[$i + 1] == '(') {
                    //不能计算 入栈
                    $operatorStack->push($expression[$i]);
                    $operatorStack->push($expression[++$i]);

                }

            } elseif (compareOperator($expression[$i], $operatorStack->getTop()) <= 0) {


                if ($operatorStack->getTop() != '(' && $operatorStack->getTop() != ')') {


                    $operator = $operatorStack->pop();

                    if ($operator != '#') {

                        $operand2 = $operandStack->pop();
                        $operand1 = $operandStack->pop();

                        $res = calculate($operand1, $operator, $operand2);

                        //echo "<br>$operand1   $operator   $operand2<br>";
                        $operatorStack->push($expression[$i]);
                        $operandStack->push($res);

                    }


                } else {

                    $operatorStack->push($expression[$i]);

                }

                //end 操作符
            } else {
                //非法
                echo "非法";
                exit();
            }

        }   //end for


    }


    return $operandStack->pop();
}


/**
 * 做计算
 * @param string $operand1 操作数1
 * @param string $operator 操作符
 * @param string $operand2 操作数2
 * @return Mixed|double 表达式的值
 * */
function calculate($operand1, $operator, $operand2)
{
    $operand1 = doubleval($operand1);
    $operand2 = doubleval($operand2);
    switch ($operator) {

        case '+':
            return $operand1 + $operand2;
            break;
        case '-':
            return $operand1 - $operand2;
            break;
        case '*':
            return $operand1 * $operand2;
            break;
        case '/':
            return $operand1 / $operand2;
            break;

    }
}

//是否是操作数
function isOperand($ch)
{

    return is_numeric($ch);

}

//是否是操作符
function isOperator($ch)
{

    $operatorArr = array('+', '-', '*', '/', '(', ')', '#');

    if (strlen($ch) != 1) {

        return false;
    }

    if (in_array($ch, $operatorArr, true)) {
        return true;
    } else {
        return false;

    }

}


//求操作符的优先级值
function getOperatorValue($operator)
{

    if ($operator == '#') {
        return -1;

    } elseif ($operator == '+' || $operator == '-') {

        return 0;

    } elseif ($operator == '*' || $operator == '/') {

        return 1;
    } elseif ($operator == '(' || $operator == ')') {
        return 2;
    }

}

/**
 * 比较两个操作数的优先级
 * @param $operator1 操作数1
 * @param $operator2 操作数2
 * @return Mixed|int 1左边优先级高于右边, -1左边优先级低于右边,0相等
 *
 * */
function compareOperator($operator1, $operator2)
{

    $dataToReturn = 0;

    if (!(isOperator($operator1) && isOperator($operator2))) {

        //非法操作
        //echo "sdfsd";
        return false;
    }

    $operator1Val = getOperatorValue($operator1);
    $operator2Val = getOperatorValue($operator2);

    $res = $operator1Val - $operator2Val;

    if ($res == 0) {

        if ($operator1Val == -1) {

            $dataToReturn = 0;
        } else {

            $dataToReturn = 1;
        }

    } else {

        $dataToReturn = $res > 0 ? 1 : -1;
    }

    //echo "<br> $operator1   $operator2  $dataToReturn<br> ";
    return $dataToReturn;

}



//分割表达式
function divideExpression($expression)
{

    $res = array();
    $str = "";
    $j = 0;
    $flag = 0;
    for ($i = 0; $i < strlen($expression); $i++) {
        if (isOperator($expression[$i])) {
            if ($flag == 0) {

                $res[] = $expression[$i];
            } else {

                $res[] = implode('', $str);
                $res[] = $expression[$i];
                $flag = 0;
                $j = 0;
                $str = '';

            }

        } else {
            $flag = 1;
            $str[$j++] = $expression[$i];
        }

        if ($i == strlen($expression) - 1) {

            if ($flag) {

                $res[] = implode('', $str);

            }
        }

    }

    return $res;

}



$expression = "58+((5*(6+4))*8)";
echo $expression . "<br>";
$res = expressionEvaluation($expression);


var_dump($res);