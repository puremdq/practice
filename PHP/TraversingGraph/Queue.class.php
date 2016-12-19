<?php
/**
 * User: Pure
 * Date: 2016/12/18
 * 封装一个队列类
 * 队头有元素 队尾没有元素  当队头和队尾相等时队为空
 */
class Queue
{

    private $size = 50;   //队大小
    private $front;// 队头指针
    private $rear;// 队尾指针
    private $queueArr = array();//存放多列元素

    public function __construct($size = 50)
    {
        $this->initQueue($size);
    }

    //初始化队列  队头有元素 队尾没有元素  当队头和队尾相等时队为空
    public function initQueue($size = 50)
    {
        $this->size = $size;
        $this->front = 0;
        $this->rear = 0;
    }


    //判断栈是否为空
    public function isEmptyQueue()
    {
        if ($this->front == $this->rear)
            return true;
        else
            return false;
    }

    //判断栈是否已满
    public function isFullQueue()
    {
        $rear = $this->rear;
        $front = $this->front;
        $size = $this->size;

        if (($rear - $front + $size) % $size == $size - 1)
            return true;
        else
            return false;
    }

    //入队列
    public function push($data)
    {


        if ($this->isFullQueue()) {

            return false;
            //throw new Exception("队列已满,无法入栈");


        } else {


            $this->queueArr[$this->rear++] = $data;

            if ($this->rear >= $this->size) {
                $this->rear = $this->rear % $this->size;
            }


            return true;
        }
    }


    /**
     * @param bool $onlyGet 是否只是得到队首移动  队首指针不移动
     * @return mixed 结果 false 不成功
     * */
    public function pop($onlyGet = false)
    {


        if ($this->isEmptyQueue()) {

            return false;

        } else {

            $res = $this->queueArr[$this->front];

            if ($onlyGet == false) {
                //不是只出队列
                $this->front++;

                if ($this->front > $this->size) {

                    $this->front = $this->front % $this->size;

                }

            }

            return $res;

        }

    }
}