<?php
/**
 * Created by PhpStorm.
 * User: ryoma
 * Date: 15-12-6
 * Time: 下午10:39
 */

//上传图片
public function uploadPicAction(){
    $file = $_FILES['files'];
    $uploadModel = new UploadModel();
    $ret = $uploadModel->upload();

    echo json_encode($ret);exit;
}

public function upload()
{
    if (empty($_FILES) || empty($_FILES['files'])) {
        return array('status' => false, 'msg' => '上传出错');
    }
    if(! Local_Utils::isVaildUploadImg($_FILES['files']['tmp_name'])){
        $ret['err'] = 1;
        $ret['msg'] = '您的格式不允许上传！';
        return $ret;
    }

    if($_FILES['files']['size'] > UPLOAD_IMG_MAX){
        $ret['err'] = 1;
        $ret['msg'] = '上传文件太大';
        return $ret;
    }

    $reqData['filename'] = $_FILES['files']['name'];
    $reqData['content'] = file_get_contents($_FILES['files']['tmp_name']);
    $reqData['time'] = time();
    $reqData['key'] = substr(md5($reqData['time'] . SERVICE_DOC_KEY), 8, 8);
    $res = $this->curlPost(SERVICE_UPLOAD, $reqData);
    $ret = json_decode($res, true);
    return $ret;
}

public static function isVaildUploadImg($filename)  {
    if(empty($filename)){
        return false;
    }
    global $_CONSTANT;

    $valid_img = $_CONSTANT['valid_upload_img'];

    $file     = fopen($filename, "rb");
    $bin      = fread($file, 2); //只读2字节
    fclose($file);
    $strInfo  = @unpack("C2chars", $bin);
    $typeCode = intval($strInfo['chars1'].$strInfo['chars2']);
    if(isset($valid_img[$typeCode])){
        return true;
    } else{
        return false;
    }
}

//其中
$_CONSTANT['valid_upload_img'] = array(
    "255216" => 'jpg',
    "7173" => 'gif',
    "6677" => 'bmp',
    "13780" => 'png'
);
