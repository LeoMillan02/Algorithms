def moda(arr, mitad):
    cont2 = 0
    reps = 0 
    cont1 = 0

    for i in arr:
        for j in arr:
            if arr[i] == arr[j] and i !=j:
                cont1+1
                reps+1
        

        if cont1 > cont2 and reps/2 > 1:
            cont2 = cont1
            moda = arr[i]

        cont1 = 0
    return moda

def MaxArray(arr):
    if len(arr) == 1:
        return arr[0]
    
    mitad = len(arr)//2
    arr_izq = arr[0:mitad]
    arr_der = arr[mitad:]

    max_izq = MaxArray(arr_izq)
    max_der = MaxArray(arr_der)
    max_mitad = moda(arr, mitad)

    return max(max_izq, max_der, max_mitad)


arreglo = [3,4,5,6,2,6,3,1]
print(arreglo[0:3])
print (MaxArray(arreglo))
