import QtQuick 2.15
import QtCharts 2.0

ChartView {
    height: 800
    width: 480
    antialiasing: true

    title: "Temperature History"
    theme: ChartView.ChartThemeQt;

    LineSeries {
        id: temperatureSeries
        name: "Temperature"

        axisX: timeAxis
        axisY: temperatureAxis
    }

    ValuesAxis {
        id: timeAxis
    }

    ValuesAxis {
        id: temperatureAxis
        min: 15
        max: 25
    }

    Connections {
        target: temperatureData
        function onNewReading() {
            if (temperatureSeries.count > 120)
                    temperatureSeries.remove(0);
            temperatureSeries.append(temperatureData.lastReading.x, temperatureData.lastReading.y)

            // adjust time axis
            timeAxis.min = temperatureSeries.at(0).x
            timeAxis.max = temperatureSeries.at(temperatureSeries.count -1).x

            // adjust temperature axis
            if (temperatureData.lastReading.y < temperatureAxis.min)
                temperatureAxis.min = temperatureData.lastReading.y;
            if (temperatureData.lastReading.y > temperatureAxis.max)
                temperatureAxis.max = temperatureData.lastReading.y;
        }
    }
}
