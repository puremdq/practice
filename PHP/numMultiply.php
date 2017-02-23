<?php


/**
 *�������
 *@author [puremdq] <[<puremdq@gmail.com>]>
 *@time   2017��2��23��
 *just for practice
 */



/**
 * ����������������
 * @param $data array Ҫ���������
 * @param $afterPointLength int С�����λ��
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
 * �ų�ĳ���ַ�
 * @param $ch string Ҫ�ų����ַ�
 * @param $str string Ҫ���в������ַ���
 * @return int ���ֺ��С����λ��
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
 * ������� �������洢
 * @param $num1 string ��һ����
 * @param $num2 string �ڶ�����
 */
function numMultiply($num1, $num2)
{
    /*������� */

    $num1AfterPointLength = excludeChar($num1);
    $num2AfterPointLength = excludeChar($num2);

    $afterPointLength = $num1AfterPointLength + $num2AfterPointLength;

    if (strlen($num1) > strlen($num2)) {
        //ȷ�� num2�ĳ��Ƚ϶� �������ѭ������
        $temp = $num1;
        $num1 = $num2;
        $num2 = $temp;

    }

    $tempRes = array();
    $res = array();
    $carry = 0;//���ڴ洢��λ

    for ($i = strlen($num2) - 1; $i >= 0; $i--) {

        $flag = 0;
        $tempRes = null;//�洢һ��
        for ($j = strlen($num1) - 1; $j >= 0; $j--) {

            $temp = intval($num1[$j]) * intval($num2[$i]) + $flag;

            if ($temp >= 10) {

                $tempRes[] = $temp % 10;
                $flag = intval($temp / 10); //��λ

            } else {

                $tempRes[] = $temp;
                $flag = 0;

            }

        }

        if ($flag > 0) {
            $tempRes[] = $flag;
        }

        //echo "di" . intval(strlen($num2) - $i) . " ��:";
        //forDebug($tempRes);

        $carry = 0; //����Ϊ��Ϊ��
        for ($k = 0; $k < count($tempRes); $k++) {

            if (!isset($res[strlen($num2) - 1 - $i + $k])) {
                $res[strlen($num2) - 1 - $i + $k] = 0;
            }

            $temp = $res[strlen($num2) - 1 - $i + $k] + $tempRes[$k] + $carry;
//            echo "$temp = {$res[strlen($num2) - 1-$i + $k]} + $tempRes[$k] + $carry <br>";
            if ($temp >= 10) {

                $res[strlen($num2) - 1 - $i + $k] = $temp % 10;
                $carry = 1; //��λ
                //echo '�н�λ�ĸ�ֵ res[' . intval(strlen($num2) - 1 - $i + $k) . '] = ' . $temp % 10 . '<br>';

            } else {

                $res[strlen($num2) - 1 - $i + $k] = $temp;
                $carry = 0; //jinwei
                //echo "�޽�λ�ĸ�ֵ: res[" . intval(strlen($num2) - 1 - $i + $k) . "] = " . $temp . "<br>";

            }

        }
        if ($carry > 0) {

            $res[] = $carry;
        }

        // echo "��" . intval(strlen($num2) - $i) . " �� res:";
        //forDebug($res);

    }

    /*����С����*/

    forDebug($res, $afterPointLength);

    //return $res;

}

numMultiply('8888','8888888888888888888888888888888888888.8888888888');