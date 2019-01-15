# Highway to hell

Qt homework game

<img src="http://i63.tinypic.com/2i8ah01.jpg"/> <img src="http://i65.tinypic.com/2s6kps2.jpg"/>

## Класс Game

Представляет сущность "Игра".
Имеет методы `start()`, `stop()` и флаг `over`.  
Инициализирует и хранит в себе ссылки на экземпляры классов "Игрок", "Сцена", "Дорога" и "Трафик".


## Класс Player

Представляет сущность "Игрок".
Имеет методы:
* `updateRate()` - изменение скорости
* `updatePosition()` - изменение положения
* `keyPressEvent()` - обработка нажатия кнопок
Есть поведение по таймеру.


## Класс Traffic

Представляет сущность "Трафик" - генерирует и управляет потоком машин.  
Имеет методы `start()`, `stop()`, `clear()`, `spawn()`.   
Есть поведение по таймеру.


## Класс Car

Представляет сущность "Машина".  
Имеет методы `move()`, `stop()`, `remove()` и поле `speed`.  
Есть поведение по таймеру.


## Класс Road

Представляет сущность "Дорога" - декоративная анимированная подложка.  
Имеет методы `start()`, `stop()`, `updatePosition()`.  
Есть поведение по таймеру.

