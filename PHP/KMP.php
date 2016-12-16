<?php

/**
 * pattern的第j位失配时
 * pattern向右移动的位数
 * @param String $patten 查找串
 * @param int $j 失配的位置（j从0开始）
 * @return mixed 要移动的位数
 */
function getNextStep($patten, $j)
{

    if (empty($patten))
        return false;


    if ($j < 2) {
        return 1;

    }

    //移动k次
    for ($k = 1; $k < $j; $k++) {
        $flag = 1;

        //移动k位
        for ($i = 0; $i < $j - $k; $i++) {

            if ($patten[$i] != $patten[$k + $i]) {
                $flag = 0;
                break;
            }

        }

        if ($flag == 1) {
            //匹配成功
            return $k;
        }
    }

    return $j;

}


/**
 * KMP算法
 * @param String $str
 * @param String $patten
 * @return mixed $a 首次出现位置
 */
function KMP($str, $patten)
{

    if (empty($patten) || empty($str))
        return false;

    //echo $str."   $patten   ".strlen($patten);exit();
    $i = $j = 0;
    $strLen = strlen($str);
    $pattenLen = strlen($patten);

    while ($i <= $strLen - $pattenLen) {

        $flag = 1;

        for ($j = 0; $j < $pattenLen; $j++) {

            if ($str[$i + $j] != $patten[$j]) {

                $flag = 0;
                $i = $i + getNextStep($patten, $j);
                break;
            }
        }//end for

        if ($flag == 1) {

            //找到
            return $i;
        }

    }

    //未找到
    return false;
}

$str = '1world1 hello world';
$patten = 'world1';
//var_dump(KMP($str, $patten));
