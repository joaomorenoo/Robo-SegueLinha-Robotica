import time

segundos = -1
minutos = 0

inicio = 1

while inicio == 1:
    segundos = segundos + 1
    time.sleep(1)
    if segundos == 60:
        minutos = minutos + 1
        segundos = 0
    if segundos <= 9:
        print(f"{minutos}:0{segundos}")
    else:
        print(f"{minutos}:{segundos}")
    