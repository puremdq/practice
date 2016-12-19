<?php
/**
 * 广度优先搜索
 */


require_once "Map.class.php";
require_once "Queue.class.php";


/**
 * 广度优先遍历(搜索)
 * @param Map $map 要遍历的图
 * @param Queue $queue 遍历过程中要用到的栈
 * @param array $isUse 是否已经被遍历过
 * @param array $list 遍历结果
 * */
function BFS(Map $map, $queue, &$isUse, &$list)
{
    $flag = 0;

    while (!$queue->isEmptyQueue()) {

        $current = $queue->pop();

        for ($i = 0; $i < count($map->points); $i++) {

            if ($map->isHaveSide($current, $map->points[$i]) && (!isset($isUse[$map->points[$i]]) || $isUse[$map->points[$i]] != 1)) {
                $list[] = $map->points[$i];
                $queue->push($map->points[$i]);
                $isUse[$map->points[$i]] = 1;

                if (count($list) >= count($map->points)) {
                    $flag = 1;
                    break;

                }
            }

        }

        if ($flag == 1) {

            break;
        }

    }

}

$points = array('a', 'b', 'c', 'd', 'e', 'f');
$map = new Map($points);
$map->addSide(array('a', 'c', 0));
$map->addSide(array('a', 'd', 0));
$map->addSide(array('c', 'b', 0));
$map->addSide(array('d', 'e', 0));
$map->addSide(array('f', 'e', 0));

$start = 'f';
$list = array('f');
$isUse['f'] = 1;

$queue = new Queue(count($points)+1);
$queue->push('f');

BFS($map, $queue, $isUse, $list);

var_dump($list);
