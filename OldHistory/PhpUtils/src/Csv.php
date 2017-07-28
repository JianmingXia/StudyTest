<?php
/**
 * User: Administrator
 * Date: 15-9-22
 * Time: 下午1:23
 */
class CsvModel{
    private $folder;
    private $url;

    public function __construct($folderName){
        $rootpath = APPLICATION_PATH."/public/resource/download/";
        if (!is_dir($rootpath)) mkdir($rootpath, 0777);
        $this->folder = $rootpath.$folderName."/";
        if (!is_dir($this->folder)) mkdir($this->folder, 0777);
        $this->folder = $this->folder.date("Ymd")."/";
        if (!is_dir($this->folder)) mkdir($this->folder, 0777);
        $host = Yaf_Registry::get ( "default_config" )->get('host')->get("url");
        $this->url = $host."/resource/download/".$folderName."/".date("Ymd")."/";
    }
    public function export($data,$title=array()){

        $fileName = date("YmdHis")."_".Local_Utils::rand(6,"number").".csv";
        $file = fopen($this->folder.$fileName,"w");
        if(count($title)>0){
            $arr = array();
            foreach($title as $k=>$v){
                $arr[] = mb_convert_encoding($v, "gb2312");
            }
            $flag = fputcsv($file,$arr);
            if($flag===false){
                die("write error");
            }
        }
        if(count($data)>0){
            foreach($data as $k=>$v){
                $arr = array();
                foreach($v as $kk=>$vv){
                    $arr[] =  mb_convert_encoding($vv, "gb2312");
                }
                $flag = fputcsv($file,$arr);
                if($flag===false){
                    die("write error");
                }
            }

        }
        fclose($file);

        return $this->url.$fileName;
    }
}