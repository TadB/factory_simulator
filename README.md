proj3

symulator fabryki mebli
Oprogramować graf modelujący abstrakcyjny system kolejkowy, w którym:
- węzeł grafu odpowiada stanowisku przetwarzania (np. wytwarzanie blatów),
- stanowisko produkuje obiekt danego typu (np. lakierowanie),
- ze stanowiskiem związanych jest kilka (rozróżnialnych) kolejek, z których pobiera ono
elementy, z których składa produkt swojego działania (np. stanowisko montujące stoły w ma dwie kolejki: nóg i bloków), skierowana krawędź grafu odpowiada możliwości przekazania przez stanowisko źródłowe efektu swojej pracy do stanowiska docelowego.
Posługując się powyższym modelem zaprogramować symulator działania fabryki mebli, w której są np. 4 stanowiska produkujące nogi do mebli, 2 stanowiska produkujące blaty, 2 stanowiska produkujące drzwiczki, 2 stanowiska montujące stoły, 2 stanowiska wytwarzające obudowy szafek, 2 stanowiska montujące szafki 2 stanowiska montujące drzwi i zawiasy do szafek. Liczba stanowisk może się różnić od przykładowej.
W symulacji przyjąć:
a) stanowisko zwraca efekt swojej pracy po jednostce czasu,
b) stanowisko przekazuje efekt swojej pracy temu następnemu stanowisku, przed którym jest najkrótsza kolejka
c) stanowisko wstrzymuje swoje działanie na jednostkę czasu, jeśli wszystkie kolejki w następnych stanowiskach są dłuższe niż 10.
Oprogramować wizualizację symulacji. Ustalić eksperymentalnie gdzie robią się najdłuższe kolejki.
