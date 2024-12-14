<?php 
    include("koneksiiot.php"); //impor file koneksi database

    date_default_timezone_set('Asia/Jakarta');
    $waktu = date("H:i:s");
    $tanggal = date("d F Y");
    $sensor_infrared= $_GET ["sensor_infrared"];  //ambil data sensor dari parameter
    

    $kirim = mysqli_query($koneksi,"INSERT INTO datasensor (waktu,tanggal,sensor_infrared) 
    VALUES ('$waktu','$tanggal','$sensor_infrared')");
//pengecekan apakah data berhasil disimpan??
    if($kirim == TRUE) {
        echo "Data berhasil diinputkan...!";
    }
    else {
        echo "Gagal di inputkan";
    }
?>  
