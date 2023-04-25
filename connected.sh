#/bin/bash
cd ~/ectf-trainer/car/ectf/car
make
make connected&
cd ~/ectf-trainer/fob/ectf/fob
make
make connected&
sleep 1 
#clear
echo
echo "You are now connected to the fob!"
nc localhost 1234
kill $(jobs -p)
cd ~/ectf-trainer
