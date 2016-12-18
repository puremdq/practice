<?php

$dataNeedTo24=[1,2,3,4];

$fuhao=[];
$re=tryTo24(getArr($dataNeedTo24),$dataNeedTo24[count($dataNeedTo24)-1],24);

if($re){
    $str='24=';
    foreach ($dataNeedTo24 as $key => $value) {

        $str=$str.$value.$fuhao[$key];
    }
    echo "$str";

}else{
    echo "不能得到24";
}

function getArr($arrData){
    /*去掉数组的最后一个元素*/
    $dataToreturn=[];
    for($i=0;$i<count($arrData)-1;$i++){
        $dataToreturn[$i]=$arrData[$i];
    }
    return $dataToreturn;

}
function tryTo24(array $currentArr,$theRest,$wantTo){

    $length=count($currentArr);

    if($length>1){

        //$currentResult 用于记录currentArr可能的值,使得 currentArr@theRest=wantTo
        //

        $currentResult=$wantTo+$theRest;//通过-都得到
        $res=tryTo24(getArr($currentArr),$currentArr[$length-1],$currentResult);
        if($res){
            $GLOBALS['fuhao'][$length-1]='-';
            return true;
        }


        $currentResult=$wantTo-$theRest;//通过+都得到
        $res=tryTo24(getArr($currentArr),$currentArr[$length-1],$currentResult);
        if($res){

            $GLOBALS['fuhao'][$length-1]='+';
            return true;
        }

        $currentResult=$wantTo*$theRest;//通过/都得到
        $res=tryTo24(getArr($currentArr),$currentArr[$length-1],$currentResult);
        if($res){

            $GLOBALS['fuhao'][$length-1]='/';
            return true;
        }


        $currentResult=$wantTo/$theRest;//通过*都得到
        $res=tryTo24(getArr($currentArr),$currentArr[$length-1],$currentResult);
        if($res){

            $GLOBALS['fuhao'][$length-1]='*';
            return true;
        }

        return false;

    }else{
        if(abs($currentArr[0]+$theRest-$wantTo)<0.0000001)
            $res= "+";
        elseif (abs($currentArr[0]-$theRest-$wantTo)<0.0000001) {
            $res="-";
        }
        elseif (abs($currentArr[0]*$theRest-$wantTo)<0.0000001) {
            $res="*";
        }
        elseif (abs($currentArr[0]/$theRest-$wantTo)<0.0000001) {
            $res="/";
        }else{
            $res=false;
        }
        if($res){
            $GLOBALS['fuhao'][0]=$res;
        }
        return $res;
    }


}

