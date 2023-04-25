#/bin/bash
cd fob/ectf/fob
make; make run&
sleep 1
echo
echo "You are now connected to the fob!"
nc localhost 1234
kill $(jobs -p)
cd ~/ectf-trainer
