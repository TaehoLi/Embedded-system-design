# 0. 사용할 패키지 불러오기
from keras.datasets import mnist
import serial
 
port = "COM3"
baud = 115200
 
ser = serial.Serial(port, baud, timeout=1)
    # open the serial port
if ser.isOpen():
     print(ser.name + ' is open...')
	 
# 1. 데이터셋 생성하기

# 훈련셋과 시험셋 불러오기
(x_train, y_train), (x_test, y_test) = mnist.load_data()

print(x_test.shape)

for k in list(range(0,16)):
   digit= x_test[20+k]
   import matplotlib.pyplot as plt
   plt.imshow(digit, cmap=plt.cm.binary)
   plt.show()
   #print( digit)

   for i in list(range(0,28)):
     for j in list(range(0,28)):
        digit_string="{:3d}".format(digit[i][j])
        ser.write(digit_string.encode('ascii'))
        #print(digit[i][j])

   out = ser.read(2)
   print('Recognized digit:',out.decode('utf-8'))

out = ser.read(2000)
print(out.decode('utf-8'))
 
ser.close()
#exit()


