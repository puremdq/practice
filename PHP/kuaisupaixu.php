<?php

$arr=[1,3,10,5,9,7,20,18,16];



function quickSort($arr,$k){
	
	$arrLength=count($arr);
	for($i=0;$i<$arrLength;$i++){
		if($i!=$k){

			if($arr[$i]<$arr[$k]){
				$lowArr[]=$arr[$i];
			}else{
				$highArr[]=$arr[$i];
			}
		}
	}

	return array_merge($lowArr,[$arr[$k]],$highArr);
}

var_dump(quickSort($arr,3));

