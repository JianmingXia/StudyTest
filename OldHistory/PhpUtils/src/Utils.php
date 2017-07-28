<?php
class Local_Utils{
    private function __construct(){}

    public static function rand($count,$type=CODE_CHAR)  {
        $chars='ABDEFGHJKLMNOPQRSTVWXYabdefghijkmnopqrstvwxy0123456789'; // characters to build the password from
        if($type == CODE_NUMBER){
            $chars = "0123456789";
        }
        mt_srand((double)microtime()*1000000*getmypid()); // seed the random number generater (must be done)
        $str='';
        while(strlen($str)<$count)
            $str.=substr($chars,(mt_rand()%strlen($chars)),1);
        return $str;
    }

    /*
     * @desc 输出函数
    * @param
    *       $code 状态码,$msg 错误信息,$data 数据
    */
    static function outputInfo($code='0',$msg='',$data=array()){
        $result = array(
                "code" => $code,
                "msg" => $msg,
                "data" =>$data
        );
        echo json_encode($result);
        exit;
    }

    static function getParam($param,$default=null){
        if (is_array($_REQUEST[$param])) {
            foreach ($_REQUEST[$param] as $key => $sub_value) {
                $value[$key] = strip_tags(addslashes(trim($sub_value)));
            }
            return $value;
            //throw new Exception("value(Array) is not supported by METHOD:getParam");
        }

        $value = trim($_REQUEST[$param]);

        $value = strip_tags(addslashes(trim($value)));

        if ($value == null && $default != null) {
            $value = $default;
        }
        return $value;
    }

    static function getPostParams(){
        return self::getParams("POST");
    }

    static function getGetParams(){
        return self::getParams("GET");
    }

    static function getPutParams(){
        return self::getParams("PUT");
    }

    static function  getParams($requestType=null){
        $data = array();
        if(is_null($requestType)){
            $data = $_REQUEST;
        }else if($requestType == "GET"){
            $data = $_GET;
        }else if($requestType == "POST"){
            $data = $_POST;
        }else if($requestType == "PUT"){
            $putData = file_get_contents('php://input', 'r');
            parse_str($putData,$data);
        }else{
            return false;
        }
        if (empty($data)) {
            return false;
        }
        $params = array();
        foreach ($data as $key => $value) {
            if(!self::isValidJson($value))
                $params[$key] = self::getParam($key);
            else
                $params[$key] = trim($value);
        }

        return $params;
    }

    static function filter($str){
        return strip_tags(addslashes($str));
    }

    private static function isValidJson($jsonStr){
        $re = json_decode($jsonStr);
        return !empty($re);
    }

    //分表方法
    static function get_hash_table($userid)
    {
        $str = crc32($userid);
        if($str<0){
            $hash = "0".substr(abs($str), 0, 1);
        }else{
            $hash = substr($str, 0, 2);
        }
        return $hash;
    }

    static function getPageList($page, $page_size, $total){
        $pages = ceil($total / $page_size);
        $page = $page > $pages ? $pages : $page;

        return array(
            "pages" => $pages,
            "page" => $page,
            "total" => $total,
            "page_size" => $page_size
        );
    }

    static function getPageLimit($page,$pageSize){
        $page = $page > 0 ? $page : 1;
        $limit = array(
            ($page - 1) * $pageSize,
            $pageSize,

        );
        return $limit;
    }

    static function formatPercent($value,$precision=2){
        if(is_numeric($value)){
            return sprintf("%.".$precision."f",$value*100)."%";
        }
        return $value;
    }

    static function formatRate($v1,$v2,$precision=2){
        return empty($v2)?'&infin;':sprintf('%.'.$precision.'f',$v1/$v2);
    }
    
    static function httpRequest($host,$type='GET',$data=array(),$timeout=10){
        $ch = curl_init();
        
        $params = http_build_query($data);
        $url = $host."?".$params;
        // 2. 设置选项，包括URL
        if($type=='GET'){
            curl_setopt($ch, CURLOPT_URL, $host."?".$params);
        }elseif($type=='POST'){
            curl_setopt($ch, CURLOPT_POST, 1);
            curl_setopt($ch, CURLOPT_URL, $host);
            //curl_setopt($ch, CURLOPT_POST,count($data)) ; // 启用时会发送一个常规的POST请求，类型为：application/x-www-form-urlencoded，就像表单提交的一样。
            curl_setopt($ch, CURLOPT_POSTFIELDS,$params);
        }else{
            curl_setopt($ch, CURLOPT_URL, $host."?".$params);
        }
        curl_setopt($ch, CURLOPT_TIMEOUT,$timeout);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        //curl_setopt($ch, CURLOPT_HEADER, 1);
        // 3. 执行并获取HTML文档内容
        $output = curl_exec($ch);
        
        // 4. 释放curl句柄
        curl_close($ch);
        return $output;
    }

    static function firstOrder($param)
    {
        //utf-8编码
        $result = "";
        if(!empty($param)){
            $result = "CONVERT( ".$param." USING gbk ) COLLATE gbk_chinese_ci ASC";
        }
        return $result;
    }
}