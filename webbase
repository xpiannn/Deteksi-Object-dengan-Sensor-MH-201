<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Monitoring Sensor IoT</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            text-align: center;
            background-color: #f4f4f4;
        }
        .status-container {
            background-color: white;
            border-radius: 10px;
            padding: 20px;
            box-shadow: 0 4px 6px rgba(0,0,0,0.1);
            margin-bottom: 20px;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
        }
        table, th, td {
            border: 1px solid #ddd;
        }
        th, td {
            padding: 12px;
            text-align: center;
        }
        th {
            background-color: #f4f4f4;
        }
        .love {
            width: 50px;
            height: 50px;
            display: inline-block;
            background-color: red;
            position: relative;
            transform: rotate(-45deg);
            margin-top: 10px;
        }
        .love::before, .love::after {
            content: "";
            width: 50px;
            height: 50px;
            background-color: red;
            border-radius: 50%;
            position: absolute;
        }
        .love::before {
            top: -25px;
            left: 0;
        }
        .love::after {
            left: 25px;
            top: 0;
        }
        .love-off {
            background-color: gray;
        }
        .love-off::before, .love-off::after {
            background-color: gray;
        }
    </style>
</head>
<body>
    <h1>Monitoring Sensor IoT</h1>

    <div class="status-container">
        <table>
            <tr>
                <th>ID</th>
                <th>Waktu</th>
                <th>Tanggal</th>
                <th>Status Sensor</th>
                <th>Indikator</th>
            </tr>
            <?php
                include("koneksiiot.php");

                $query = mysqli_query($koneksi, "SELECT * FROM datasensor ORDER BY id DESC LIMIT 5");
                while ($status = mysqli_fetch_array($query)) {
                    echo "<tr>";
                    echo "<td>" . $status['id'] . "</td>";
                    echo "<td>" . $status['waktu'] . "</td>";
                    echo "<td>" . $status['tanggal'] . "</td>";
                    echo "<td>" . $status['sensor_infrared'] . "</td>";
                    echo "<td>";
                    if ($status['sensor_infrared'] === 'Terdapat Objek') {
                        echo "<div class='love'></div>";
                    } else {
                        echo "<div class='love love-off'></div>";
                    }
                    echo "</td>";
                    echo "</tr>";
                }
            ?>
        </table>
    </div>
</body>
</html>
