double calculatedPositon(double* points)
{
	double pointsInPx[2], // pointInPx[0] - x
											  // pointInPx[1] - y
				 W1px = 0.00034508963, // Мой выведенный coefficient для ширины
				 H1px = 0.00020789677, // Мой выведенный coefficient для высоты
				 minWidth = 12.94303529912, // Левый верхний угол - широта
				 minHeight = 52.64611109803,// Левый верхний угол - долгота
				 originalImageWidth = 3094, // Начальная ширина картинки
				 originalImageHeight = 1560,// Начальная высота картинки
				 ImageWidth = 1019,         // Ширина твоей картинки
				 ImageHeight = 700,         // Высота твоей картинки
				 coefficientX = ImageWidth / originalImageWidth,   // coefficient для твоей картинки (1019 / 3094 = 0.329)
				 coefficientY = ImageHeight / originalImageHeight; // coefficient для твоей картинки (700 / 1560 = 0.448)

	pointsInPx[0] = (points[0] - minWidth) / W1px; // X in Px for full image
	pointsInPx[1] = (points[1] - minWidth) / H1px; // Y in Px for full image

	pointsInPx[0] *= coefficientX; // Умножаем на масшабирование твоей картинки
	pointsInPx[1] *= coefficientY; // Умножаем на масшабирование твоей картинки

	return pointsInPx; // Возвращаем массив/обьект с полученными координатами ( я еще это число округляю перед тем как вернуть )
}


/* -------------------------
   --- My function in JS ---
   -------------------------

function calculatedPositon(element) {
	var W1px = 0.00034508963,
			H1px = 0.00020789677,
			minWidth = 12.94303529912,
			minHeight = 52.64611109803,
			positionX = element.point.x,
			positionY = element.point.y,
			spanX,
			spanY,
			pointInPx = {
				x: 0,
				y: 0
			};
	spanX = positionX - minWidth;
	spanY = minHeight - positionY;
	pointInPx.x = Math.round(spanX / W1px);
	pointInPx.y = Math.round(spanY / H1px);
	return pointInPx;
}*/