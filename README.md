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

Interfejs programu nie pozwala na samodzielne dodawanie nowych stanowisk. Stanowiska (zarówno wykonujące części, jak również składające produkt) są utworzone wewnątrz klasy modelującej graf. Użytkownik ma wpływ na ilość poszczególnych stanowisk oraz na czas wykonywania symulacji. Dostaje informację zwrotną w postaci ilości wyprodukowanych sztuk oraz wielkości kolejek, które utworzyły się podczas przebiegu symulacji. Interfejs przewiduje możliwość podejrzenia wyników symulacji na ekranie lub zapisanie wyświetlonych wyników do pliku.

Symulacja fabryki składa się z klasy "factory", wewnątrz której są tworzone obiekty klas "element" oraz "product". W klasie "factory" zostały zaimplementowane metody uruchomienia symulacji oraz wyświetlania danych. Graf jest modelowany na obiektach klasy list z biblioteki STL. Głównymi obiektami są listy elementów (czyli części, z których składa się produkty) oraz listy produktów. Każda lista może posiadać w sobie dowolną ilość obiektów (tzn. grupy tych samych obiektów, np. 4 stanowiska produkujące nogi do stołów — każde stanowisko jest jednym elementem listy nogi).
Obiekty klasy "product" posiadają rozróżnialne kolejki — zaimplementowanych jako lista zmiennych typu "int".
W obiektach klasy element są przechowywane adresy do kolejek, do których jest dostarczany produkowany przez te stanowisko półprodukt.

Z uwagi na sposób implementacji i budowy grafu — nie ma możliwości uruchomienia symulacji z daną wejściową równą zeru.
Dla danych wejściowych: 2 stanowiska montujące stoły oraz 2 stanowiska montujące szafki, 2 stanowiska wytwarzające nogi oraz 2 stanowiska wytwarzające blaty — reszta dowolna. Czas wykonania dla każdego stanowiska identyczny, czas symulacji 10s. Dostajemy nieoptymalny wynik symulacji. Stanowiska montujące stoły pochłonęły całą wydajność roboczą stanowisk wykonujących nogi do mebli. Wynika to ze sposobu sprawdzania wielkości kolejek, zawsze w tej samej kolejności, więc symulator nie rozkłada optymalnie produkowanych podzespołów do poszczególnych stanowisk, jeżeli regularnie będzie pobierana produkowana część z kolejki to zawsze będzie ona podawana z linii produkcyjnej do tej samej kolejki.
