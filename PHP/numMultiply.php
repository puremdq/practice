<?php


/**
 *大数相乘
 *@author [puremdq] <[<puremdq@gmail.com>]>
 *@time   2017年2月23日
 *just for practice
 */



/**
 * 输出逆序的数字数组
 * @param $data array 要输出的数组
 * @param $afterPointLength int 小数点后位数
 * */
function forDebug($data, $afterPointLength = 0)
{

    //echo "afterPointLength:" . $afterPointLength . "<br>";
    

    for ($i = count($data) - 1; $i >= 0; $i--) {


        if ($afterPointLength != 0) {

            if (count($data) - $afterPointLength == count($data) - 1 - $i) {

                //echo "i:$i  ";
                echo '.';
            }
        }
        echo $data[$i];

    }
    echo "<br/>";
}

/**
 * 排除某个字符
 * @param $ch string 要排除的字符
 * @param $str string 要进行操作的字符串
 * @return int 数字后的小数点位数
 * */
function excludeChar(&$str, $ch = '.')
{
    $pointIndex = strpos($str, $ch);

    if ($pointIndex !== false) {

        $str = str_replace($ch, '', $str);
        return strlen($str) + 1 - ($pointIndex + 1);

    } else {

        return 0;
    }

}


/**
 * 大数相乘 结果逆序存储
 * @param $num1 string 第一个数
 * @param $num2 string 第二个数
 */
function numMultiply($num1, $num2)
{
    /*结果逆序 */

    $num1AfterPointLength = excludeChar($num1);
    $num2AfterPointLength = excludeChar($num2);

    $afterPointLength = $num1AfterPointLength + $num2AfterPointLength;

    if (strlen($num1) > strlen($num2)) {
        //确保 num2的长度较短 降低外层循环次数
        $temp = $num1;
        $num1 = $num2;
        $num2 = $temp;

    }

    $tempRes = array();
    $res = array();
    $carry = 0;//用于存储进位

    for ($i = strlen($num2) - 1; $i >= 0; $i--) {

        $flag = 0;
        $tempRes = null;//存储一层
        for ($j = strlen($num1) - 1; $j >= 0; $j--) {

            $temp = intval($num1[$j]) * intval($num2[$i]) + $flag;

            if ($temp >= 10) {

                $tempRes[] = $temp % 10;
                $flag = intval($temp / 10); //进位

            } else {

                $tempRes[] = $temp;
                $flag = 0;

            }

        }

        if ($flag > 0) {
            $tempRes[] = $flag;
        }

        //echo "di" . intval(strlen($num2) - $i) . " 层:";
        //forDebug($tempRes);

        $carry = 0; //将仅为制为零
        for ($k = 0; $k < count($tempRes); $k++) {

            if (!isset($res[strlen($num2) - 1 - $i + $k])) {
                $res[strlen($num2) - 1 - $i + $k] = 0;
            }

            $temp = $res[strlen($num2) - 1 - $i + $k] + $tempRes[$k] + $carry;
//            echo "$temp = {$res[strlen($num2) - 1-$i + $k]} + $tempRes[$k] + $carry <br>";
            if ($temp >= 10) {

                $res[strlen($num2) - 1 - $i + $k] = $temp % 10;
                $carry = 1; //进位
                //echo '有进位的赋值 res[' . intval(strlen($num2) - 1 - $i + $k) . '] = ' . $temp % 10 . '<br>';

            } else {

                $res[strlen($num2) - 1 - $i + $k] = $temp;
                $carry = 0; //jinwei
                //echo "无进位的赋值: res[" . intval(strlen($num2) - 1 - $i + $k) . "] = " . $temp . "<br>";

            }

        }
        if ($carry > 0) {

            $res[] = $carry;
        }

        // echo "第" . intval(strlen($num2) - $i) . " 层 res:";
        //forDebug($res);

    }

    /*加上小数点*/

    forDebug($res, $afterPointLength);

    //return $res;

}

numMultiply('8888','8888888888888888888888888888888888888.8888888888');