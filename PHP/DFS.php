<?php
/**
 * 深度优先遍历
 */

/*
 * 图类
 * */
class Map
{
    private $points = array();//表示该图含有的点
    private $sides = array();//表示该图含有的边  形如[['a','b',0],['b','c',0]]
    private $matrix = null;


    function __construct($points = null, $sides = null)
    {
        $this->points = $points;
        $this->sides = $sides;
    }

    function __get($name)
    {
        if (isset($this->$name)) {


            return $this->$name;
        } else {

            return null;
        }
    }

    /**
     * @param  array $points 点的数组
     * */
    public function setPoints($points)
    {
        $this->points = $points;
    }

    /**
     * 添加点
     * @param  string $point
     * */
    public function addPoint($point)
    {

        if (!in_array($point, $this->points)) {

            $this->points[] = $point;

        }
    }

    /**
     * 设置边
     * @param  array $sides 边的数组
     * */
    public function setSides($sides)
    {
        $this->sides = $sides;
    }

    /**
     * 添加边
     * @param  array $side
     * @return mixed false表示添加失败
     * */
    public function addSide($side)
    {

        if (in_array($side[0], $this->points) && in_array($side[1], $this->points)) {

            $this->sides[] = $side;
            return true;

        } else {

            return false;
        }
    }


    /**
     * 得到邻接矩阵
     * @return array $matrix 当前图的邻接矩阵
     * */
    public function getMatrix()
    {

        if (isset($this->matrix)) {

            return $this->matrix;
        }

        $matrix = array();//邻接矩阵
        foreach ($this->sides as $side) {

            $matrix[$side[0]][$side[1]] = 1;

            if ($side[2] == 0) {
                //如果是无方向边
                $matrix[$side[1]][$side[0]] = 1;
            }

        }
        $this->matrix = $matrix;
        return $this->matrix;
    }

    /**
     * 判断两点之间是否有边
     * @param string $point1
     * @param string $point2
     * @return bool
     * */
    public function isHaveSide($point1, $point2)
    {

        $matrix = $this->getMatrix();

        if (isset($matrix[$point1][$point2]) && $matrix[$point1][$point2] == 1) {

            return true;
        } else {

            return false;
        }
    }

}


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

