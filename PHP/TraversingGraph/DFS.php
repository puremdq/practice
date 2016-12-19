<?php
/**
 * 深度优先遍历
 */

require_once "Map.class.php";


/**
 * 广度优先遍历(搜索)
 * @param Map $map 要遍历的图
 * @param string $start 从此节点开始进行深度遍历
 * @param array $isUse 是否已经被遍历过
 * @param array $list 遍历结果
 * */
function DFS(Map $map, $start, &$isUse, &$list)
{
    $points = $map->points;
    for ($i = 0; $i < count($points); $i++) {
        if ($map->isHaveSide($start, $points[$i])&&!isset($isUse[$points[$i]])) {

            $list[] = $points[$i];
            $isUse[$points[$i]] = 1;
            if (count($list) == count($points)) {
                break;
            } else {

                DFS($map, $points[$i], $isUse, $list);

            }
        }

    }
}


$points = array('a', 'b', 'c', 'd', 'e','f');
$map = new Map($points);
$map->addSide(array('a', 'c', 0));
$map->addSide(array('a', 'd', 0));
$map->addSide(array('c', 'b', 0));
$map->addSide(array('d', 'e', 0));

$map->addSide(array('f', 'e', 0));

$isUse['a']=1;
$list=array('a');

DFS($map,'a',$isUse,$list);

var_dump($list);

/*var_dump($map->getMatrix());
var_dump($map->isHaveSide('c','b'));*/

