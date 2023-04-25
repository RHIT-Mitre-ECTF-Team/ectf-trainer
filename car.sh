#/bin/bash
cd car/ectf/car
make; make run&
sleep 1
#clear
echo
echo "You are now connected to the car!"
nc localhost 1236
kill $(jobs -p)
cd ~/ectf-trainer
